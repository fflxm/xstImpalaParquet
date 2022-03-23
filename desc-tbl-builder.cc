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

#include "testutil/desc-tbl-builder.h"
#include "util/bit-util.h"

#include "common/object-pool.h"
#include "service/frontend.h"
#include "runtime/descriptors.h"

#include "common/names.h"

namespace impala {

DescriptorTblBuilder::DescriptorTblBuilder(Frontend* fe, ObjectPool* obj_pool)
  : fe_(fe), obj_pool_(obj_pool) {
  DCHECK(fe != NULL);
  DCHECK(obj_pool_ != NULL);
}
//modify by ff
DescriptorTblBuilder::DescriptorTblBuilder(ObjectPool* obj_pool)
  : fe_(nullptr), obj_pool_(obj_pool) {
  DCHECK(obj_pool_ != NULL);
}
TupleDescBuilder& DescriptorTblBuilder::DeclareTuple() {
  TupleDescBuilder* tuple_builder = obj_pool_->Add(new TupleDescBuilder());
  tuples_descs_.push_back(tuple_builder);
  return *tuple_builder;
}

void DescriptorTblBuilder::SetTableDescriptor(const TTableDescriptor& table_desc) {
  DCHECK(thrift_desc_tbl_.tableDescriptors.empty())
      << "Only one TableDescriptor can be set.";
  thrift_desc_tbl_.tableDescriptors.push_back(table_desc);
}

DescriptorTbl* DescriptorTblBuilder::Build() {
  DCHECK(!tuples_descs_.empty());

  TBuildTestDescriptorTableParams params;
  for (int i = 0; i < tuples_descs_.size(); ++i) {
    params.slot_types.push_back(vector<TColumnType>());
    vector<TColumnType>& tslot_types = params.slot_types.back();
    const vector<ColumnType>& slot_types = tuples_descs_[i]->slot_types();
    for (const ColumnType& slot_type : slot_types) {
      tslot_types.push_back(slot_type.ToThrift());
    }
  }

  Status buildDescTblStatus = fe_->BuildTestDescriptorTable(params, &thrift_desc_tbl_);
  DCHECK(buildDescTblStatus.ok()) << buildDescTblStatus.GetDetail();

  DescriptorTbl* desc_tbl;
  Status status = DescriptorTbl::CreateInternal(obj_pool_, thrift_desc_tbl_, &desc_tbl);
  DCHECK(status.ok()) << status.GetDetail();
  return desc_tbl;
}
//modify by ff
DescriptorTbl* DescriptorTblBuilder::BuildLocal() {
  DCHECK(!tuples_descs_.empty());

  vector<TTupleDescriptor>  vtuple;
  vector<TSlotDescriptor>  slot;
  vector<TColumnDescriptor> vtcc;
  TColumnDescriptor tcc;

//  TBuildTestDescriptorTableParams params;
  for (int i = 0; i < tuples_descs_.size(); ++i) {
//    params.slot_types.push_back(vector<TColumnType>());
//    vector<TColumnType>& tslot_types = params.slot_types.back();
    const vector<ColumnType>& slot_types = tuples_descs_[i]->slot_types();
    for (const ColumnType& slot_type : slot_types) {
      //tslot_types.push_back(slot_type.ToThrift());
      //create slot
      TSlotDescriptor tslot;
      tslot.__set_id((TSlotId) i);
      tslot.__set_parent((TTupleId) 0);
//      tslot.__set_itemTupleId((TTupleId) 110501);
      tslot.__set_slotType(slot_type.ToThrift());
      tslot.__set_materializedPath(vector<int32_t>(1,i));
      slot.push_back(tslot);

      memset(&tcc, 0x0, sizeof(TColumnDescriptor));
      tcc.__set_type(slot_type.ToThrift());
      vtcc.push_back(tcc);
    }
    //create tuples
    TTupleDescriptor ttuple;
    ttuple.__set_id((TTupleId) 0);
    ttuple.__set_byteSize(1105);
    ttuple.__set_numNullBytes(0);
    ttuple.__set_tableId((TTableId) 0);
    ttuple.__set_tuplePath(vector<int32_t>(1,0));
    vtuple.push_back(ttuple);
  }
  thrift_desc_tbl_.__set_slotDescriptors(slot);
  thrift_desc_tbl_.__set_tupleDescriptors(vtuple);
  for(int j=0; j<thrift_desc_tbl_.tableDescriptors.size(); j++){
    thrift_desc_tbl_.tableDescriptors[j].__set_columnDescriptors(vtcc);
  }

  DescriptorTbl* desc_tbl;
  Status status = DescriptorTbl::CreateInternal(obj_pool_, thrift_desc_tbl_, &desc_tbl);
  DCHECK(status.ok()) << status.GetDetail();
  return desc_tbl;
}
}
