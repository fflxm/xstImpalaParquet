/**
 * Autogenerated by Thrift Compiler (0.11.0)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef ImpalaInternalService_TYPES_H
#define ImpalaInternalService_TYPES_H

#include <iosfwd>

#include <thrift/Thrift.h>
#include <thrift/TApplicationException.h>
#include <thrift/TBase.h>
#include <thrift/protocol/TProtocol.h>
#include <thrift/transport/TTransport.h>

#include <thrift/stdcxx.h>
#include "Status_types.h"
#include "ErrorCodes_types.h"
#include "Types_types.h"
#include "Exprs_types.h"
#include "CatalogObjects_types.h"
#include "Descriptors_types.h"
#include "PlanNodes_types.h"
#include "Planner_types.h"
#include "DataSinks_types.h"
#include "Results_types.h"
#include "RuntimeProfile_types.h"
#include "ImpalaService_types.h"
#include "Data_types.h"
#include "Query_types.h"


namespace impala {

struct ImpalaInternalServiceVersion {
  enum type {
    V1 = 0
  };
};

extern const std::map<int, const char*> _ImpalaInternalServiceVersion_VALUES_TO_NAMES;

std::ostream& operator<<(std::ostream& out, const ImpalaInternalServiceVersion::type& val);

class TDebugOptions;

class TRuntimeFilterSource;

class TPlanFragmentInstanceCtx;

class TExecPlanFragmentInfo;

class TResolveRequestPoolParams;

class TResolveRequestPoolResult;

class TPoolConfigParams;

class TPoolConfig;

class TParseDateStringResult;

typedef struct _TDebugOptions__isset {
  _TDebugOptions__isset() : node_id(false), phase(false), action(false), action_param(false) {}
  bool node_id :1;
  bool phase :1;
  bool action :1;
  bool action_param :1;
} _TDebugOptions__isset;

class TDebugOptions {
 public:

  TDebugOptions(const TDebugOptions&);
  TDebugOptions(TDebugOptions&&);
  TDebugOptions& operator=(const TDebugOptions&);
  TDebugOptions& operator=(TDebugOptions&&);
  TDebugOptions() : node_id(0), phase(( ::impala::TExecNodePhase::type)0), action(( ::impala::TDebugAction::type)0), action_param() {
  }

  virtual ~TDebugOptions() throw();
   ::impala::TPlanNodeId node_id;
   ::impala::TExecNodePhase::type phase;
   ::impala::TDebugAction::type action;
  std::string action_param;

  _TDebugOptions__isset __isset;

  void __set_node_id(const  ::impala::TPlanNodeId val);

  void __set_phase(const  ::impala::TExecNodePhase::type val);

  void __set_action(const  ::impala::TDebugAction::type val);

  void __set_action_param(const std::string& val);

  template <class Protocol_>
  uint32_t read(Protocol_* iprot);
  template <class Protocol_>
  uint32_t write(Protocol_* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(TDebugOptions &a, TDebugOptions &b);

std::ostream& operator<<(std::ostream& out, const TDebugOptions& obj);


class TRuntimeFilterSource {
 public:

  TRuntimeFilterSource(const TRuntimeFilterSource&);
  TRuntimeFilterSource(TRuntimeFilterSource&&);
  TRuntimeFilterSource& operator=(const TRuntimeFilterSource&);
  TRuntimeFilterSource& operator=(TRuntimeFilterSource&&);
  TRuntimeFilterSource() : src_node_id(0), filter_id(0) {
  }

  virtual ~TRuntimeFilterSource() throw();
   ::impala::TPlanNodeId src_node_id;
  int32_t filter_id;

  void __set_src_node_id(const  ::impala::TPlanNodeId val);

  void __set_filter_id(const int32_t val);

  template <class Protocol_>
  uint32_t read(Protocol_* iprot);
  template <class Protocol_>
  uint32_t write(Protocol_* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(TRuntimeFilterSource &a, TRuntimeFilterSource &b);

std::ostream& operator<<(std::ostream& out, const TRuntimeFilterSource& obj);

typedef struct _TPlanFragmentInstanceCtx__isset {
  _TPlanFragmentInstanceCtx__isset() : sender_id(false), debug_options(false), filters_produced(false), num_join_build_outputs(false), num_backends(false) {}
  bool sender_id :1;
  bool debug_options :1;
  bool filters_produced :1;
  bool num_join_build_outputs :1;
  bool num_backends :1;
} _TPlanFragmentInstanceCtx__isset;

class TPlanFragmentInstanceCtx {
 public:

  TPlanFragmentInstanceCtx(const TPlanFragmentInstanceCtx&);
  TPlanFragmentInstanceCtx(TPlanFragmentInstanceCtx&&);
  TPlanFragmentInstanceCtx& operator=(const TPlanFragmentInstanceCtx&);
  TPlanFragmentInstanceCtx& operator=(TPlanFragmentInstanceCtx&&);
  TPlanFragmentInstanceCtx() : fragment_idx(0), per_fragment_instance_idx(0), sender_id(0), num_join_build_outputs(0), num_backends(0) {
  }

  virtual ~TPlanFragmentInstanceCtx() throw();
   ::impala::TFragmentIdx fragment_idx;
   ::impala::TUniqueId fragment_instance_id;
  int32_t per_fragment_instance_idx;
  std::map< ::impala::TPlanNodeId, int32_t>  per_exch_num_senders;
  int32_t sender_id;
  TDebugOptions debug_options;
  std::vector<TRuntimeFilterSource>  filters_produced;
  int32_t num_join_build_outputs;
  int32_t num_backends;

  _TPlanFragmentInstanceCtx__isset __isset;

  void __set_fragment_idx(const  ::impala::TFragmentIdx val);

  void __set_fragment_instance_id(const  ::impala::TUniqueId& val);

  void __set_per_fragment_instance_idx(const int32_t val);

  void __set_per_exch_num_senders(const std::map< ::impala::TPlanNodeId, int32_t> & val);

  void __set_sender_id(const int32_t val);

  void __set_debug_options(const TDebugOptions& val);

  void __set_filters_produced(const std::vector<TRuntimeFilterSource> & val);

  void __set_num_join_build_outputs(const int32_t val);

  void __set_num_backends(const int32_t val);

  template <class Protocol_>
  uint32_t read(Protocol_* iprot);
  template <class Protocol_>
  uint32_t write(Protocol_* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(TPlanFragmentInstanceCtx &a, TPlanFragmentInstanceCtx &b);

std::ostream& operator<<(std::ostream& out, const TPlanFragmentInstanceCtx& obj);

typedef struct _TExecPlanFragmentInfo__isset {
  _TExecPlanFragmentInfo__isset() : fragments(false), fragment_instance_ctxs(false) {}
  bool fragments :1;
  bool fragment_instance_ctxs :1;
} _TExecPlanFragmentInfo__isset;

class TExecPlanFragmentInfo {
 public:

  TExecPlanFragmentInfo(const TExecPlanFragmentInfo&);
  TExecPlanFragmentInfo(TExecPlanFragmentInfo&&);
  TExecPlanFragmentInfo& operator=(const TExecPlanFragmentInfo&);
  TExecPlanFragmentInfo& operator=(TExecPlanFragmentInfo&&);
  TExecPlanFragmentInfo() {
  }

  virtual ~TExecPlanFragmentInfo() throw();
  std::vector< ::impala::TPlanFragment>  fragments;
  std::vector<TPlanFragmentInstanceCtx>  fragment_instance_ctxs;

  _TExecPlanFragmentInfo__isset __isset;

  void __set_fragments(const std::vector< ::impala::TPlanFragment> & val);

  void __set_fragment_instance_ctxs(const std::vector<TPlanFragmentInstanceCtx> & val);

  template <class Protocol_>
  uint32_t read(Protocol_* iprot);
  template <class Protocol_>
  uint32_t write(Protocol_* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(TExecPlanFragmentInfo &a, TExecPlanFragmentInfo &b);

std::ostream& operator<<(std::ostream& out, const TExecPlanFragmentInfo& obj);


class TResolveRequestPoolParams {
 public:

  TResolveRequestPoolParams(const TResolveRequestPoolParams&);
  TResolveRequestPoolParams(TResolveRequestPoolParams&&);
  TResolveRequestPoolParams& operator=(const TResolveRequestPoolParams&);
  TResolveRequestPoolParams& operator=(TResolveRequestPoolParams&&);
  TResolveRequestPoolParams() : user(), requested_pool() {
  }

  virtual ~TResolveRequestPoolParams() throw();
  std::string user;
  std::string requested_pool;

  void __set_user(const std::string& val);

  void __set_requested_pool(const std::string& val);

  template <class Protocol_>
  uint32_t read(Protocol_* iprot);
  template <class Protocol_>
  uint32_t write(Protocol_* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(TResolveRequestPoolParams &a, TResolveRequestPoolParams &b);

std::ostream& operator<<(std::ostream& out, const TResolveRequestPoolParams& obj);

typedef struct _TResolveRequestPoolResult__isset {
  _TResolveRequestPoolResult__isset() : resolved_pool(false), has_access(false), status(false) {}
  bool resolved_pool :1;
  bool has_access :1;
  bool status :1;
} _TResolveRequestPoolResult__isset;

class TResolveRequestPoolResult {
 public:

  TResolveRequestPoolResult(const TResolveRequestPoolResult&);
  TResolveRequestPoolResult(TResolveRequestPoolResult&&);
  TResolveRequestPoolResult& operator=(const TResolveRequestPoolResult&);
  TResolveRequestPoolResult& operator=(TResolveRequestPoolResult&&);
  TResolveRequestPoolResult() : resolved_pool(), has_access(0) {
  }

  virtual ~TResolveRequestPoolResult() throw();
  std::string resolved_pool;
  bool has_access;
   ::impala::TStatus status;

  _TResolveRequestPoolResult__isset __isset;

  void __set_resolved_pool(const std::string& val);

  void __set_has_access(const bool val);

  void __set_status(const  ::impala::TStatus& val);

  template <class Protocol_>
  uint32_t read(Protocol_* iprot);
  template <class Protocol_>
  uint32_t write(Protocol_* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(TResolveRequestPoolResult &a, TResolveRequestPoolResult &b);

std::ostream& operator<<(std::ostream& out, const TResolveRequestPoolResult& obj);


class TPoolConfigParams {
 public:

  TPoolConfigParams(const TPoolConfigParams&);
  TPoolConfigParams(TPoolConfigParams&&);
  TPoolConfigParams& operator=(const TPoolConfigParams&);
  TPoolConfigParams& operator=(TPoolConfigParams&&);
  TPoolConfigParams() : pool() {
  }

  virtual ~TPoolConfigParams() throw();
  std::string pool;

  void __set_pool(const std::string& val);

  template <class Protocol_>
  uint32_t read(Protocol_* iprot);
  template <class Protocol_>
  uint32_t write(Protocol_* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(TPoolConfigParams &a, TPoolConfigParams &b);

std::ostream& operator<<(std::ostream& out, const TPoolConfigParams& obj);

typedef struct _TPoolConfig__isset {
  _TPoolConfig__isset() : queue_timeout_ms(false) {}
  bool queue_timeout_ms :1;
} _TPoolConfig__isset;

class TPoolConfig {
 public:

  TPoolConfig(const TPoolConfig&);
  TPoolConfig(TPoolConfig&&);
  TPoolConfig& operator=(const TPoolConfig&);
  TPoolConfig& operator=(TPoolConfig&&);
  TPoolConfig() : max_requests(0), max_queued(0), max_mem_resources(0), queue_timeout_ms(0), default_query_options(), max_query_mem_limit(0LL), min_query_mem_limit(0LL), clamp_mem_limit_query_option(true), max_mt_dop(-1LL) {
  }

  virtual ~TPoolConfig() throw();
  int64_t max_requests;
  int64_t max_queued;
  int64_t max_mem_resources;
  int64_t queue_timeout_ms;
  std::string default_query_options;
  int64_t max_query_mem_limit;
  int64_t min_query_mem_limit;
  bool clamp_mem_limit_query_option;
  int64_t max_mt_dop;

  _TPoolConfig__isset __isset;

  void __set_max_requests(const int64_t val);

  void __set_max_queued(const int64_t val);

  void __set_max_mem_resources(const int64_t val);

  void __set_queue_timeout_ms(const int64_t val);

  void __set_default_query_options(const std::string& val);

  void __set_max_query_mem_limit(const int64_t val);

  void __set_min_query_mem_limit(const int64_t val);

  void __set_clamp_mem_limit_query_option(const bool val);

  void __set_max_mt_dop(const int64_t val);

  template <class Protocol_>
  uint32_t read(Protocol_* iprot);
  template <class Protocol_>
  uint32_t write(Protocol_* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(TPoolConfig &a, TPoolConfig &b);

std::ostream& operator<<(std::ostream& out, const TPoolConfig& obj);

typedef struct _TParseDateStringResult__isset {
  _TParseDateStringResult__isset() : days_since_epoch(false), canonical_date_string(false) {}
  bool days_since_epoch :1;
  bool canonical_date_string :1;
} _TParseDateStringResult__isset;

class TParseDateStringResult {
 public:

  TParseDateStringResult(const TParseDateStringResult&);
  TParseDateStringResult(TParseDateStringResult&&);
  TParseDateStringResult& operator=(const TParseDateStringResult&);
  TParseDateStringResult& operator=(TParseDateStringResult&&);
  TParseDateStringResult() : valid(0), days_since_epoch(0), canonical_date_string() {
  }

  virtual ~TParseDateStringResult() throw();
  bool valid;
  int32_t days_since_epoch;
  std::string canonical_date_string;

  _TParseDateStringResult__isset __isset;

  void __set_valid(const bool val);

  void __set_days_since_epoch(const int32_t val);

  void __set_canonical_date_string(const std::string& val);

  template <class Protocol_>
  uint32_t read(Protocol_* iprot);
  template <class Protocol_>
  uint32_t write(Protocol_* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(TParseDateStringResult &a, TParseDateStringResult &b);

std::ostream& operator<<(std::ostream& out, const TParseDateStringResult& obj);

} // namespace

#include "ImpalaInternalService_types.tcc"

#endif