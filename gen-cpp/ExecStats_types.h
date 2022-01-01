/**
 * Autogenerated by Thrift Compiler (0.11.0)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef ExecStats_TYPES_H
#define ExecStats_TYPES_H

#include <iosfwd>

#include <thrift/Thrift.h>
#include <thrift/TApplicationException.h>
#include <thrift/TBase.h>
#include <thrift/protocol/TProtocol.h>
#include <thrift/transport/TTransport.h>

#include <thrift/stdcxx.h>
#include "Status_types.h"
#include "Types_types.h"


namespace impala {

struct TExecState {
  enum type {
    REGISTERED = 0,
    PLANNING = 1,
    QUEUED = 2,
    RUNNING = 3,
    FINISHED = 4,
    CANCELLED = 5,
    FAILED = 6
  };
};

extern const std::map<int, const char*> _TExecState_VALUES_TO_NAMES;

std::ostream& operator<<(std::ostream& out, const TExecState::type& val);

class TExecStats;

class TPlanNodeExecSummary;

class TExecProgress;

class TExecSummary;

typedef struct _TExecStats__isset {
  _TExecStats__isset() : latency_ns(false), cpu_time_ns(false), cardinality(false), memory_used(false) {}
  bool latency_ns :1;
  bool cpu_time_ns :1;
  bool cardinality :1;
  bool memory_used :1;
} _TExecStats__isset;

class TExecStats {
 public:

  TExecStats(const TExecStats&);
  TExecStats(TExecStats&&);
  TExecStats& operator=(const TExecStats&);
  TExecStats& operator=(TExecStats&&);
  TExecStats() : latency_ns(0), cpu_time_ns(0), cardinality(0), memory_used(0) {
  }

  virtual ~TExecStats() throw();
  int64_t latency_ns;
  int64_t cpu_time_ns;
  int64_t cardinality;
  int64_t memory_used;

  _TExecStats__isset __isset;

  void __set_latency_ns(const int64_t val);

  void __set_cpu_time_ns(const int64_t val);

  void __set_cardinality(const int64_t val);

  void __set_memory_used(const int64_t val);

  template <class Protocol_>
  uint32_t read(Protocol_* iprot);
  template <class Protocol_>
  uint32_t write(Protocol_* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(TExecStats &a, TExecStats &b);

std::ostream& operator<<(std::ostream& out, const TExecStats& obj);

typedef struct _TPlanNodeExecSummary__isset {
  _TPlanNodeExecSummary__isset() : label_detail(false), estimated_stats(false), exec_stats(false), is_broadcast(false), num_hosts(false) {}
  bool label_detail :1;
  bool estimated_stats :1;
  bool exec_stats :1;
  bool is_broadcast :1;
  bool num_hosts :1;
} _TPlanNodeExecSummary__isset;

class TPlanNodeExecSummary {
 public:

  TPlanNodeExecSummary(const TPlanNodeExecSummary&);
  TPlanNodeExecSummary(TPlanNodeExecSummary&&);
  TPlanNodeExecSummary& operator=(const TPlanNodeExecSummary&);
  TPlanNodeExecSummary& operator=(TPlanNodeExecSummary&&);
  TPlanNodeExecSummary() : node_id(0), fragment_idx(0), label(), label_detail(), num_children(0), is_broadcast(0), num_hosts(0) {
  }

  virtual ~TPlanNodeExecSummary() throw();
   ::impala::TPlanNodeId node_id;
   ::impala::TFragmentIdx fragment_idx;
  std::string label;
  std::string label_detail;
  int32_t num_children;
  TExecStats estimated_stats;
  std::vector<TExecStats>  exec_stats;
  bool is_broadcast;
  int32_t num_hosts;

  _TPlanNodeExecSummary__isset __isset;

  void __set_node_id(const  ::impala::TPlanNodeId val);

  void __set_fragment_idx(const  ::impala::TFragmentIdx val);

  void __set_label(const std::string& val);

  void __set_label_detail(const std::string& val);

  void __set_num_children(const int32_t val);

  void __set_estimated_stats(const TExecStats& val);

  void __set_exec_stats(const std::vector<TExecStats> & val);

  void __set_is_broadcast(const bool val);

  void __set_num_hosts(const int32_t val);

  template <class Protocol_>
  uint32_t read(Protocol_* iprot);
  template <class Protocol_>
  uint32_t write(Protocol_* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(TPlanNodeExecSummary &a, TPlanNodeExecSummary &b);

std::ostream& operator<<(std::ostream& out, const TPlanNodeExecSummary& obj);

typedef struct _TExecProgress__isset {
  _TExecProgress__isset() : total_scan_ranges(false), num_completed_scan_ranges(false) {}
  bool total_scan_ranges :1;
  bool num_completed_scan_ranges :1;
} _TExecProgress__isset;

class TExecProgress {
 public:

  TExecProgress(const TExecProgress&);
  TExecProgress(TExecProgress&&);
  TExecProgress& operator=(const TExecProgress&);
  TExecProgress& operator=(TExecProgress&&);
  TExecProgress() : total_scan_ranges(0), num_completed_scan_ranges(0) {
  }

  virtual ~TExecProgress() throw();
  int64_t total_scan_ranges;
  int64_t num_completed_scan_ranges;

  _TExecProgress__isset __isset;

  void __set_total_scan_ranges(const int64_t val);

  void __set_num_completed_scan_ranges(const int64_t val);

  template <class Protocol_>
  uint32_t read(Protocol_* iprot);
  template <class Protocol_>
  uint32_t write(Protocol_* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(TExecProgress &a, TExecProgress &b);

std::ostream& operator<<(std::ostream& out, const TExecProgress& obj);

typedef struct _TExecSummary__isset {
  _TExecSummary__isset() : status(false), nodes(false), exch_to_sender_map(false), error_logs(false), progress(false), is_queued(false), queued_reason(false) {}
  bool status :1;
  bool nodes :1;
  bool exch_to_sender_map :1;
  bool error_logs :1;
  bool progress :1;
  bool is_queued :1;
  bool queued_reason :1;
} _TExecSummary__isset;

class TExecSummary {
 public:

  TExecSummary(const TExecSummary&);
  TExecSummary(TExecSummary&&);
  TExecSummary& operator=(const TExecSummary&);
  TExecSummary& operator=(TExecSummary&&);
  TExecSummary() : state((TExecState::type)0), is_queued(0), queued_reason() {
  }

  virtual ~TExecSummary() throw();
  TExecState::type state;
   ::impala::TStatus status;
  std::vector<TPlanNodeExecSummary>  nodes;
  std::map<int32_t, int32_t>  exch_to_sender_map;
  std::vector<std::string>  error_logs;
  TExecProgress progress;
  bool is_queued;
  std::string queued_reason;

  _TExecSummary__isset __isset;

  void __set_state(const TExecState::type val);

  void __set_status(const  ::impala::TStatus& val);

  void __set_nodes(const std::vector<TPlanNodeExecSummary> & val);

  void __set_exch_to_sender_map(const std::map<int32_t, int32_t> & val);

  void __set_error_logs(const std::vector<std::string> & val);

  void __set_progress(const TExecProgress& val);

  void __set_is_queued(const bool val);

  void __set_queued_reason(const std::string& val);

  template <class Protocol_>
  uint32_t read(Protocol_* iprot);
  template <class Protocol_>
  uint32_t write(Protocol_* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(TExecSummary &a, TExecSummary &b);

std::ostream& operator<<(std::ostream& out, const TExecSummary& obj);

} // namespace

#include "ExecStats_types.tcc"

#endif
