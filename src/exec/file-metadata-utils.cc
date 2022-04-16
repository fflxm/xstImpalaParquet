// Licensed to the Apache Software Foundation (ASF) under one
// or more contributor license agreements.  See the NOTICE file
// distributed with this work for additional information
// regarding copyright ownership.  The ASF licenses this file
// to you under the Apache License, Version 2.0 (the
// "License"); you may not use this file except in compliance
// with the License.  You may obtain a copy of the License at
//
//   http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing,
// software distributed under the License is distributed on an
// "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
// KIND, either express or implied.  See the License for the
// specific language governing permissions and limitations
// under the License.

#include "exec/file-metadata-utils.h"

#include "exec/hdfs-scan-node-base.h"
#include "exec/scanner-context.h"
#include "exec/text-converter.inline.h"
#include "runtime/descriptors.h"
#include "runtime/tuple.h"
#include "util/flat_buffer.h"
#include "util/string-parser.h"

#include "common/names.h"

namespace impala {

void FileMetadataUtils::Open(ScannerContext* context) {
  DCHECK(context != nullptr);
  context_ = context;
  file_desc_ = scan_node_->GetFileDesc(context->partition_descriptor()->id(),
                                       context->GetStream()->filename());
}

Tuple* FileMetadataUtils::CreateTemplateTuple(MemPool* mem_pool) {
  DCHECK(context_ != nullptr);
  DCHECK(file_desc_ != nullptr);
  // Initialize the template tuple, it is copied from the template tuple map in the
  // HdfsScanNodeBase.
  Tuple* template_tuple =
      scan_node_->GetTemplateTupleForPartitionId(context_->partition_descriptor()->id());
  if (template_tuple != nullptr) {
    template_tuple =
        template_tuple->DeepCopy(*scan_node_->tuple_desc(), mem_pool);
  }
  if (!scan_node_->hdfs_table()->IsIcebergTable()) {
    return template_tuple;
  }
  using namespace org::apache::impala::fb;
  TextConverter text_converter(/* escape_char = */ '\\',
      scan_node_->hdfs_table()->null_column_value(),
      /* check_null = */ true, /* strict_mode = */ true);
  const FbFileMetadata* file_metadata = file_desc_->file_metadata;
  const FbIcebergMetadata* ice_metadata = file_metadata->iceberg_metadata();
  auto transforms = ice_metadata->partition_keys();
  if (transforms == nullptr) return template_tuple;

  const TupleDescriptor* tuple_desc = scan_node_->tuple_desc();
  if (template_tuple == nullptr) {
    template_tuple = Tuple::Create(tuple_desc->byte_size(), mem_pool);
  }
  for (const SlotDescriptor* slot_desc : scan_node_->tuple_desc()->slots()) {
    const SchemaPath& path = slot_desc->col_path();
    if (path.size() != 1) continue;
    const ColumnDescriptor& col_desc =
        scan_node_->hdfs_table()->col_descs()[path.front()];
    int field_id = col_desc.field_id();
    for (int i = 0; i < transforms->Length(); ++i) {
      auto transform = transforms->Get(i);
      if (transform->transform_type() !=
          FbIcebergTransformType::FbIcebergTransformType_IDENTITY) {
        continue;
      }
      if (field_id != transform->source_id()) continue;
      if (!text_converter.WriteSlot(slot_desc, template_tuple,
                                    transform->transform_value()->c_str(),
                                    transform->transform_value()->size(),
                                    true, false,
                                    mem_pool)) {
        ErrorMsg error_msg(TErrorCode::GENERAL,
            Substitute("Could not parse partition value for "
                "column '$0' in file '$1'. Partition string is '$2'",
                col_desc.name(), file_desc_->filename,
                transform->transform_value()->c_str()));
        // Dates are stored as INTs in the partition data in Iceberg, so let's try
        // to parse them as INTs.
        if (col_desc.type().type == PrimitiveType::TYPE_DATE) {
          int32_t* slot = template_tuple->GetIntSlot(slot_desc->tuple_offset());
          StringParser::ParseResult parse_result;
          *slot = StringParser::StringToInt<int32_t>(
              transform->transform_value()->c_str(),
              transform->transform_value()->size(),
              &parse_result);
          if (parse_result == StringParser::ParseResult::PARSE_SUCCESS) {
            template_tuple->SetNotNull(slot_desc->null_indicator_offset());
          } else {
            state_->LogError(error_msg);
          }
        } else {
          state_->LogError(error_msg);
        }
      }
    }
  }
  return template_tuple;
}

bool FileMetadataUtils::IsValuePartitionCol(const SlotDescriptor* slot_desc) {
  DCHECK(context_ != nullptr);
  DCHECK(file_desc_ != nullptr);
  if (slot_desc->parent() != scan_node_->tuple_desc()) return false;
  if (slot_desc->col_pos() < scan_node_->num_partition_keys()) {
    return true;
  }

  if (!scan_node_->hdfs_table()->IsIcebergTable()) return false;

  using namespace org::apache::impala::fb;

  const SchemaPath& path = slot_desc->col_path();
  if (path.size() != 1) return false;

  int field_id = scan_node_->hdfs_table()->col_descs()[path.front()].field_id();
  const FbFileMetadata* file_metadata = file_desc_->file_metadata;
  const FbIcebergMetadata* ice_metadata = file_metadata->iceberg_metadata();
  auto transforms = ice_metadata->partition_keys();
  if (transforms == nullptr) return false;
  for (int i = 0; i < transforms->Length(); ++i) {
    auto transform = transforms->Get(i);
    if (transform->source_id() == field_id &&
        transform->transform_type() ==
            FbIcebergTransformType::FbIcebergTransformType_IDENTITY) {
      return true;
    }
  }
  return false;
}

} // namespace impala
