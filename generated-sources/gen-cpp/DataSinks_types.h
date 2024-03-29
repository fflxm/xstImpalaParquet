/**
 * Autogenerated by Thrift Compiler (0.11.0)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef DataSinks_TYPES_H
#define DataSinks_TYPES_H

#include <iosfwd>

#include <thrift/Thrift.h>
#include <thrift/TApplicationException.h>
#include <thrift/TBase.h>
#include <thrift/protocol/TProtocol.h>
#include <thrift/transport/TTransport.h>

#include <thrift/stdcxx.h>
#include "ExecStats_types.h"
#include "Exprs_types.h"
#include "Types_types.h"
#include "Descriptors_types.h"
#include "Partitions_types.h"
#include "PlanNodes_types.h"
#include "ResourceProfile_types.h"


namespace impala {

struct TDataSinkType {
  enum type {
    DATA_STREAM_SINK = 0,
    TABLE_SINK = 1,
    HASH_JOIN_BUILDER = 2,
    PLAN_ROOT_SINK = 3,
    NESTED_LOOP_JOIN_BUILDER = 4
  };
};

extern const std::map<int, const char*> _TDataSinkType_VALUES_TO_NAMES;

std::ostream& operator<<(std::ostream& out, const TDataSinkType::type& val);

struct TSinkAction {
  enum type {
    INSERT = 0,
    UPDATE = 1,
    UPSERT = 2,
    DELETE = 3
  };
};

extern const std::map<int, const char*> _TSinkAction_VALUES_TO_NAMES;

std::ostream& operator<<(std::ostream& out, const TSinkAction::type& val);

struct TTableSinkType {
  enum type {
    HDFS = 0,
    HBASE = 1,
    KUDU = 2
  };
};

extern const std::map<int, const char*> _TTableSinkType_VALUES_TO_NAMES;

std::ostream& operator<<(std::ostream& out, const TTableSinkType::type& val);

class TDataStreamSink;

class THdfsTableSink;

class TKuduTableSink;

class TJoinBuildSink;

class TPlanRootSink;

class TTableSink;

class TDataSink;


class TDataStreamSink {
 public:

  TDataStreamSink(const TDataStreamSink&);
  TDataStreamSink(TDataStreamSink&&);
  TDataStreamSink& operator=(const TDataStreamSink&);
  TDataStreamSink& operator=(TDataStreamSink&&);
  TDataStreamSink() : dest_node_id(0) {
  }

  virtual ~TDataStreamSink() throw();
   ::impala::TPlanNodeId dest_node_id;
   ::impala::TDataPartition output_partition;

  void __set_dest_node_id(const  ::impala::TPlanNodeId val);

  void __set_output_partition(const  ::impala::TDataPartition& val);

  template <class Protocol_>
  uint32_t read(Protocol_* iprot);
  template <class Protocol_>
  uint32_t write(Protocol_* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(TDataStreamSink &a, TDataStreamSink &b);

std::ostream& operator<<(std::ostream& out, const TDataStreamSink& obj);

typedef struct _THdfsTableSink__isset {
  _THdfsTableSink__isset() : skip_header_line_count(false), sort_columns(false), write_id(false), is_result_sink(true), external_output_dir(false), external_output_partition_depth(false), parquet_bloom_filter_col_info(false) {}
  bool skip_header_line_count :1;
  bool sort_columns :1;
  bool write_id :1;
  bool is_result_sink :1;
  bool external_output_dir :1;
  bool external_output_partition_depth :1;
  bool parquet_bloom_filter_col_info :1;
} _THdfsTableSink__isset;

class THdfsTableSink {
 public:

  THdfsTableSink(const THdfsTableSink&);
  THdfsTableSink(THdfsTableSink&&);
  THdfsTableSink& operator=(const THdfsTableSink&);
  THdfsTableSink& operator=(THdfsTableSink&&);
  THdfsTableSink() : overwrite(0), skip_header_line_count(0), input_is_clustered(0), write_id(0), sorting_order(( ::impala::TSortingOrder::type)0), is_result_sink(false), external_output_dir(), external_output_partition_depth(0) {
  }

  virtual ~THdfsTableSink() throw();
  std::vector< ::impala::TExpr>  partition_key_exprs;
  bool overwrite;
  int32_t skip_header_line_count;
  bool input_is_clustered;
  std::vector<int32_t>  sort_columns;
  int64_t write_id;
   ::impala::TSortingOrder::type sorting_order;
  bool is_result_sink;
  std::string external_output_dir;
  int32_t external_output_partition_depth;
  std::map<std::string, int64_t>  parquet_bloom_filter_col_info;

  _THdfsTableSink__isset __isset;

  void __set_partition_key_exprs(const std::vector< ::impala::TExpr> & val);

  void __set_overwrite(const bool val);

  void __set_skip_header_line_count(const int32_t val);

  void __set_input_is_clustered(const bool val);

  void __set_sort_columns(const std::vector<int32_t> & val);

  void __set_write_id(const int64_t val);

  void __set_sorting_order(const  ::impala::TSortingOrder::type val);

  void __set_is_result_sink(const bool val);

  void __set_external_output_dir(const std::string& val);

  void __set_external_output_partition_depth(const int32_t val);

  void __set_parquet_bloom_filter_col_info(const std::map<std::string, int64_t> & val);

  template <class Protocol_>
  uint32_t read(Protocol_* iprot);
  template <class Protocol_>
  uint32_t write(Protocol_* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(THdfsTableSink &a, THdfsTableSink &b);

std::ostream& operator<<(std::ostream& out, const THdfsTableSink& obj);

typedef struct _TKuduTableSink__isset {
  _TKuduTableSink__isset() : referenced_columns(false), ignore_not_found_or_duplicate(false), kudu_txn_token(false) {}
  bool referenced_columns :1;
  bool ignore_not_found_or_duplicate :1;
  bool kudu_txn_token :1;
} _TKuduTableSink__isset;

class TKuduTableSink {
 public:

  TKuduTableSink(const TKuduTableSink&);
  TKuduTableSink(TKuduTableSink&&);
  TKuduTableSink& operator=(const TKuduTableSink&);
  TKuduTableSink& operator=(TKuduTableSink&&);
  TKuduTableSink() : ignore_not_found_or_duplicate(0), kudu_txn_token() {
  }

  virtual ~TKuduTableSink() throw();
  std::vector<int32_t>  referenced_columns;
  bool ignore_not_found_or_duplicate;
  std::string kudu_txn_token;

  _TKuduTableSink__isset __isset;

  void __set_referenced_columns(const std::vector<int32_t> & val);

  void __set_ignore_not_found_or_duplicate(const bool val);

  void __set_kudu_txn_token(const std::string& val);

  template <class Protocol_>
  uint32_t read(Protocol_* iprot);
  template <class Protocol_>
  uint32_t write(Protocol_* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(TKuduTableSink &a, TKuduTableSink &b);

std::ostream& operator<<(std::ostream& out, const TKuduTableSink& obj);

typedef struct _TJoinBuildSink__isset {
  _TJoinBuildSink__isset() : eq_join_conjuncts(false), runtime_filters(false), hash_seed(false), share_build(false) {}
  bool eq_join_conjuncts :1;
  bool runtime_filters :1;
  bool hash_seed :1;
  bool share_build :1;
} _TJoinBuildSink__isset;

class TJoinBuildSink {
 public:

  TJoinBuildSink(const TJoinBuildSink&);
  TJoinBuildSink(TJoinBuildSink&&);
  TJoinBuildSink& operator=(const TJoinBuildSink&);
  TJoinBuildSink& operator=(TJoinBuildSink&&);
  TJoinBuildSink() : dest_node_id(0), join_op(( ::impala::TJoinOp::type)0), hash_seed(0), share_build(0) {
  }

  virtual ~TJoinBuildSink() throw();
   ::impala::TPlanNodeId dest_node_id;
   ::impala::TJoinOp::type join_op;
  std::vector< ::impala::TEqJoinCondition>  eq_join_conjuncts;
  std::vector< ::impala::TRuntimeFilterDesc>  runtime_filters;
  int32_t hash_seed;
  bool share_build;

  _TJoinBuildSink__isset __isset;

  void __set_dest_node_id(const  ::impala::TPlanNodeId val);

  void __set_join_op(const  ::impala::TJoinOp::type val);

  void __set_eq_join_conjuncts(const std::vector< ::impala::TEqJoinCondition> & val);

  void __set_runtime_filters(const std::vector< ::impala::TRuntimeFilterDesc> & val);

  void __set_hash_seed(const int32_t val);

  void __set_share_build(const bool val);

  template <class Protocol_>
  uint32_t read(Protocol_* iprot);
  template <class Protocol_>
  uint32_t write(Protocol_* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(TJoinBuildSink &a, TJoinBuildSink &b);

std::ostream& operator<<(std::ostream& out, const TJoinBuildSink& obj);


class TPlanRootSink {
 public:

  TPlanRootSink(const TPlanRootSink&);
  TPlanRootSink(TPlanRootSink&&);
  TPlanRootSink& operator=(const TPlanRootSink&);
  TPlanRootSink& operator=(TPlanRootSink&&);
  TPlanRootSink() {
  }

  virtual ~TPlanRootSink() throw();
   ::impala::TBackendResourceProfile resource_profile;

  void __set_resource_profile(const  ::impala::TBackendResourceProfile& val);

  template <class Protocol_>
  uint32_t read(Protocol_* iprot);
  template <class Protocol_>
  uint32_t write(Protocol_* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(TPlanRootSink &a, TPlanRootSink &b);

std::ostream& operator<<(std::ostream& out, const TPlanRootSink& obj);

typedef struct _TTableSink__isset {
  _TTableSink__isset() : hdfs_table_sink(false), kudu_table_sink(false) {}
  bool hdfs_table_sink :1;
  bool kudu_table_sink :1;
} _TTableSink__isset;

class TTableSink {
 public:

  TTableSink(const TTableSink&);
  TTableSink(TTableSink&&);
  TTableSink& operator=(const TTableSink&);
  TTableSink& operator=(TTableSink&&);
  TTableSink() : target_table_id(0), type((TTableSinkType::type)0), action((TSinkAction::type)0) {
  }

  virtual ~TTableSink() throw();
   ::impala::TTableId target_table_id;
  TTableSinkType::type type;
  TSinkAction::type action;
  THdfsTableSink hdfs_table_sink;
  TKuduTableSink kudu_table_sink;

  _TTableSink__isset __isset;

  void __set_target_table_id(const  ::impala::TTableId val);

  void __set_type(const TTableSinkType::type val);

  void __set_action(const TSinkAction::type val);

  void __set_hdfs_table_sink(const THdfsTableSink& val);

  void __set_kudu_table_sink(const TKuduTableSink& val);

  template <class Protocol_>
  uint32_t read(Protocol_* iprot);
  template <class Protocol_>
  uint32_t write(Protocol_* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(TTableSink &a, TTableSink &b);

std::ostream& operator<<(std::ostream& out, const TTableSink& obj);

typedef struct _TDataSink__isset {
  _TDataSink__isset() : stream_sink(false), table_sink(false), join_build_sink(false), plan_root_sink(false), label(false), estimated_stats(false), output_exprs(false), resource_profile(false) {}
  bool stream_sink :1;
  bool table_sink :1;
  bool join_build_sink :1;
  bool plan_root_sink :1;
  bool label :1;
  bool estimated_stats :1;
  bool output_exprs :1;
  bool resource_profile :1;
} _TDataSink__isset;

class TDataSink {
 public:

  TDataSink(const TDataSink&);
  TDataSink(TDataSink&&);
  TDataSink& operator=(const TDataSink&);
  TDataSink& operator=(TDataSink&&);
  TDataSink() : type((TDataSinkType::type)0), label() {
  }

  virtual ~TDataSink() throw();
  TDataSinkType::type type;
  TDataStreamSink stream_sink;
  TTableSink table_sink;
  TJoinBuildSink join_build_sink;
  TPlanRootSink plan_root_sink;
  std::string label;
   ::impala::TExecStats estimated_stats;
  std::vector< ::impala::TExpr>  output_exprs;
   ::impala::TBackendResourceProfile resource_profile;

  _TDataSink__isset __isset;

  void __set_type(const TDataSinkType::type val);

  void __set_stream_sink(const TDataStreamSink& val);

  void __set_table_sink(const TTableSink& val);

  void __set_join_build_sink(const TJoinBuildSink& val);

  void __set_plan_root_sink(const TPlanRootSink& val);

  void __set_label(const std::string& val);

  void __set_estimated_stats(const  ::impala::TExecStats& val);

  void __set_output_exprs(const std::vector< ::impala::TExpr> & val);

  void __set_resource_profile(const  ::impala::TBackendResourceProfile& val);

  template <class Protocol_>
  uint32_t read(Protocol_* iprot);
  template <class Protocol_>
  uint32_t write(Protocol_* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(TDataSink &a, TDataSink &b);

std::ostream& operator<<(std::ostream& out, const TDataSink& obj);

} // namespace

#include "DataSinks_types.tcc"

#endif
