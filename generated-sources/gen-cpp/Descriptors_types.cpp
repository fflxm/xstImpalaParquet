/**
 * Autogenerated by Thrift Compiler (0.11.0)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#include "Descriptors_types.h"

#include <algorithm>
#include <ostream>

#include <thrift/TToString.h>

namespace impala {


TSlotDescriptor::~TSlotDescriptor() throw() {
}


void TSlotDescriptor::__set_id(const  ::impala::TSlotId val) {
  this->id = val;
}

void TSlotDescriptor::__set_parent(const  ::impala::TTupleId val) {
  this->parent = val;
}

void TSlotDescriptor::__set_itemTupleId(const  ::impala::TTupleId val) {
  this->itemTupleId = val;
__isset.itemTupleId = true;
}

void TSlotDescriptor::__set_slotType(const  ::impala::TColumnType& val) {
  this->slotType = val;
}

void TSlotDescriptor::__set_materializedPath(const std::vector<int32_t> & val) {
  this->materializedPath = val;
}

void TSlotDescriptor::__set_byteOffset(const int32_t val) {
  this->byteOffset = val;
}

void TSlotDescriptor::__set_nullIndicatorByte(const int32_t val) {
  this->nullIndicatorByte = val;
}

void TSlotDescriptor::__set_nullIndicatorBit(const int32_t val) {
  this->nullIndicatorBit = val;
}

void TSlotDescriptor::__set_slotIdx(const int32_t val) {
  this->slotIdx = val;
}
std::ostream& operator<<(std::ostream& out, const TSlotDescriptor& obj)
{
  obj.printTo(out);
  return out;
}


void swap(TSlotDescriptor &a, TSlotDescriptor &b) {
  using ::std::swap;
  swap(a.id, b.id);
  swap(a.parent, b.parent);
  swap(a.itemTupleId, b.itemTupleId);
  swap(a.slotType, b.slotType);
  swap(a.materializedPath, b.materializedPath);
  swap(a.byteOffset, b.byteOffset);
  swap(a.nullIndicatorByte, b.nullIndicatorByte);
  swap(a.nullIndicatorBit, b.nullIndicatorBit);
  swap(a.slotIdx, b.slotIdx);
  swap(a.__isset, b.__isset);
}

TSlotDescriptor::TSlotDescriptor(const TSlotDescriptor& other6) {
  id = other6.id;
  parent = other6.parent;
  itemTupleId = other6.itemTupleId;
  slotType = other6.slotType;
  materializedPath = other6.materializedPath;
  byteOffset = other6.byteOffset;
  nullIndicatorByte = other6.nullIndicatorByte;
  nullIndicatorBit = other6.nullIndicatorBit;
  slotIdx = other6.slotIdx;
  __isset = other6.__isset;
}
TSlotDescriptor::TSlotDescriptor( TSlotDescriptor&& other7) {
  id = std::move(other7.id);
  parent = std::move(other7.parent);
  itemTupleId = std::move(other7.itemTupleId);
  slotType = std::move(other7.slotType);
  materializedPath = std::move(other7.materializedPath);
  byteOffset = std::move(other7.byteOffset);
  nullIndicatorByte = std::move(other7.nullIndicatorByte);
  nullIndicatorBit = std::move(other7.nullIndicatorBit);
  slotIdx = std::move(other7.slotIdx);
  __isset = std::move(other7.__isset);
}
TSlotDescriptor& TSlotDescriptor::operator=(const TSlotDescriptor& other8) {
  id = other8.id;
  parent = other8.parent;
  itemTupleId = other8.itemTupleId;
  slotType = other8.slotType;
  materializedPath = other8.materializedPath;
  byteOffset = other8.byteOffset;
  nullIndicatorByte = other8.nullIndicatorByte;
  nullIndicatorBit = other8.nullIndicatorBit;
  slotIdx = other8.slotIdx;
  __isset = other8.__isset;
  return *this;
}
TSlotDescriptor& TSlotDescriptor::operator=(TSlotDescriptor&& other9) {
  id = std::move(other9.id);
  parent = std::move(other9.parent);
  itemTupleId = std::move(other9.itemTupleId);
  slotType = std::move(other9.slotType);
  materializedPath = std::move(other9.materializedPath);
  byteOffset = std::move(other9.byteOffset);
  nullIndicatorByte = std::move(other9.nullIndicatorByte);
  nullIndicatorBit = std::move(other9.nullIndicatorBit);
  slotIdx = std::move(other9.slotIdx);
  __isset = std::move(other9.__isset);
  return *this;
}
void TSlotDescriptor::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "TSlotDescriptor(";
  out << "id=" << to_string(id);
  out << ", " << "parent=" << to_string(parent);
  out << ", " << "itemTupleId="; (__isset.itemTupleId ? (out << to_string(itemTupleId)) : (out << "<null>"));
  out << ", " << "slotType=" << to_string(slotType);
  out << ", " << "materializedPath=" << to_string(materializedPath);
  out << ", " << "byteOffset=" << to_string(byteOffset);
  out << ", " << "nullIndicatorByte=" << to_string(nullIndicatorByte);
  out << ", " << "nullIndicatorBit=" << to_string(nullIndicatorBit);
  out << ", " << "slotIdx=" << to_string(slotIdx);
  out << ")";
}


TColumnDescriptor::~TColumnDescriptor() throw() {
}


void TColumnDescriptor::__set_name(const std::string& val) {
  this->name = val;
}

void TColumnDescriptor::__set_type(const  ::impala::TColumnType& val) {
  this->type = val;
}

void TColumnDescriptor::__set_icebergFieldId(const int32_t val) {
  this->icebergFieldId = val;
__isset.icebergFieldId = true;
}

void TColumnDescriptor::__set_icebergFieldMapKeyId(const int32_t val) {
  this->icebergFieldMapKeyId = val;
__isset.icebergFieldMapKeyId = true;
}

void TColumnDescriptor::__set_icebergFieldMapValueId(const int32_t val) {
  this->icebergFieldMapValueId = val;
__isset.icebergFieldMapValueId = true;
}
std::ostream& operator<<(std::ostream& out, const TColumnDescriptor& obj)
{
  obj.printTo(out);
  return out;
}


void swap(TColumnDescriptor &a, TColumnDescriptor &b) {
  using ::std::swap;
  swap(a.name, b.name);
  swap(a.type, b.type);
  swap(a.icebergFieldId, b.icebergFieldId);
  swap(a.icebergFieldMapKeyId, b.icebergFieldMapKeyId);
  swap(a.icebergFieldMapValueId, b.icebergFieldMapValueId);
  swap(a.__isset, b.__isset);
}

TColumnDescriptor::TColumnDescriptor(const TColumnDescriptor& other10) {
  name = other10.name;
  type = other10.type;
  icebergFieldId = other10.icebergFieldId;
  icebergFieldMapKeyId = other10.icebergFieldMapKeyId;
  icebergFieldMapValueId = other10.icebergFieldMapValueId;
  __isset = other10.__isset;
}
TColumnDescriptor::TColumnDescriptor( TColumnDescriptor&& other11) {
  name = std::move(other11.name);
  type = std::move(other11.type);
  icebergFieldId = std::move(other11.icebergFieldId);
  icebergFieldMapKeyId = std::move(other11.icebergFieldMapKeyId);
  icebergFieldMapValueId = std::move(other11.icebergFieldMapValueId);
  __isset = std::move(other11.__isset);
}
TColumnDescriptor& TColumnDescriptor::operator=(const TColumnDescriptor& other12) {
  name = other12.name;
  type = other12.type;
  icebergFieldId = other12.icebergFieldId;
  icebergFieldMapKeyId = other12.icebergFieldMapKeyId;
  icebergFieldMapValueId = other12.icebergFieldMapValueId;
  __isset = other12.__isset;
  return *this;
}
TColumnDescriptor& TColumnDescriptor::operator=(TColumnDescriptor&& other13) {
  name = std::move(other13.name);
  type = std::move(other13.type);
  icebergFieldId = std::move(other13.icebergFieldId);
  icebergFieldMapKeyId = std::move(other13.icebergFieldMapKeyId);
  icebergFieldMapValueId = std::move(other13.icebergFieldMapValueId);
  __isset = std::move(other13.__isset);
  return *this;
}
void TColumnDescriptor::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "TColumnDescriptor(";
  out << "name=" << to_string(name);
  out << ", " << "type=" << to_string(type);
  out << ", " << "icebergFieldId="; (__isset.icebergFieldId ? (out << to_string(icebergFieldId)) : (out << "<null>"));
  out << ", " << "icebergFieldMapKeyId="; (__isset.icebergFieldMapKeyId ? (out << to_string(icebergFieldMapKeyId)) : (out << "<null>"));
  out << ", " << "icebergFieldMapValueId="; (__isset.icebergFieldMapValueId ? (out << to_string(icebergFieldMapValueId)) : (out << "<null>"));
  out << ")";
}


TTableDescriptor::~TTableDescriptor() throw() {
}


void TTableDescriptor::__set_id(const  ::impala::TTableId val) {
  this->id = val;
}

void TTableDescriptor::__set_tableType(const  ::impala::TTableType::type val) {
  this->tableType = val;
}

void TTableDescriptor::__set_columnDescriptors(const std::vector<TColumnDescriptor> & val) {
  this->columnDescriptors = val;
}

void TTableDescriptor::__set_numClusteringCols(const int32_t val) {
  this->numClusteringCols = val;
}

void TTableDescriptor::__set_hdfsTable(const  ::impala::THdfsTable& val) {
  this->hdfsTable = val;
__isset.hdfsTable = true;
}

void TTableDescriptor::__set_hbaseTable(const  ::impala::THBaseTable& val) {
  this->hbaseTable = val;
__isset.hbaseTable = true;
}

void TTableDescriptor::__set_dataSourceTable(const  ::impala::TDataSourceTable& val) {
  this->dataSourceTable = val;
__isset.dataSourceTable = true;
}

void TTableDescriptor::__set_kuduTable(const  ::impala::TKuduTable& val) {
  this->kuduTable = val;
__isset.kuduTable = true;
}

void TTableDescriptor::__set_icebergTable(const  ::impala::TIcebergTable& val) {
  this->icebergTable = val;
__isset.icebergTable = true;
}

void TTableDescriptor::__set_tableName(const std::string& val) {
  this->tableName = val;
}

void TTableDescriptor::__set_dbName(const std::string& val) {
  this->dbName = val;
}
std::ostream& operator<<(std::ostream& out, const TTableDescriptor& obj)
{
  obj.printTo(out);
  return out;
}


void swap(TTableDescriptor &a, TTableDescriptor &b) {
  using ::std::swap;
  swap(a.id, b.id);
  swap(a.tableType, b.tableType);
  swap(a.columnDescriptors, b.columnDescriptors);
  swap(a.numClusteringCols, b.numClusteringCols);
  swap(a.hdfsTable, b.hdfsTable);
  swap(a.hbaseTable, b.hbaseTable);
  swap(a.dataSourceTable, b.dataSourceTable);
  swap(a.kuduTable, b.kuduTable);
  swap(a.icebergTable, b.icebergTable);
  swap(a.tableName, b.tableName);
  swap(a.dbName, b.dbName);
  swap(a.__isset, b.__isset);
}

TTableDescriptor::TTableDescriptor(const TTableDescriptor& other21) {
  id = other21.id;
  tableType = other21.tableType;
  columnDescriptors = other21.columnDescriptors;
  numClusteringCols = other21.numClusteringCols;
  hdfsTable = other21.hdfsTable;
  hbaseTable = other21.hbaseTable;
  dataSourceTable = other21.dataSourceTable;
  kuduTable = other21.kuduTable;
  icebergTable = other21.icebergTable;
  tableName = other21.tableName;
  dbName = other21.dbName;
  __isset = other21.__isset;
}
TTableDescriptor::TTableDescriptor( TTableDescriptor&& other22) {
  id = std::move(other22.id);
  tableType = std::move(other22.tableType);
  columnDescriptors = std::move(other22.columnDescriptors);
  numClusteringCols = std::move(other22.numClusteringCols);
  hdfsTable = std::move(other22.hdfsTable);
  hbaseTable = std::move(other22.hbaseTable);
  dataSourceTable = std::move(other22.dataSourceTable);
  kuduTable = std::move(other22.kuduTable);
  icebergTable = std::move(other22.icebergTable);
  tableName = std::move(other22.tableName);
  dbName = std::move(other22.dbName);
  __isset = std::move(other22.__isset);
}
TTableDescriptor& TTableDescriptor::operator=(const TTableDescriptor& other23) {
  id = other23.id;
  tableType = other23.tableType;
  columnDescriptors = other23.columnDescriptors;
  numClusteringCols = other23.numClusteringCols;
  hdfsTable = other23.hdfsTable;
  hbaseTable = other23.hbaseTable;
  dataSourceTable = other23.dataSourceTable;
  kuduTable = other23.kuduTable;
  icebergTable = other23.icebergTable;
  tableName = other23.tableName;
  dbName = other23.dbName;
  __isset = other23.__isset;
  return *this;
}
TTableDescriptor& TTableDescriptor::operator=(TTableDescriptor&& other24) {
  id = std::move(other24.id);
  tableType = std::move(other24.tableType);
  columnDescriptors = std::move(other24.columnDescriptors);
  numClusteringCols = std::move(other24.numClusteringCols);
  hdfsTable = std::move(other24.hdfsTable);
  hbaseTable = std::move(other24.hbaseTable);
  dataSourceTable = std::move(other24.dataSourceTable);
  kuduTable = std::move(other24.kuduTable);
  icebergTable = std::move(other24.icebergTable);
  tableName = std::move(other24.tableName);
  dbName = std::move(other24.dbName);
  __isset = std::move(other24.__isset);
  return *this;
}
void TTableDescriptor::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "TTableDescriptor(";
  out << "id=" << to_string(id);
  out << ", " << "tableType=" << to_string(tableType);
  out << ", " << "columnDescriptors=" << to_string(columnDescriptors);
  out << ", " << "numClusteringCols=" << to_string(numClusteringCols);
  out << ", " << "hdfsTable="; (__isset.hdfsTable ? (out << to_string(hdfsTable)) : (out << "<null>"));
  out << ", " << "hbaseTable="; (__isset.hbaseTable ? (out << to_string(hbaseTable)) : (out << "<null>"));
  out << ", " << "dataSourceTable="; (__isset.dataSourceTable ? (out << to_string(dataSourceTable)) : (out << "<null>"));
  out << ", " << "kuduTable="; (__isset.kuduTable ? (out << to_string(kuduTable)) : (out << "<null>"));
  out << ", " << "icebergTable="; (__isset.icebergTable ? (out << to_string(icebergTable)) : (out << "<null>"));
  out << ", " << "tableName=" << to_string(tableName);
  out << ", " << "dbName=" << to_string(dbName);
  out << ")";
}


TTupleDescriptor::~TTupleDescriptor() throw() {
}


void TTupleDescriptor::__set_id(const  ::impala::TTupleId val) {
  this->id = val;
}

void TTupleDescriptor::__set_byteSize(const int32_t val) {
  this->byteSize = val;
}

void TTupleDescriptor::__set_numNullBytes(const int32_t val) {
  this->numNullBytes = val;
}

void TTupleDescriptor::__set_tableId(const  ::impala::TTableId val) {
  this->tableId = val;
__isset.tableId = true;
}

void TTupleDescriptor::__set_tuplePath(const std::vector<int32_t> & val) {
  this->tuplePath = val;
__isset.tuplePath = true;
}
std::ostream& operator<<(std::ostream& out, const TTupleDescriptor& obj)
{
  obj.printTo(out);
  return out;
}


void swap(TTupleDescriptor &a, TTupleDescriptor &b) {
  using ::std::swap;
  swap(a.id, b.id);
  swap(a.byteSize, b.byteSize);
  swap(a.numNullBytes, b.numNullBytes);
  swap(a.tableId, b.tableId);
  swap(a.tuplePath, b.tuplePath);
  swap(a.__isset, b.__isset);
}

TTupleDescriptor::TTupleDescriptor(const TTupleDescriptor& other31) {
  id = other31.id;
  byteSize = other31.byteSize;
  numNullBytes = other31.numNullBytes;
  tableId = other31.tableId;
  tuplePath = other31.tuplePath;
  __isset = other31.__isset;
}
TTupleDescriptor::TTupleDescriptor( TTupleDescriptor&& other32) {
  id = std::move(other32.id);
  byteSize = std::move(other32.byteSize);
  numNullBytes = std::move(other32.numNullBytes);
  tableId = std::move(other32.tableId);
  tuplePath = std::move(other32.tuplePath);
  __isset = std::move(other32.__isset);
}
TTupleDescriptor& TTupleDescriptor::operator=(const TTupleDescriptor& other33) {
  id = other33.id;
  byteSize = other33.byteSize;
  numNullBytes = other33.numNullBytes;
  tableId = other33.tableId;
  tuplePath = other33.tuplePath;
  __isset = other33.__isset;
  return *this;
}
TTupleDescriptor& TTupleDescriptor::operator=(TTupleDescriptor&& other34) {
  id = std::move(other34.id);
  byteSize = std::move(other34.byteSize);
  numNullBytes = std::move(other34.numNullBytes);
  tableId = std::move(other34.tableId);
  tuplePath = std::move(other34.tuplePath);
  __isset = std::move(other34.__isset);
  return *this;
}
void TTupleDescriptor::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "TTupleDescriptor(";
  out << "id=" << to_string(id);
  out << ", " << "byteSize=" << to_string(byteSize);
  out << ", " << "numNullBytes=" << to_string(numNullBytes);
  out << ", " << "tableId="; (__isset.tableId ? (out << to_string(tableId)) : (out << "<null>"));
  out << ", " << "tuplePath="; (__isset.tuplePath ? (out << to_string(tuplePath)) : (out << "<null>"));
  out << ")";
}


TDescriptorTable::~TDescriptorTable() throw() {
}


void TDescriptorTable::__set_slotDescriptors(const std::vector<TSlotDescriptor> & val) {
  this->slotDescriptors = val;
__isset.slotDescriptors = true;
}

void TDescriptorTable::__set_tupleDescriptors(const std::vector<TTupleDescriptor> & val) {
  this->tupleDescriptors = val;
}

void TDescriptorTable::__set_tableDescriptors(const std::vector<TTableDescriptor> & val) {
  this->tableDescriptors = val;
__isset.tableDescriptors = true;
}
std::ostream& operator<<(std::ostream& out, const TDescriptorTable& obj)
{
  obj.printTo(out);
  return out;
}


void swap(TDescriptorTable &a, TDescriptorTable &b) {
  using ::std::swap;
  swap(a.slotDescriptors, b.slotDescriptors);
  swap(a.tupleDescriptors, b.tupleDescriptors);
  swap(a.tableDescriptors, b.tableDescriptors);
  swap(a.__isset, b.__isset);
}

TDescriptorTable::TDescriptorTable(const TDescriptorTable& other53) {
  slotDescriptors = other53.slotDescriptors;
  tupleDescriptors = other53.tupleDescriptors;
  tableDescriptors = other53.tableDescriptors;
  __isset = other53.__isset;
}
TDescriptorTable::TDescriptorTable( TDescriptorTable&& other54) {
  slotDescriptors = std::move(other54.slotDescriptors);
  tupleDescriptors = std::move(other54.tupleDescriptors);
  tableDescriptors = std::move(other54.tableDescriptors);
  __isset = std::move(other54.__isset);
}
TDescriptorTable& TDescriptorTable::operator=(const TDescriptorTable& other55) {
  slotDescriptors = other55.slotDescriptors;
  tupleDescriptors = other55.tupleDescriptors;
  tableDescriptors = other55.tableDescriptors;
  __isset = other55.__isset;
  return *this;
}
TDescriptorTable& TDescriptorTable::operator=(TDescriptorTable&& other56) {
  slotDescriptors = std::move(other56.slotDescriptors);
  tupleDescriptors = std::move(other56.tupleDescriptors);
  tableDescriptors = std::move(other56.tableDescriptors);
  __isset = std::move(other56.__isset);
  return *this;
}
void TDescriptorTable::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "TDescriptorTable(";
  out << "slotDescriptors="; (__isset.slotDescriptors ? (out << to_string(slotDescriptors)) : (out << "<null>"));
  out << ", " << "tupleDescriptors=" << to_string(tupleDescriptors);
  out << ", " << "tableDescriptors="; (__isset.tableDescriptors ? (out << to_string(tableDescriptors)) : (out << "<null>"));
  out << ")";
}


TDescriptorTableSerialized::~TDescriptorTableSerialized() throw() {
}


void TDescriptorTableSerialized::__set_thrift_desc_tbl(const std::string& val) {
  this->thrift_desc_tbl = val;
}
std::ostream& operator<<(std::ostream& out, const TDescriptorTableSerialized& obj)
{
  obj.printTo(out);
  return out;
}


void swap(TDescriptorTableSerialized &a, TDescriptorTableSerialized &b) {
  using ::std::swap;
  swap(a.thrift_desc_tbl, b.thrift_desc_tbl);
}

TDescriptorTableSerialized::TDescriptorTableSerialized(const TDescriptorTableSerialized& other57) {
  thrift_desc_tbl = other57.thrift_desc_tbl;
}
TDescriptorTableSerialized::TDescriptorTableSerialized( TDescriptorTableSerialized&& other58) {
  thrift_desc_tbl = std::move(other58.thrift_desc_tbl);
}
TDescriptorTableSerialized& TDescriptorTableSerialized::operator=(const TDescriptorTableSerialized& other59) {
  thrift_desc_tbl = other59.thrift_desc_tbl;
  return *this;
}
TDescriptorTableSerialized& TDescriptorTableSerialized::operator=(TDescriptorTableSerialized&& other60) {
  thrift_desc_tbl = std::move(other60.thrift_desc_tbl);
  return *this;
}
void TDescriptorTableSerialized::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "TDescriptorTableSerialized(";
  out << "thrift_desc_tbl=" << to_string(thrift_desc_tbl);
  out << ")";
}

} // namespace
