/**
 * Autogenerated by Thrift Compiler (0.11.0)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#include "ExecStats_types.h"

#include <algorithm>
#include <ostream>

#include <thrift/TToString.h>

namespace impala {

int _kTExecStateValues[] = {
  TExecState::REGISTERED,
  TExecState::PLANNING,
  TExecState::QUEUED,
  TExecState::RUNNING,
  TExecState::FINISHED,
  TExecState::CANCELLED,
  TExecState::FAILED
};
const char* _kTExecStateNames[] = {
  "REGISTERED",
  "PLANNING",
  "QUEUED",
  "RUNNING",
  "FINISHED",
  "CANCELLED",
  "FAILED"
};
const std::map<int, const char*> _TExecState_VALUES_TO_NAMES(::apache::thrift::TEnumIterator(7, _kTExecStateValues, _kTExecStateNames), ::apache::thrift::TEnumIterator(-1, NULL, NULL));

std::ostream& operator<<(std::ostream& out, const TExecState::type& val) {
  std::map<int, const char*>::const_iterator it = _TExecState_VALUES_TO_NAMES.find(val);
  if (it != _TExecState_VALUES_TO_NAMES.end()) {
    out << it->second;
  } else {
    out << static_cast<int>(val);
  }
  return out;
}


TExecStats::~TExecStats() throw() {
}


void TExecStats::__set_latency_ns(const int64_t val) {
  this->latency_ns = val;
__isset.latency_ns = true;
}

void TExecStats::__set_cpu_time_ns(const int64_t val) {
  this->cpu_time_ns = val;
__isset.cpu_time_ns = true;
}

void TExecStats::__set_cardinality(const int64_t val) {
  this->cardinality = val;
__isset.cardinality = true;
}

void TExecStats::__set_memory_used(const int64_t val) {
  this->memory_used = val;
__isset.memory_used = true;
}
std::ostream& operator<<(std::ostream& out, const TExecStats& obj)
{
  obj.printTo(out);
  return out;
}


void swap(TExecStats &a, TExecStats &b) {
  using ::std::swap;
  swap(a.latency_ns, b.latency_ns);
  swap(a.cpu_time_ns, b.cpu_time_ns);
  swap(a.cardinality, b.cardinality);
  swap(a.memory_used, b.memory_used);
  swap(a.__isset, b.__isset);
}

TExecStats::TExecStats(const TExecStats& other0) {
  latency_ns = other0.latency_ns;
  cpu_time_ns = other0.cpu_time_ns;
  cardinality = other0.cardinality;
  memory_used = other0.memory_used;
  __isset = other0.__isset;
}
TExecStats::TExecStats( TExecStats&& other1) {
  latency_ns = std::move(other1.latency_ns);
  cpu_time_ns = std::move(other1.cpu_time_ns);
  cardinality = std::move(other1.cardinality);
  memory_used = std::move(other1.memory_used);
  __isset = std::move(other1.__isset);
}
TExecStats& TExecStats::operator=(const TExecStats& other2) {
  latency_ns = other2.latency_ns;
  cpu_time_ns = other2.cpu_time_ns;
  cardinality = other2.cardinality;
  memory_used = other2.memory_used;
  __isset = other2.__isset;
  return *this;
}
TExecStats& TExecStats::operator=(TExecStats&& other3) {
  latency_ns = std::move(other3.latency_ns);
  cpu_time_ns = std::move(other3.cpu_time_ns);
  cardinality = std::move(other3.cardinality);
  memory_used = std::move(other3.memory_used);
  __isset = std::move(other3.__isset);
  return *this;
}
void TExecStats::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "TExecStats(";
  out << "latency_ns="; (__isset.latency_ns ? (out << to_string(latency_ns)) : (out << "<null>"));
  out << ", " << "cpu_time_ns="; (__isset.cpu_time_ns ? (out << to_string(cpu_time_ns)) : (out << "<null>"));
  out << ", " << "cardinality="; (__isset.cardinality ? (out << to_string(cardinality)) : (out << "<null>"));
  out << ", " << "memory_used="; (__isset.memory_used ? (out << to_string(memory_used)) : (out << "<null>"));
  out << ")";
}


TPlanNodeExecSummary::~TPlanNodeExecSummary() throw() {
}


void TPlanNodeExecSummary::__set_node_id(const  ::impala::TPlanNodeId val) {
  this->node_id = val;
}

void TPlanNodeExecSummary::__set_fragment_idx(const  ::impala::TFragmentIdx val) {
  this->fragment_idx = val;
}

void TPlanNodeExecSummary::__set_label(const std::string& val) {
  this->label = val;
}

void TPlanNodeExecSummary::__set_label_detail(const std::string& val) {
  this->label_detail = val;
__isset.label_detail = true;
}

void TPlanNodeExecSummary::__set_num_children(const int32_t val) {
  this->num_children = val;
}

void TPlanNodeExecSummary::__set_estimated_stats(const TExecStats& val) {
  this->estimated_stats = val;
__isset.estimated_stats = true;
}

void TPlanNodeExecSummary::__set_exec_stats(const std::vector<TExecStats> & val) {
  this->exec_stats = val;
__isset.exec_stats = true;
}

void TPlanNodeExecSummary::__set_is_broadcast(const bool val) {
  this->is_broadcast = val;
__isset.is_broadcast = true;
}

void TPlanNodeExecSummary::__set_num_hosts(const int32_t val) {
  this->num_hosts = val;
__isset.num_hosts = true;
}
std::ostream& operator<<(std::ostream& out, const TPlanNodeExecSummary& obj)
{
  obj.printTo(out);
  return out;
}


void swap(TPlanNodeExecSummary &a, TPlanNodeExecSummary &b) {
  using ::std::swap;
  swap(a.node_id, b.node_id);
  swap(a.fragment_idx, b.fragment_idx);
  swap(a.label, b.label);
  swap(a.label_detail, b.label_detail);
  swap(a.num_children, b.num_children);
  swap(a.estimated_stats, b.estimated_stats);
  swap(a.exec_stats, b.exec_stats);
  swap(a.is_broadcast, b.is_broadcast);
  swap(a.num_hosts, b.num_hosts);
  swap(a.__isset, b.__isset);
}

TPlanNodeExecSummary::TPlanNodeExecSummary(const TPlanNodeExecSummary& other10) {
  node_id = other10.node_id;
  fragment_idx = other10.fragment_idx;
  label = other10.label;
  label_detail = other10.label_detail;
  num_children = other10.num_children;
  estimated_stats = other10.estimated_stats;
  exec_stats = other10.exec_stats;
  is_broadcast = other10.is_broadcast;
  num_hosts = other10.num_hosts;
  __isset = other10.__isset;
}
TPlanNodeExecSummary::TPlanNodeExecSummary( TPlanNodeExecSummary&& other11) {
  node_id = std::move(other11.node_id);
  fragment_idx = std::move(other11.fragment_idx);
  label = std::move(other11.label);
  label_detail = std::move(other11.label_detail);
  num_children = std::move(other11.num_children);
  estimated_stats = std::move(other11.estimated_stats);
  exec_stats = std::move(other11.exec_stats);
  is_broadcast = std::move(other11.is_broadcast);
  num_hosts = std::move(other11.num_hosts);
  __isset = std::move(other11.__isset);
}
TPlanNodeExecSummary& TPlanNodeExecSummary::operator=(const TPlanNodeExecSummary& other12) {
  node_id = other12.node_id;
  fragment_idx = other12.fragment_idx;
  label = other12.label;
  label_detail = other12.label_detail;
  num_children = other12.num_children;
  estimated_stats = other12.estimated_stats;
  exec_stats = other12.exec_stats;
  is_broadcast = other12.is_broadcast;
  num_hosts = other12.num_hosts;
  __isset = other12.__isset;
  return *this;
}
TPlanNodeExecSummary& TPlanNodeExecSummary::operator=(TPlanNodeExecSummary&& other13) {
  node_id = std::move(other13.node_id);
  fragment_idx = std::move(other13.fragment_idx);
  label = std::move(other13.label);
  label_detail = std::move(other13.label_detail);
  num_children = std::move(other13.num_children);
  estimated_stats = std::move(other13.estimated_stats);
  exec_stats = std::move(other13.exec_stats);
  is_broadcast = std::move(other13.is_broadcast);
  num_hosts = std::move(other13.num_hosts);
  __isset = std::move(other13.__isset);
  return *this;
}
void TPlanNodeExecSummary::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "TPlanNodeExecSummary(";
  out << "node_id=" << to_string(node_id);
  out << ", " << "fragment_idx=" << to_string(fragment_idx);
  out << ", " << "label=" << to_string(label);
  out << ", " << "label_detail="; (__isset.label_detail ? (out << to_string(label_detail)) : (out << "<null>"));
  out << ", " << "num_children=" << to_string(num_children);
  out << ", " << "estimated_stats="; (__isset.estimated_stats ? (out << to_string(estimated_stats)) : (out << "<null>"));
  out << ", " << "exec_stats="; (__isset.exec_stats ? (out << to_string(exec_stats)) : (out << "<null>"));
  out << ", " << "is_broadcast="; (__isset.is_broadcast ? (out << to_string(is_broadcast)) : (out << "<null>"));
  out << ", " << "num_hosts="; (__isset.num_hosts ? (out << to_string(num_hosts)) : (out << "<null>"));
  out << ")";
}


TExecProgress::~TExecProgress() throw() {
}


void TExecProgress::__set_total_scan_ranges(const int64_t val) {
  this->total_scan_ranges = val;
__isset.total_scan_ranges = true;
}

void TExecProgress::__set_num_completed_scan_ranges(const int64_t val) {
  this->num_completed_scan_ranges = val;
__isset.num_completed_scan_ranges = true;
}
std::ostream& operator<<(std::ostream& out, const TExecProgress& obj)
{
  obj.printTo(out);
  return out;
}


void swap(TExecProgress &a, TExecProgress &b) {
  using ::std::swap;
  swap(a.total_scan_ranges, b.total_scan_ranges);
  swap(a.num_completed_scan_ranges, b.num_completed_scan_ranges);
  swap(a.__isset, b.__isset);
}

TExecProgress::TExecProgress(const TExecProgress& other14) {
  total_scan_ranges = other14.total_scan_ranges;
  num_completed_scan_ranges = other14.num_completed_scan_ranges;
  __isset = other14.__isset;
}
TExecProgress::TExecProgress( TExecProgress&& other15) {
  total_scan_ranges = std::move(other15.total_scan_ranges);
  num_completed_scan_ranges = std::move(other15.num_completed_scan_ranges);
  __isset = std::move(other15.__isset);
}
TExecProgress& TExecProgress::operator=(const TExecProgress& other16) {
  total_scan_ranges = other16.total_scan_ranges;
  num_completed_scan_ranges = other16.num_completed_scan_ranges;
  __isset = other16.__isset;
  return *this;
}
TExecProgress& TExecProgress::operator=(TExecProgress&& other17) {
  total_scan_ranges = std::move(other17.total_scan_ranges);
  num_completed_scan_ranges = std::move(other17.num_completed_scan_ranges);
  __isset = std::move(other17.__isset);
  return *this;
}
void TExecProgress::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "TExecProgress(";
  out << "total_scan_ranges="; (__isset.total_scan_ranges ? (out << to_string(total_scan_ranges)) : (out << "<null>"));
  out << ", " << "num_completed_scan_ranges="; (__isset.num_completed_scan_ranges ? (out << to_string(num_completed_scan_ranges)) : (out << "<null>"));
  out << ")";
}


TExecSummary::~TExecSummary() throw() {
}


void TExecSummary::__set_state(const TExecState::type val) {
  this->state = val;
}

void TExecSummary::__set_status(const  ::impala::TStatus& val) {
  this->status = val;
__isset.status = true;
}

void TExecSummary::__set_nodes(const std::vector<TPlanNodeExecSummary> & val) {
  this->nodes = val;
__isset.nodes = true;
}

void TExecSummary::__set_exch_to_sender_map(const std::map<int32_t, int32_t> & val) {
  this->exch_to_sender_map = val;
__isset.exch_to_sender_map = true;
}

void TExecSummary::__set_error_logs(const std::vector<std::string> & val) {
  this->error_logs = val;
__isset.error_logs = true;
}

void TExecSummary::__set_progress(const TExecProgress& val) {
  this->progress = val;
__isset.progress = true;
}

void TExecSummary::__set_is_queued(const bool val) {
  this->is_queued = val;
__isset.is_queued = true;
}

void TExecSummary::__set_queued_reason(const std::string& val) {
  this->queued_reason = val;
__isset.queued_reason = true;
}
std::ostream& operator<<(std::ostream& out, const TExecSummary& obj)
{
  obj.printTo(out);
  return out;
}


void swap(TExecSummary &a, TExecSummary &b) {
  using ::std::swap;
  swap(a.state, b.state);
  swap(a.status, b.status);
  swap(a.nodes, b.nodes);
  swap(a.exch_to_sender_map, b.exch_to_sender_map);
  swap(a.error_logs, b.error_logs);
  swap(a.progress, b.progress);
  swap(a.is_queued, b.is_queued);
  swap(a.queued_reason, b.queued_reason);
  swap(a.__isset, b.__isset);
}

TExecSummary::TExecSummary(const TExecSummary& other39) {
  state = other39.state;
  status = other39.status;
  nodes = other39.nodes;
  exch_to_sender_map = other39.exch_to_sender_map;
  error_logs = other39.error_logs;
  progress = other39.progress;
  is_queued = other39.is_queued;
  queued_reason = other39.queued_reason;
  __isset = other39.__isset;
}
TExecSummary::TExecSummary( TExecSummary&& other40) {
  state = std::move(other40.state);
  status = std::move(other40.status);
  nodes = std::move(other40.nodes);
  exch_to_sender_map = std::move(other40.exch_to_sender_map);
  error_logs = std::move(other40.error_logs);
  progress = std::move(other40.progress);
  is_queued = std::move(other40.is_queued);
  queued_reason = std::move(other40.queued_reason);
  __isset = std::move(other40.__isset);
}
TExecSummary& TExecSummary::operator=(const TExecSummary& other41) {
  state = other41.state;
  status = other41.status;
  nodes = other41.nodes;
  exch_to_sender_map = other41.exch_to_sender_map;
  error_logs = other41.error_logs;
  progress = other41.progress;
  is_queued = other41.is_queued;
  queued_reason = other41.queued_reason;
  __isset = other41.__isset;
  return *this;
}
TExecSummary& TExecSummary::operator=(TExecSummary&& other42) {
  state = std::move(other42.state);
  status = std::move(other42.status);
  nodes = std::move(other42.nodes);
  exch_to_sender_map = std::move(other42.exch_to_sender_map);
  error_logs = std::move(other42.error_logs);
  progress = std::move(other42.progress);
  is_queued = std::move(other42.is_queued);
  queued_reason = std::move(other42.queued_reason);
  __isset = std::move(other42.__isset);
  return *this;
}
void TExecSummary::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "TExecSummary(";
  out << "state=" << to_string(state);
  out << ", " << "status="; (__isset.status ? (out << to_string(status)) : (out << "<null>"));
  out << ", " << "nodes="; (__isset.nodes ? (out << to_string(nodes)) : (out << "<null>"));
  out << ", " << "exch_to_sender_map="; (__isset.exch_to_sender_map ? (out << to_string(exch_to_sender_map)) : (out << "<null>"));
  out << ", " << "error_logs="; (__isset.error_logs ? (out << to_string(error_logs)) : (out << "<null>"));
  out << ", " << "progress="; (__isset.progress ? (out << to_string(progress)) : (out << "<null>"));
  out << ", " << "is_queued="; (__isset.is_queued ? (out << to_string(is_queued)) : (out << "<null>"));
  out << ", " << "queued_reason="; (__isset.queued_reason ? (out << to_string(queued_reason)) : (out << "<null>"));
  out << ")";
}

} // namespace
