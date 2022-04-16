/**
 * Autogenerated by Thrift Compiler (0.11.0)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#include "DataSinks_types.h"

#include <algorithm>
#include <ostream>

#include <thrift/TToString.h>

namespace impala {

int _kTDataSinkTypeValues[] = {
  TDataSinkType::DATA_STREAM_SINK,
  TDataSinkType::TABLE_SINK,
  TDataSinkType::HASH_JOIN_BUILDER,
  TDataSinkType::PLAN_ROOT_SINK,
  TDataSinkType::NESTED_LOOP_JOIN_BUILDER
};
const char* _kTDataSinkTypeNames[] = {
  "DATA_STREAM_SINK",
  "TABLE_SINK",
  "HASH_JOIN_BUILDER",
  "PLAN_ROOT_SINK",
  "NESTED_LOOP_JOIN_BUILDER"
};
const std::map<int, const char*> _TDataSinkType_VALUES_TO_NAMES(::apache::thrift::TEnumIterator(5, _kTDataSinkTypeValues, _kTDataSinkTypeNames), ::apache::thrift::TEnumIterator(-1, NULL, NULL));

std::ostream& operator<<(std::ostream& out, const TDataSinkType::type& val) {
  std::map<int, const char*>::const_iterator it = _TDataSinkType_VALUES_TO_NAMES.find(val);
  if (it != _TDataSinkType_VALUES_TO_NAMES.end()) {
    out << it->second;
  } else {
    out << static_cast<int>(val);
  }
  return out;
}

int _kTSinkActionValues[] = {
  TSinkAction::INSERT,
  TSinkAction::UPDATE,
  TSinkAction::UPSERT,
  TSinkAction::DELETE
};
const char* _kTSinkActionNames[] = {
  "INSERT",
  "UPDATE",
  "UPSERT",
  "DELETE"
};
const std::map<int, const char*> _TSinkAction_VALUES_TO_NAMES(::apache::thrift::TEnumIterator(4, _kTSinkActionValues, _kTSinkActionNames), ::apache::thrift::TEnumIterator(-1, NULL, NULL));

std::ostream& operator<<(std::ostream& out, const TSinkAction::type& val) {
  std::map<int, const char*>::const_iterator it = _TSinkAction_VALUES_TO_NAMES.find(val);
  if (it != _TSinkAction_VALUES_TO_NAMES.end()) {
    out << it->second;
  } else {
    out << static_cast<int>(val);
  }
  return out;
}

int _kTTableSinkTypeValues[] = {
  TTableSinkType::HDFS,
  TTableSinkType::HBASE,
  TTableSinkType::KUDU
};
const char* _kTTableSinkTypeNames[] = {
  "HDFS",
  "HBASE",
  "KUDU"
};
const std::map<int, const char*> _TTableSinkType_VALUES_TO_NAMES(::apache::thrift::TEnumIterator(3, _kTTableSinkTypeValues, _kTTableSinkTypeNames), ::apache::thrift::TEnumIterator(-1, NULL, NULL));

std::ostream& operator<<(std::ostream& out, const TTableSinkType::type& val) {
  std::map<int, const char*>::const_iterator it = _TTableSinkType_VALUES_TO_NAMES.find(val);
  if (it != _TTableSinkType_VALUES_TO_NAMES.end()) {
    out << it->second;
  } else {
    out << static_cast<int>(val);
  }
  return out;
}


TDataStreamSink::~TDataStreamSink() throw() {
}


void TDataStreamSink::__set_dest_node_id(const  ::impala::TPlanNodeId val) {
  this->dest_node_id = val;
}

void TDataStreamSink::__set_output_partition(const  ::impala::TDataPartition& val) {
  this->output_partition = val;
}
std::ostream& operator<<(std::ostream& out, const TDataStreamSink& obj)
{
  obj.printTo(out);
  return out;
}


void swap(TDataStreamSink &a, TDataStreamSink &b) {
  using ::std::swap;
  swap(a.dest_node_id, b.dest_node_id);
  swap(a.output_partition, b.output_partition);
}

TDataStreamSink::TDataStreamSink(const TDataStreamSink& other0) {
  dest_node_id = other0.dest_node_id;
  output_partition = other0.output_partition;
}
TDataStreamSink::TDataStreamSink( TDataStreamSink&& other1) {
  dest_node_id = std::move(other1.dest_node_id);
  output_partition = std::move(other1.output_partition);
}
TDataStreamSink& TDataStreamSink::operator=(const TDataStreamSink& other2) {
  dest_node_id = other2.dest_node_id;
  output_partition = other2.output_partition;
  return *this;
}
TDataStreamSink& TDataStreamSink::operator=(TDataStreamSink&& other3) {
  dest_node_id = std::move(other3.dest_node_id);
  output_partition = std::move(other3.output_partition);
  return *this;
}
void TDataStreamSink::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "TDataStreamSink(";
  out << "dest_node_id=" << to_string(dest_node_id);
  out << ", " << "output_partition=" << to_string(output_partition);
  out << ")";
}


THdfsTableSink::~THdfsTableSink() throw() {
}


void THdfsTableSink::__set_partition_key_exprs(const std::vector< ::impala::TExpr> & val) {
  this->partition_key_exprs = val;
}

void THdfsTableSink::__set_overwrite(const bool val) {
  this->overwrite = val;
}

void THdfsTableSink::__set_skip_header_line_count(const int32_t val) {
  this->skip_header_line_count = val;
__isset.skip_header_line_count = true;
}

void THdfsTableSink::__set_input_is_clustered(const bool val) {
  this->input_is_clustered = val;
}

void THdfsTableSink::__set_sort_columns(const std::vector<int32_t> & val) {
  this->sort_columns = val;
__isset.sort_columns = true;
}

void THdfsTableSink::__set_write_id(const int64_t val) {
  this->write_id = val;
__isset.write_id = true;
}

void THdfsTableSink::__set_sorting_order(const  ::impala::TSortingOrder::type val) {
  this->sorting_order = val;
}

void THdfsTableSink::__set_is_result_sink(const bool val) {
  this->is_result_sink = val;
__isset.is_result_sink = true;
}

void THdfsTableSink::__set_external_output_dir(const std::string& val) {
  this->external_output_dir = val;
__isset.external_output_dir = true;
}

void THdfsTableSink::__set_external_output_partition_depth(const int32_t val) {
  this->external_output_partition_depth = val;
__isset.external_output_partition_depth = true;
}

void THdfsTableSink::__set_parquet_bloom_filter_col_info(const std::map<std::string, int64_t> & val) {
  this->parquet_bloom_filter_col_info = val;
__isset.parquet_bloom_filter_col_info = true;
}
std::ostream& operator<<(std::ostream& out, const THdfsTableSink& obj)
{
  obj.printTo(out);
  return out;
}


void swap(THdfsTableSink &a, THdfsTableSink &b) {
  using ::std::swap;
  swap(a.partition_key_exprs, b.partition_key_exprs);
  swap(a.overwrite, b.overwrite);
  swap(a.skip_header_line_count, b.skip_header_line_count);
  swap(a.input_is_clustered, b.input_is_clustered);
  swap(a.sort_columns, b.sort_columns);
  swap(a.write_id, b.write_id);
  swap(a.sorting_order, b.sorting_order);
  swap(a.is_result_sink, b.is_result_sink);
  swap(a.external_output_dir, b.external_output_dir);
  swap(a.external_output_partition_depth, b.external_output_partition_depth);
  swap(a.parquet_bloom_filter_col_info, b.parquet_bloom_filter_col_info);
  swap(a.__isset, b.__isset);
}

THdfsTableSink::THdfsTableSink(const THdfsTableSink& other25) {
  partition_key_exprs = other25.partition_key_exprs;
  overwrite = other25.overwrite;
  skip_header_line_count = other25.skip_header_line_count;
  input_is_clustered = other25.input_is_clustered;
  sort_columns = other25.sort_columns;
  write_id = other25.write_id;
  sorting_order = other25.sorting_order;
  is_result_sink = other25.is_result_sink;
  external_output_dir = other25.external_output_dir;
  external_output_partition_depth = other25.external_output_partition_depth;
  parquet_bloom_filter_col_info = other25.parquet_bloom_filter_col_info;
  __isset = other25.__isset;
}
THdfsTableSink::THdfsTableSink( THdfsTableSink&& other26) {
  partition_key_exprs = std::move(other26.partition_key_exprs);
  overwrite = std::move(other26.overwrite);
  skip_header_line_count = std::move(other26.skip_header_line_count);
  input_is_clustered = std::move(other26.input_is_clustered);
  sort_columns = std::move(other26.sort_columns);
  write_id = std::move(other26.write_id);
  sorting_order = std::move(other26.sorting_order);
  is_result_sink = std::move(other26.is_result_sink);
  external_output_dir = std::move(other26.external_output_dir);
  external_output_partition_depth = std::move(other26.external_output_partition_depth);
  parquet_bloom_filter_col_info = std::move(other26.parquet_bloom_filter_col_info);
  __isset = std::move(other26.__isset);
}
THdfsTableSink& THdfsTableSink::operator=(const THdfsTableSink& other27) {
  partition_key_exprs = other27.partition_key_exprs;
  overwrite = other27.overwrite;
  skip_header_line_count = other27.skip_header_line_count;
  input_is_clustered = other27.input_is_clustered;
  sort_columns = other27.sort_columns;
  write_id = other27.write_id;
  sorting_order = other27.sorting_order;
  is_result_sink = other27.is_result_sink;
  external_output_dir = other27.external_output_dir;
  external_output_partition_depth = other27.external_output_partition_depth;
  parquet_bloom_filter_col_info = other27.parquet_bloom_filter_col_info;
  __isset = other27.__isset;
  return *this;
}
THdfsTableSink& THdfsTableSink::operator=(THdfsTableSink&& other28) {
  partition_key_exprs = std::move(other28.partition_key_exprs);
  overwrite = std::move(other28.overwrite);
  skip_header_line_count = std::move(other28.skip_header_line_count);
  input_is_clustered = std::move(other28.input_is_clustered);
  sort_columns = std::move(other28.sort_columns);
  write_id = std::move(other28.write_id);
  sorting_order = std::move(other28.sorting_order);
  is_result_sink = std::move(other28.is_result_sink);
  external_output_dir = std::move(other28.external_output_dir);
  external_output_partition_depth = std::move(other28.external_output_partition_depth);
  parquet_bloom_filter_col_info = std::move(other28.parquet_bloom_filter_col_info);
  __isset = std::move(other28.__isset);
  return *this;
}
void THdfsTableSink::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "THdfsTableSink(";
  out << "partition_key_exprs=" << to_string(partition_key_exprs);
  out << ", " << "overwrite=" << to_string(overwrite);
  out << ", " << "skip_header_line_count="; (__isset.skip_header_line_count ? (out << to_string(skip_header_line_count)) : (out << "<null>"));
  out << ", " << "input_is_clustered=" << to_string(input_is_clustered);
  out << ", " << "sort_columns="; (__isset.sort_columns ? (out << to_string(sort_columns)) : (out << "<null>"));
  out << ", " << "write_id="; (__isset.write_id ? (out << to_string(write_id)) : (out << "<null>"));
  out << ", " << "sorting_order=" << to_string(sorting_order);
  out << ", " << "is_result_sink="; (__isset.is_result_sink ? (out << to_string(is_result_sink)) : (out << "<null>"));
  out << ", " << "external_output_dir="; (__isset.external_output_dir ? (out << to_string(external_output_dir)) : (out << "<null>"));
  out << ", " << "external_output_partition_depth="; (__isset.external_output_partition_depth ? (out << to_string(external_output_partition_depth)) : (out << "<null>"));
  out << ", " << "parquet_bloom_filter_col_info="; (__isset.parquet_bloom_filter_col_info ? (out << to_string(parquet_bloom_filter_col_info)) : (out << "<null>"));
  out << ")";
}


TKuduTableSink::~TKuduTableSink() throw() {
}


void TKuduTableSink::__set_referenced_columns(const std::vector<int32_t> & val) {
  this->referenced_columns = val;
__isset.referenced_columns = true;
}

void TKuduTableSink::__set_ignore_not_found_or_duplicate(const bool val) {
  this->ignore_not_found_or_duplicate = val;
__isset.ignore_not_found_or_duplicate = true;
}

void TKuduTableSink::__set_kudu_txn_token(const std::string& val) {
  this->kudu_txn_token = val;
__isset.kudu_txn_token = true;
}
std::ostream& operator<<(std::ostream& out, const TKuduTableSink& obj)
{
  obj.printTo(out);
  return out;
}


void swap(TKuduTableSink &a, TKuduTableSink &b) {
  using ::std::swap;
  swap(a.referenced_columns, b.referenced_columns);
  swap(a.ignore_not_found_or_duplicate, b.ignore_not_found_or_duplicate);
  swap(a.kudu_txn_token, b.kudu_txn_token);
  swap(a.__isset, b.__isset);
}

TKuduTableSink::TKuduTableSink(const TKuduTableSink& other35) {
  referenced_columns = other35.referenced_columns;
  ignore_not_found_or_duplicate = other35.ignore_not_found_or_duplicate;
  kudu_txn_token = other35.kudu_txn_token;
  __isset = other35.__isset;
}
TKuduTableSink::TKuduTableSink( TKuduTableSink&& other36) {
  referenced_columns = std::move(other36.referenced_columns);
  ignore_not_found_or_duplicate = std::move(other36.ignore_not_found_or_duplicate);
  kudu_txn_token = std::move(other36.kudu_txn_token);
  __isset = std::move(other36.__isset);
}
TKuduTableSink& TKuduTableSink::operator=(const TKuduTableSink& other37) {
  referenced_columns = other37.referenced_columns;
  ignore_not_found_or_duplicate = other37.ignore_not_found_or_duplicate;
  kudu_txn_token = other37.kudu_txn_token;
  __isset = other37.__isset;
  return *this;
}
TKuduTableSink& TKuduTableSink::operator=(TKuduTableSink&& other38) {
  referenced_columns = std::move(other38.referenced_columns);
  ignore_not_found_or_duplicate = std::move(other38.ignore_not_found_or_duplicate);
  kudu_txn_token = std::move(other38.kudu_txn_token);
  __isset = std::move(other38.__isset);
  return *this;
}
void TKuduTableSink::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "TKuduTableSink(";
  out << "referenced_columns="; (__isset.referenced_columns ? (out << to_string(referenced_columns)) : (out << "<null>"));
  out << ", " << "ignore_not_found_or_duplicate="; (__isset.ignore_not_found_or_duplicate ? (out << to_string(ignore_not_found_or_duplicate)) : (out << "<null>"));
  out << ", " << "kudu_txn_token="; (__isset.kudu_txn_token ? (out << to_string(kudu_txn_token)) : (out << "<null>"));
  out << ")";
}


TJoinBuildSink::~TJoinBuildSink() throw() {
}


void TJoinBuildSink::__set_dest_node_id(const  ::impala::TPlanNodeId val) {
  this->dest_node_id = val;
}

void TJoinBuildSink::__set_join_op(const  ::impala::TJoinOp::type val) {
  this->join_op = val;
}

void TJoinBuildSink::__set_eq_join_conjuncts(const std::vector< ::impala::TEqJoinCondition> & val) {
  this->eq_join_conjuncts = val;
__isset.eq_join_conjuncts = true;
}

void TJoinBuildSink::__set_runtime_filters(const std::vector< ::impala::TRuntimeFilterDesc> & val) {
  this->runtime_filters = val;
__isset.runtime_filters = true;
}

void TJoinBuildSink::__set_hash_seed(const int32_t val) {
  this->hash_seed = val;
__isset.hash_seed = true;
}

void TJoinBuildSink::__set_share_build(const bool val) {
  this->share_build = val;
__isset.share_build = true;
}
std::ostream& operator<<(std::ostream& out, const TJoinBuildSink& obj)
{
  obj.printTo(out);
  return out;
}


void swap(TJoinBuildSink &a, TJoinBuildSink &b) {
  using ::std::swap;
  swap(a.dest_node_id, b.dest_node_id);
  swap(a.join_op, b.join_op);
  swap(a.eq_join_conjuncts, b.eq_join_conjuncts);
  swap(a.runtime_filters, b.runtime_filters);
  swap(a.hash_seed, b.hash_seed);
  swap(a.share_build, b.share_build);
  swap(a.__isset, b.__isset);
}

TJoinBuildSink::TJoinBuildSink(const TJoinBuildSink& other52) {
  dest_node_id = other52.dest_node_id;
  join_op = other52.join_op;
  eq_join_conjuncts = other52.eq_join_conjuncts;
  runtime_filters = other52.runtime_filters;
  hash_seed = other52.hash_seed;
  share_build = other52.share_build;
  __isset = other52.__isset;
}
TJoinBuildSink::TJoinBuildSink( TJoinBuildSink&& other53) {
  dest_node_id = std::move(other53.dest_node_id);
  join_op = std::move(other53.join_op);
  eq_join_conjuncts = std::move(other53.eq_join_conjuncts);
  runtime_filters = std::move(other53.runtime_filters);
  hash_seed = std::move(other53.hash_seed);
  share_build = std::move(other53.share_build);
  __isset = std::move(other53.__isset);
}
TJoinBuildSink& TJoinBuildSink::operator=(const TJoinBuildSink& other54) {
  dest_node_id = other54.dest_node_id;
  join_op = other54.join_op;
  eq_join_conjuncts = other54.eq_join_conjuncts;
  runtime_filters = other54.runtime_filters;
  hash_seed = other54.hash_seed;
  share_build = other54.share_build;
  __isset = other54.__isset;
  return *this;
}
TJoinBuildSink& TJoinBuildSink::operator=(TJoinBuildSink&& other55) {
  dest_node_id = std::move(other55.dest_node_id);
  join_op = std::move(other55.join_op);
  eq_join_conjuncts = std::move(other55.eq_join_conjuncts);
  runtime_filters = std::move(other55.runtime_filters);
  hash_seed = std::move(other55.hash_seed);
  share_build = std::move(other55.share_build);
  __isset = std::move(other55.__isset);
  return *this;
}
void TJoinBuildSink::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "TJoinBuildSink(";
  out << "dest_node_id=" << to_string(dest_node_id);
  out << ", " << "join_op=" << to_string(join_op);
  out << ", " << "eq_join_conjuncts="; (__isset.eq_join_conjuncts ? (out << to_string(eq_join_conjuncts)) : (out << "<null>"));
  out << ", " << "runtime_filters="; (__isset.runtime_filters ? (out << to_string(runtime_filters)) : (out << "<null>"));
  out << ", " << "hash_seed="; (__isset.hash_seed ? (out << to_string(hash_seed)) : (out << "<null>"));
  out << ", " << "share_build="; (__isset.share_build ? (out << to_string(share_build)) : (out << "<null>"));
  out << ")";
}


TPlanRootSink::~TPlanRootSink() throw() {
}


void TPlanRootSink::__set_resource_profile(const  ::impala::TBackendResourceProfile& val) {
  this->resource_profile = val;
}
std::ostream& operator<<(std::ostream& out, const TPlanRootSink& obj)
{
  obj.printTo(out);
  return out;
}


void swap(TPlanRootSink &a, TPlanRootSink &b) {
  using ::std::swap;
  swap(a.resource_profile, b.resource_profile);
}

TPlanRootSink::TPlanRootSink(const TPlanRootSink& other56) {
  resource_profile = other56.resource_profile;
}
TPlanRootSink::TPlanRootSink( TPlanRootSink&& other57) {
  resource_profile = std::move(other57.resource_profile);
}
TPlanRootSink& TPlanRootSink::operator=(const TPlanRootSink& other58) {
  resource_profile = other58.resource_profile;
  return *this;
}
TPlanRootSink& TPlanRootSink::operator=(TPlanRootSink&& other59) {
  resource_profile = std::move(other59.resource_profile);
  return *this;
}
void TPlanRootSink::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "TPlanRootSink(";
  out << "resource_profile=" << to_string(resource_profile);
  out << ")";
}


TTableSink::~TTableSink() throw() {
}


void TTableSink::__set_target_table_id(const  ::impala::TTableId val) {
  this->target_table_id = val;
}

void TTableSink::__set_type(const TTableSinkType::type val) {
  this->type = val;
}

void TTableSink::__set_action(const TSinkAction::type val) {
  this->action = val;
}

void TTableSink::__set_hdfs_table_sink(const THdfsTableSink& val) {
  this->hdfs_table_sink = val;
__isset.hdfs_table_sink = true;
}

void TTableSink::__set_kudu_table_sink(const TKuduTableSink& val) {
  this->kudu_table_sink = val;
__isset.kudu_table_sink = true;
}
std::ostream& operator<<(std::ostream& out, const TTableSink& obj)
{
  obj.printTo(out);
  return out;
}


void swap(TTableSink &a, TTableSink &b) {
  using ::std::swap;
  swap(a.target_table_id, b.target_table_id);
  swap(a.type, b.type);
  swap(a.action, b.action);
  swap(a.hdfs_table_sink, b.hdfs_table_sink);
  swap(a.kudu_table_sink, b.kudu_table_sink);
  swap(a.__isset, b.__isset);
}

TTableSink::TTableSink(const TTableSink& other62) {
  target_table_id = other62.target_table_id;
  type = other62.type;
  action = other62.action;
  hdfs_table_sink = other62.hdfs_table_sink;
  kudu_table_sink = other62.kudu_table_sink;
  __isset = other62.__isset;
}
TTableSink::TTableSink( TTableSink&& other63) {
  target_table_id = std::move(other63.target_table_id);
  type = std::move(other63.type);
  action = std::move(other63.action);
  hdfs_table_sink = std::move(other63.hdfs_table_sink);
  kudu_table_sink = std::move(other63.kudu_table_sink);
  __isset = std::move(other63.__isset);
}
TTableSink& TTableSink::operator=(const TTableSink& other64) {
  target_table_id = other64.target_table_id;
  type = other64.type;
  action = other64.action;
  hdfs_table_sink = other64.hdfs_table_sink;
  kudu_table_sink = other64.kudu_table_sink;
  __isset = other64.__isset;
  return *this;
}
TTableSink& TTableSink::operator=(TTableSink&& other65) {
  target_table_id = std::move(other65.target_table_id);
  type = std::move(other65.type);
  action = std::move(other65.action);
  hdfs_table_sink = std::move(other65.hdfs_table_sink);
  kudu_table_sink = std::move(other65.kudu_table_sink);
  __isset = std::move(other65.__isset);
  return *this;
}
void TTableSink::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "TTableSink(";
  out << "target_table_id=" << to_string(target_table_id);
  out << ", " << "type=" << to_string(type);
  out << ", " << "action=" << to_string(action);
  out << ", " << "hdfs_table_sink="; (__isset.hdfs_table_sink ? (out << to_string(hdfs_table_sink)) : (out << "<null>"));
  out << ", " << "kudu_table_sink="; (__isset.kudu_table_sink ? (out << to_string(kudu_table_sink)) : (out << "<null>"));
  out << ")";
}


TDataSink::~TDataSink() throw() {
}


void TDataSink::__set_type(const TDataSinkType::type val) {
  this->type = val;
}

void TDataSink::__set_stream_sink(const TDataStreamSink& val) {
  this->stream_sink = val;
__isset.stream_sink = true;
}

void TDataSink::__set_table_sink(const TTableSink& val) {
  this->table_sink = val;
__isset.table_sink = true;
}

void TDataSink::__set_join_build_sink(const TJoinBuildSink& val) {
  this->join_build_sink = val;
__isset.join_build_sink = true;
}

void TDataSink::__set_plan_root_sink(const TPlanRootSink& val) {
  this->plan_root_sink = val;
__isset.plan_root_sink = true;
}

void TDataSink::__set_label(const std::string& val) {
  this->label = val;
__isset.label = true;
}

void TDataSink::__set_estimated_stats(const  ::impala::TExecStats& val) {
  this->estimated_stats = val;
__isset.estimated_stats = true;
}

void TDataSink::__set_output_exprs(const std::vector< ::impala::TExpr> & val) {
  this->output_exprs = val;
__isset.output_exprs = true;
}

void TDataSink::__set_resource_profile(const  ::impala::TBackendResourceProfile& val) {
  this->resource_profile = val;
__isset.resource_profile = true;
}
std::ostream& operator<<(std::ostream& out, const TDataSink& obj)
{
  obj.printTo(out);
  return out;
}


void swap(TDataSink &a, TDataSink &b) {
  using ::std::swap;
  swap(a.type, b.type);
  swap(a.stream_sink, b.stream_sink);
  swap(a.table_sink, b.table_sink);
  swap(a.join_build_sink, b.join_build_sink);
  swap(a.plan_root_sink, b.plan_root_sink);
  swap(a.label, b.label);
  swap(a.estimated_stats, b.estimated_stats);
  swap(a.output_exprs, b.output_exprs);
  swap(a.resource_profile, b.resource_profile);
  swap(a.__isset, b.__isset);
}

TDataSink::TDataSink(const TDataSink& other73) {
  type = other73.type;
  stream_sink = other73.stream_sink;
  table_sink = other73.table_sink;
  join_build_sink = other73.join_build_sink;
  plan_root_sink = other73.plan_root_sink;
  label = other73.label;
  estimated_stats = other73.estimated_stats;
  output_exprs = other73.output_exprs;
  resource_profile = other73.resource_profile;
  __isset = other73.__isset;
}
TDataSink::TDataSink( TDataSink&& other74) {
  type = std::move(other74.type);
  stream_sink = std::move(other74.stream_sink);
  table_sink = std::move(other74.table_sink);
  join_build_sink = std::move(other74.join_build_sink);
  plan_root_sink = std::move(other74.plan_root_sink);
  label = std::move(other74.label);
  estimated_stats = std::move(other74.estimated_stats);
  output_exprs = std::move(other74.output_exprs);
  resource_profile = std::move(other74.resource_profile);
  __isset = std::move(other74.__isset);
}
TDataSink& TDataSink::operator=(const TDataSink& other75) {
  type = other75.type;
  stream_sink = other75.stream_sink;
  table_sink = other75.table_sink;
  join_build_sink = other75.join_build_sink;
  plan_root_sink = other75.plan_root_sink;
  label = other75.label;
  estimated_stats = other75.estimated_stats;
  output_exprs = other75.output_exprs;
  resource_profile = other75.resource_profile;
  __isset = other75.__isset;
  return *this;
}
TDataSink& TDataSink::operator=(TDataSink&& other76) {
  type = std::move(other76.type);
  stream_sink = std::move(other76.stream_sink);
  table_sink = std::move(other76.table_sink);
  join_build_sink = std::move(other76.join_build_sink);
  plan_root_sink = std::move(other76.plan_root_sink);
  label = std::move(other76.label);
  estimated_stats = std::move(other76.estimated_stats);
  output_exprs = std::move(other76.output_exprs);
  resource_profile = std::move(other76.resource_profile);
  __isset = std::move(other76.__isset);
  return *this;
}
void TDataSink::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "TDataSink(";
  out << "type=" << to_string(type);
  out << ", " << "stream_sink="; (__isset.stream_sink ? (out << to_string(stream_sink)) : (out << "<null>"));
  out << ", " << "table_sink="; (__isset.table_sink ? (out << to_string(table_sink)) : (out << "<null>"));
  out << ", " << "join_build_sink="; (__isset.join_build_sink ? (out << to_string(join_build_sink)) : (out << "<null>"));
  out << ", " << "plan_root_sink="; (__isset.plan_root_sink ? (out << to_string(plan_root_sink)) : (out << "<null>"));
  out << ", " << "label="; (__isset.label ? (out << to_string(label)) : (out << "<null>"));
  out << ", " << "estimated_stats="; (__isset.estimated_stats ? (out << to_string(estimated_stats)) : (out << "<null>"));
  out << ", " << "output_exprs="; (__isset.output_exprs ? (out << to_string(output_exprs)) : (out << "<null>"));
  out << ", " << "resource_profile="; (__isset.resource_profile ? (out << to_string(resource_profile)) : (out << "<null>"));
  out << ")";
}

} // namespace
