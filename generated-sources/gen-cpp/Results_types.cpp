/**
 * Autogenerated by Thrift Compiler (0.11.0)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#include "Results_types.h"

#include <algorithm>
#include <ostream>

#include <thrift/TToString.h>

namespace impala {


TRowBatch::~TRowBatch() throw() {
}


void TRowBatch::__set_num_rows(const int32_t val) {
  this->num_rows = val;
}

void TRowBatch::__set_row_tuples(const std::vector< ::impala::TTupleId> & val) {
  this->row_tuples = val;
}

void TRowBatch::__set_tuple_offsets(const std::vector<int32_t> & val) {
  this->tuple_offsets = val;
}

void TRowBatch::__set_tuple_data(const std::string& val) {
  this->tuple_data = val;
}

void TRowBatch::__set_compression_type(const  ::impala::THdfsCompression::type val) {
  this->compression_type = val;
}

void TRowBatch::__set_uncompressed_size(const int32_t val) {
  this->uncompressed_size = val;
}
std::ostream& operator<<(std::ostream& out, const TRowBatch& obj)
{
  obj.printTo(out);
  return out;
}


void swap(TRowBatch &a, TRowBatch &b) {
  using ::std::swap;
  swap(a.num_rows, b.num_rows);
  swap(a.row_tuples, b.row_tuples);
  swap(a.tuple_offsets, b.tuple_offsets);
  swap(a.tuple_data, b.tuple_data);
  swap(a.compression_type, b.compression_type);
  swap(a.uncompressed_size, b.uncompressed_size);
  swap(a.__isset, b.__isset);
}

TRowBatch::TRowBatch(const TRowBatch& other13) {
  num_rows = other13.num_rows;
  row_tuples = other13.row_tuples;
  tuple_offsets = other13.tuple_offsets;
  tuple_data = other13.tuple_data;
  compression_type = other13.compression_type;
  uncompressed_size = other13.uncompressed_size;
  __isset = other13.__isset;
}
TRowBatch::TRowBatch( TRowBatch&& other14) {
  num_rows = std::move(other14.num_rows);
  row_tuples = std::move(other14.row_tuples);
  tuple_offsets = std::move(other14.tuple_offsets);
  tuple_data = std::move(other14.tuple_data);
  compression_type = std::move(other14.compression_type);
  uncompressed_size = std::move(other14.uncompressed_size);
  __isset = std::move(other14.__isset);
}
TRowBatch& TRowBatch::operator=(const TRowBatch& other15) {
  num_rows = other15.num_rows;
  row_tuples = other15.row_tuples;
  tuple_offsets = other15.tuple_offsets;
  tuple_data = other15.tuple_data;
  compression_type = other15.compression_type;
  uncompressed_size = other15.uncompressed_size;
  __isset = other15.__isset;
  return *this;
}
TRowBatch& TRowBatch::operator=(TRowBatch&& other16) {
  num_rows = std::move(other16.num_rows);
  row_tuples = std::move(other16.row_tuples);
  tuple_offsets = std::move(other16.tuple_offsets);
  tuple_data = std::move(other16.tuple_data);
  compression_type = std::move(other16.compression_type);
  uncompressed_size = std::move(other16.uncompressed_size);
  __isset = std::move(other16.__isset);
  return *this;
}
void TRowBatch::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "TRowBatch(";
  out << "num_rows=" << to_string(num_rows);
  out << ", " << "row_tuples=" << to_string(row_tuples);
  out << ", " << "tuple_offsets=" << to_string(tuple_offsets);
  out << ", " << "tuple_data=" << to_string(tuple_data);
  out << ", " << "compression_type=" << to_string(compression_type);
  out << ", " << "uncompressed_size=" << to_string(uncompressed_size);
  out << ")";
}


TResultSetMetadata::~TResultSetMetadata() throw() {
}


void TResultSetMetadata::__set_columns(const std::vector< ::impala::TColumn> & val) {
  this->columns = val;
}
std::ostream& operator<<(std::ostream& out, const TResultSetMetadata& obj)
{
  obj.printTo(out);
  return out;
}


void swap(TResultSetMetadata &a, TResultSetMetadata &b) {
  using ::std::swap;
  swap(a.columns, b.columns);
}

TResultSetMetadata::TResultSetMetadata(const TResultSetMetadata& other23) {
  columns = other23.columns;
}
TResultSetMetadata::TResultSetMetadata( TResultSetMetadata&& other24) {
  columns = std::move(other24.columns);
}
TResultSetMetadata& TResultSetMetadata::operator=(const TResultSetMetadata& other25) {
  columns = other25.columns;
  return *this;
}
TResultSetMetadata& TResultSetMetadata::operator=(TResultSetMetadata&& other26) {
  columns = std::move(other26.columns);
  return *this;
}
void TResultSetMetadata::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "TResultSetMetadata(";
  out << "columns=" << to_string(columns);
  out << ")";
}


TResultSet::~TResultSet() throw() {
}


void TResultSet::__set_rows(const std::vector< ::impala::TResultRow> & val) {
  this->rows = val;
}

void TResultSet::__set_schema(const TResultSetMetadata& val) {
  this->schema = val;
}
std::ostream& operator<<(std::ostream& out, const TResultSet& obj)
{
  obj.printTo(out);
  return out;
}


void swap(TResultSet &a, TResultSet &b) {
  using ::std::swap;
  swap(a.rows, b.rows);
  swap(a.schema, b.schema);
}

TResultSet::TResultSet(const TResultSet& other33) {
  rows = other33.rows;
  schema = other33.schema;
}
TResultSet::TResultSet( TResultSet&& other34) {
  rows = std::move(other34.rows);
  schema = std::move(other34.schema);
}
TResultSet& TResultSet::operator=(const TResultSet& other35) {
  rows = other35.rows;
  schema = other35.schema;
  return *this;
}
TResultSet& TResultSet::operator=(TResultSet&& other36) {
  rows = std::move(other36.rows);
  schema = std::move(other36.schema);
  return *this;
}
void TResultSet::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "TResultSet(";
  out << "rows=" << to_string(rows);
  out << ", " << "schema=" << to_string(schema);
  out << ")";
}

} // namespace
