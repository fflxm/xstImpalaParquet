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

#ifndef IMPALA_EXEC_PARQUET_METADATA_UTILS_H
#define IMPALA_EXEC_PARQUET_METADATA_UTILS_H

#include <string>

#include "runtime/descriptors.h"
#include "gen-cpp/parquet_types.h"

namespace impala {

class RuntimeState;
class TQueryOptions;

class ParquetMetadataUtils {
 public:
  /// Checks the version of the given file and returns a non-OK status if
  /// Impala does not support that version.
  static Status ValidateFileVersion(const parquet::FileMetaData& file_metadata,
      const char* filename);

  /// Validate column offsets by checking if the dictionary page comes before the data
  /// pages and checking if the column offsets lie within the file.
  static Status ValidateColumnOffsets(const std::string& filename, int64_t file_length,
      const parquet::RowGroup& row_group);

  /// Check that a file offset is in the file. Return an error status with a detailed
  /// error message if it is not.
  static Status ValidateOffsetInFile(const std::string& filename, int col_idx,
      int64_t file_length, int64_t offset, const std::string& offset_name);

  /// Validates the column metadata inside a row group to make sure this column is
  /// supported (e.g. encoding, type, etc).
  static Status ValidateRowGroupColumn(const parquet::FileMetaData& file_metadata,
      const char* filename, int row_group_idx, int col_idx,
      const parquet::SchemaElement& schema_element, RuntimeState* state);

  /// Validates the column metadata to make sure the column is supported and its type
  /// attributes conform to the parquet spec.
  static Status ValidateColumn(const char* filename,
      const parquet::SchemaElement& schema_element, const SlotDescriptor* slot_desc,
      RuntimeState* state);

  /// Returns the Parquet type corresponding to Impala's internal type. The caller must
  /// validate that the input type is valid, otherwise this will DCHECK.
  static parquet::Type::type ConvertInternalToParquetType(PrimitiveType type,
      const TParquetTimestampType::type timestamp_type);

  /// Sets type related fields in a SchemaElement based on the column's internal type
  /// and this function's arguments.
  static void FillSchemaElement(const ColumnType& col_type,
      bool string_utf8, TParquetTimestampType::type timestamp_type,
      parquet::SchemaElement* col_schema);
};

struct ParquetFileVersion {
  /// Application that wrote the file. e.g. "IMPALA"
  std::string application;

  /// Version of the application that wrote the file, expressed in three parts
  /// (<major>.<minor>.<patch>). Unspecified parts default to 0, and extra parts are
  /// ignored. e.g.:
  /// "1.2.3"    => {1, 2, 3}
  /// "1.2"      => {1, 2, 0}
  /// "1.2-cdh5" => {1, 2, 0}
  struct {
    int major;
    int minor;
    int patch;
  } version;

  /// If true, this file was generated by an Impala internal release
  bool is_impala_internal;

  ParquetFileVersion() : is_impala_internal(false) { }

  /// Parses the version from the created_by string
  ParquetFileVersion(const std::string& created_by);

  /// Returns true if version is strictly less than <major>.<minor>.<patch>
  bool VersionLt(int major, int minor = 0, int patch = 0) const;

  /// Returns true if version is equal to <major>.<minor>.<patch>
  bool VersionEq(int major, int minor, int patch) const;
};

/// Internal representation of a Parquet schema (including nested-type columns).
struct SchemaNode {
  /// The corresponding schema element defined in the file metadata
  const parquet::SchemaElement* element;

  /// The index into the RowGroup::columns list if this column is materialized in the
  /// file (i.e. it's a scalar type). -1 for nested types.
  int col_idx;

  /// The maximum definition level of this column, i.e., the definition level that
  /// corresponds to a non-NULL value. Valid values are >= 0.
  int max_def_level;

  /// The maximum repetition level of this column. Valid values are >= 0.
  int max_rep_level;

  /// The definition level of the most immediate ancestor of this node with repeated
  /// field repetition type. 0 if there are no repeated ancestors.
  int def_level_of_immediate_repeated_ancestor;

  /// Any nested schema nodes. Empty for non-nested types.
  std::vector<SchemaNode> children;

  SchemaNode() : element(NULL), col_idx(-1), max_def_level(-1), max_rep_level(-1),
                 def_level_of_immediate_repeated_ancestor(-1) { }

  std::string DebugString(int indent = 0) const;

  bool is_repeated() const {
    return element->repetition_type == parquet::FieldRepetitionType::REPEATED;
  }
};

/// Utility class to resolve SchemaPaths (e.g., from a table descriptor) against a
/// Parquet file schema. Supports resolution by field index or by field name.
/// Supports different policies for resolving nested arrays based on the modern
/// three-level encoding or the legacy encodings (one and two level).
class ParquetSchemaResolver {
 public:
  ParquetSchemaResolver(const HdfsTableDescriptor& tbl_desc,
      TSchemaResolutionStrategy::type fallback_schema_resolution,
      TParquetArrayResolution::type array_resolution)
    : tbl_desc_(tbl_desc),
      fallback_schema_resolution_(fallback_schema_resolution),
      array_resolution_(array_resolution),
      filename_(NULL) {}

  /// Parses the schema of the given file metadata into an internal schema
  /// representation used in path resolution. Remembers the filename for error
  /// reporting. Returns a non-OK status if the Parquet schema could not be parsed.
  Status Init(const parquet::FileMetaData* file_metadata, const char* filename) {
    DCHECK(filename != NULL);
    filename_ = filename;
    // Use FIELD_ID-based column resolution for Iceberg tables if possible.
    const auto& schema = file_metadata->schema;
    if (tbl_desc_.IsIcebergTable() && schema.size() > 1) {
      // schema[0] is the 'root', schema[1] is the first column.
      const parquet::SchemaElement& first_column = schema[1];
      if (first_column.__isset.field_id) {
        fallback_schema_resolution_ = TSchemaResolutionStrategy::type::FIELD_ID;
      }
    }
    return CreateSchemaTree(file_metadata->schema, &schema_);
  }

  /// Traverses 'schema_' according to 'path', returning the result in 'node'. If 'path'
  /// does not exist in this file's schema, 'missing_field' is set to true and
  /// Status::OK() is returned, otherwise 'missing_field' is set to false. If 'path'
  /// resolves to a collection position field, *pos_field is set to true. Otherwise
  /// 'pos_field' is set to false. Returns a non-OK status if 'path' cannot be resolved
  /// against the file's schema (e.g., unrecognized collection schema).
  ///
  /// Tries to resolve fields within lists according to the 'ordered_array_encodings_'.
  /// Returns a bad status if resolution fails for all attempted array encodings.
  Status ResolvePath(const SchemaPath& path, SchemaNode** node, bool* pos_field,
      bool* missing_field) const;

 private:
  /// The 'array_encoding' parameter determines whether to assume one-, two-, or
  /// three-level array encoding. The returned status is not logged (i.e. it's an expected
  /// error).
  enum ArrayEncoding {
    ONE_LEVEL,
    TWO_LEVEL,
    THREE_LEVEL,
    NUM_ARRAY_ENCODINGS
  };

  /// An arbitrary limit on the number of children per schema node we support.
  /// Used to sanity-check Parquet schemas.
  static const int SCHEMA_NODE_CHILDREN_SANITY_LIMIT = 64 * 1024;

  /// Maps from the array-resolution policy to the ordered array encodings that should
  /// be tried during path resolution. All entries have the ONE_LEVEL encoding at the end
  /// because there is no ambiguity between the one-level and the other encodings (there
  /// is no harm in trying it).
  static const std::vector<ArrayEncoding> ORDERED_ARRAY_ENCODINGS[];

  /// Unflattens the schema metadata from a Parquet file metadata and converts it to our
  /// SchemaNode representation. Returns the result in 'node' unless an error status is
  /// returned. Does not set the slot_desc field of any SchemaNode.
  Status CreateSchemaTree(const std::vector<parquet::SchemaElement>& schema,
      SchemaNode* node) const;

  /// Recursive implementation used internally by the above CreateSchemaTree() function.
  Status CreateSchemaTree(const std::vector<parquet::SchemaElement>& schema,
      int max_def_level, int max_rep_level, int ira_def_level, int* idx, int* col_idx,
      SchemaNode* node) const;

  Status ResolvePathHelper(ArrayEncoding array_encoding, const SchemaPath& path,
      SchemaNode** node, bool* pos_field, bool* missing_field) const;

  /// Helper functions for ResolvePathHelper().

  /// Advances 'node' to one of its children based on path[next_idx] and
  /// 'col_type'. 'col_type' is NULL if 'node' is the root node, otherwise it's the type
  /// associated with 'node'. Returns the child node or sets 'missing_field' to true.
  SchemaNode* NextSchemaNode(const ColumnType* col_type, const SchemaPath& path,
      int next_idx, SchemaNode* node, bool* missing_field) const;

  /// Returns the index of 'node's child with 'name', or the number of children if not
  /// found. The name comparison is case-insensitive because that's how Impala treats
  /// db/table/column/field names. If there are several matches with different casing,
  /// then the index of the first match is returned.
  int FindChildWithName(SchemaNode* node, const std::string& name) const;
  /// Returns the index of 'node's child with 'field id' for Iceberg tables.
  int FindChildWithFieldId(SchemaNode* node, const int& field_id) const;

  /// The ResolvePathHelper() logic for arrays.
  Status ResolveArray(ArrayEncoding array_encoding, const SchemaPath& path, int idx,
    SchemaNode** node, bool* pos_field, bool* missing_field) const;

  /// The ResolvePathHelper() logic for maps.
  Status ResolveMap(const SchemaPath& path, int idx, SchemaNode** node,
      bool* missing_field) const;

  /// The ResolvePathHelper() logic for scalars (just does validation since there's no
  /// more actual work to be done).
  Status ValidateScalarNode(const SchemaNode& node, const ColumnType& col_type,
      const SchemaPath& path, int idx) const;

  const HdfsTableDescriptor& tbl_desc_;
  TSchemaResolutionStrategy::type fallback_schema_resolution_;
  const TParquetArrayResolution::type array_resolution_;
  const char* filename_;

  /// Root node of our internal schema representation populated in Init().
  SchemaNode schema_;
};

} // impala namespace

#endif
