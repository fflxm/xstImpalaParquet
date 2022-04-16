/**
 * Autogenerated by Thrift Compiler (0.11.0)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#include "StatestoreService_types.h"

#include <algorithm>
#include <ostream>

#include <thrift/TToString.h>

namespace impala {

int _kStatestoreServiceVersionValues[] = {
  StatestoreServiceVersion::V1
};
const char* _kStatestoreServiceVersionNames[] = {
  "V1"
};
const std::map<int, const char*> _StatestoreServiceVersion_VALUES_TO_NAMES(::apache::thrift::TEnumIterator(1, _kStatestoreServiceVersionValues, _kStatestoreServiceVersionNames), ::apache::thrift::TEnumIterator(-1, NULL, NULL));

std::ostream& operator<<(std::ostream& out, const StatestoreServiceVersion::type& val) {
  std::map<int, const char*>::const_iterator it = _StatestoreServiceVersion_VALUES_TO_NAMES.find(val);
  if (it != _StatestoreServiceVersion_VALUES_TO_NAMES.end()) {
    out << it->second;
  } else {
    out << static_cast<int>(val);
  }
  return out;
}


THeavyMemoryQuery::~THeavyMemoryQuery() throw() {
}


void THeavyMemoryQuery::__set_memory_consumed(const int64_t val) {
  this->memory_consumed = val;
}

void THeavyMemoryQuery::__set_queryId(const  ::impala::TUniqueId& val) {
  this->queryId = val;
}
std::ostream& operator<<(std::ostream& out, const THeavyMemoryQuery& obj)
{
  obj.printTo(out);
  return out;
}


void swap(THeavyMemoryQuery &a, THeavyMemoryQuery &b) {
  using ::std::swap;
  swap(a.memory_consumed, b.memory_consumed);
  swap(a.queryId, b.queryId);
}

THeavyMemoryQuery::THeavyMemoryQuery(const THeavyMemoryQuery& other0) {
  memory_consumed = other0.memory_consumed;
  queryId = other0.queryId;
}
THeavyMemoryQuery::THeavyMemoryQuery( THeavyMemoryQuery&& other1) {
  memory_consumed = std::move(other1.memory_consumed);
  queryId = std::move(other1.queryId);
}
THeavyMemoryQuery& THeavyMemoryQuery::operator=(const THeavyMemoryQuery& other2) {
  memory_consumed = other2.memory_consumed;
  queryId = other2.queryId;
  return *this;
}
THeavyMemoryQuery& THeavyMemoryQuery::operator=(THeavyMemoryQuery&& other3) {
  memory_consumed = std::move(other3.memory_consumed);
  queryId = std::move(other3.queryId);
  return *this;
}
void THeavyMemoryQuery::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "THeavyMemoryQuery(";
  out << "memory_consumed=" << to_string(memory_consumed);
  out << ", " << "queryId=" << to_string(queryId);
  out << ")";
}


TPoolStats::~TPoolStats() throw() {
}


void TPoolStats::__set_num_admitted_running(const int64_t val) {
  this->num_admitted_running = val;
}

void TPoolStats::__set_num_queued(const int64_t val) {
  this->num_queued = val;
}

void TPoolStats::__set_backend_mem_reserved(const int64_t val) {
  this->backend_mem_reserved = val;
}

void TPoolStats::__set_heavy_memory_queries(const std::vector<THeavyMemoryQuery> & val) {
  this->heavy_memory_queries = val;
}

void TPoolStats::__set_min_memory_consumed(const int64_t val) {
  this->min_memory_consumed = val;
}

void TPoolStats::__set_max_memory_consumed(const int64_t val) {
  this->max_memory_consumed = val;
}

void TPoolStats::__set_total_memory_consumed(const int64_t val) {
  this->total_memory_consumed = val;
}

void TPoolStats::__set_num_running(const int64_t val) {
  this->num_running = val;
}
std::ostream& operator<<(std::ostream& out, const TPoolStats& obj)
{
  obj.printTo(out);
  return out;
}


void swap(TPoolStats &a, TPoolStats &b) {
  using ::std::swap;
  swap(a.num_admitted_running, b.num_admitted_running);
  swap(a.num_queued, b.num_queued);
  swap(a.backend_mem_reserved, b.backend_mem_reserved);
  swap(a.heavy_memory_queries, b.heavy_memory_queries);
  swap(a.min_memory_consumed, b.min_memory_consumed);
  swap(a.max_memory_consumed, b.max_memory_consumed);
  swap(a.total_memory_consumed, b.total_memory_consumed);
  swap(a.num_running, b.num_running);
}

TPoolStats::TPoolStats(const TPoolStats& other10) {
  num_admitted_running = other10.num_admitted_running;
  num_queued = other10.num_queued;
  backend_mem_reserved = other10.backend_mem_reserved;
  heavy_memory_queries = other10.heavy_memory_queries;
  min_memory_consumed = other10.min_memory_consumed;
  max_memory_consumed = other10.max_memory_consumed;
  total_memory_consumed = other10.total_memory_consumed;
  num_running = other10.num_running;
}
TPoolStats::TPoolStats( TPoolStats&& other11) {
  num_admitted_running = std::move(other11.num_admitted_running);
  num_queued = std::move(other11.num_queued);
  backend_mem_reserved = std::move(other11.backend_mem_reserved);
  heavy_memory_queries = std::move(other11.heavy_memory_queries);
  min_memory_consumed = std::move(other11.min_memory_consumed);
  max_memory_consumed = std::move(other11.max_memory_consumed);
  total_memory_consumed = std::move(other11.total_memory_consumed);
  num_running = std::move(other11.num_running);
}
TPoolStats& TPoolStats::operator=(const TPoolStats& other12) {
  num_admitted_running = other12.num_admitted_running;
  num_queued = other12.num_queued;
  backend_mem_reserved = other12.backend_mem_reserved;
  heavy_memory_queries = other12.heavy_memory_queries;
  min_memory_consumed = other12.min_memory_consumed;
  max_memory_consumed = other12.max_memory_consumed;
  total_memory_consumed = other12.total_memory_consumed;
  num_running = other12.num_running;
  return *this;
}
TPoolStats& TPoolStats::operator=(TPoolStats&& other13) {
  num_admitted_running = std::move(other13.num_admitted_running);
  num_queued = std::move(other13.num_queued);
  backend_mem_reserved = std::move(other13.backend_mem_reserved);
  heavy_memory_queries = std::move(other13.heavy_memory_queries);
  min_memory_consumed = std::move(other13.min_memory_consumed);
  max_memory_consumed = std::move(other13.max_memory_consumed);
  total_memory_consumed = std::move(other13.total_memory_consumed);
  num_running = std::move(other13.num_running);
  return *this;
}
void TPoolStats::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "TPoolStats(";
  out << "num_admitted_running=" << to_string(num_admitted_running);
  out << ", " << "num_queued=" << to_string(num_queued);
  out << ", " << "backend_mem_reserved=" << to_string(backend_mem_reserved);
  out << ", " << "heavy_memory_queries=" << to_string(heavy_memory_queries);
  out << ", " << "min_memory_consumed=" << to_string(min_memory_consumed);
  out << ", " << "max_memory_consumed=" << to_string(max_memory_consumed);
  out << ", " << "total_memory_consumed=" << to_string(total_memory_consumed);
  out << ", " << "num_running=" << to_string(num_running);
  out << ")";
}


THostStats::~THostStats() throw() {
}


void THostStats::__set_mem_reserved(const int64_t val) {
  this->mem_reserved = val;
}

void THostStats::__set_mem_admitted(const int64_t val) {
  this->mem_admitted = val;
}

void THostStats::__set_num_admitted(const int64_t val) {
  this->num_admitted = val;
}

void THostStats::__set_slots_in_use(const int64_t val) {
  this->slots_in_use = val;
}
std::ostream& operator<<(std::ostream& out, const THostStats& obj)
{
  obj.printTo(out);
  return out;
}


void swap(THostStats &a, THostStats &b) {
  using ::std::swap;
  swap(a.mem_reserved, b.mem_reserved);
  swap(a.mem_admitted, b.mem_admitted);
  swap(a.num_admitted, b.num_admitted);
  swap(a.slots_in_use, b.slots_in_use);
}

THostStats::THostStats(const THostStats& other14) {
  mem_reserved = other14.mem_reserved;
  mem_admitted = other14.mem_admitted;
  num_admitted = other14.num_admitted;
  slots_in_use = other14.slots_in_use;
}
THostStats::THostStats( THostStats&& other15) {
  mem_reserved = std::move(other15.mem_reserved);
  mem_admitted = std::move(other15.mem_admitted);
  num_admitted = std::move(other15.num_admitted);
  slots_in_use = std::move(other15.slots_in_use);
}
THostStats& THostStats::operator=(const THostStats& other16) {
  mem_reserved = other16.mem_reserved;
  mem_admitted = other16.mem_admitted;
  num_admitted = other16.num_admitted;
  slots_in_use = other16.slots_in_use;
  return *this;
}
THostStats& THostStats::operator=(THostStats&& other17) {
  mem_reserved = std::move(other17.mem_reserved);
  mem_admitted = std::move(other17.mem_admitted);
  num_admitted = std::move(other17.num_admitted);
  slots_in_use = std::move(other17.slots_in_use);
  return *this;
}
void THostStats::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "THostStats(";
  out << "mem_reserved=" << to_string(mem_reserved);
  out << ", " << "mem_admitted=" << to_string(mem_admitted);
  out << ", " << "num_admitted=" << to_string(num_admitted);
  out << ", " << "slots_in_use=" << to_string(slots_in_use);
  out << ")";
}


TPerHostStatsUpdateElement::~TPerHostStatsUpdateElement() throw() {
}


void TPerHostStatsUpdateElement::__set_host_addr(const std::string& val) {
  this->host_addr = val;
}

void TPerHostStatsUpdateElement::__set_stats(const THostStats& val) {
  this->stats = val;
}
std::ostream& operator<<(std::ostream& out, const TPerHostStatsUpdateElement& obj)
{
  obj.printTo(out);
  return out;
}


void swap(TPerHostStatsUpdateElement &a, TPerHostStatsUpdateElement &b) {
  using ::std::swap;
  swap(a.host_addr, b.host_addr);
  swap(a.stats, b.stats);
}

TPerHostStatsUpdateElement::TPerHostStatsUpdateElement(const TPerHostStatsUpdateElement& other18) {
  host_addr = other18.host_addr;
  stats = other18.stats;
}
TPerHostStatsUpdateElement::TPerHostStatsUpdateElement( TPerHostStatsUpdateElement&& other19) {
  host_addr = std::move(other19.host_addr);
  stats = std::move(other19.stats);
}
TPerHostStatsUpdateElement& TPerHostStatsUpdateElement::operator=(const TPerHostStatsUpdateElement& other20) {
  host_addr = other20.host_addr;
  stats = other20.stats;
  return *this;
}
TPerHostStatsUpdateElement& TPerHostStatsUpdateElement::operator=(TPerHostStatsUpdateElement&& other21) {
  host_addr = std::move(other21.host_addr);
  stats = std::move(other21.stats);
  return *this;
}
void TPerHostStatsUpdateElement::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "TPerHostStatsUpdateElement(";
  out << "host_addr=" << to_string(host_addr);
  out << ", " << "stats=" << to_string(stats);
  out << ")";
}


TPerHostStatsUpdate::~TPerHostStatsUpdate() throw() {
}


void TPerHostStatsUpdate::__set_per_host_stats(const std::vector<TPerHostStatsUpdateElement> & val) {
  this->per_host_stats = val;
}
std::ostream& operator<<(std::ostream& out, const TPerHostStatsUpdate& obj)
{
  obj.printTo(out);
  return out;
}


void swap(TPerHostStatsUpdate &a, TPerHostStatsUpdate &b) {
  using ::std::swap;
  swap(a.per_host_stats, b.per_host_stats);
}

TPerHostStatsUpdate::TPerHostStatsUpdate(const TPerHostStatsUpdate& other28) {
  per_host_stats = other28.per_host_stats;
}
TPerHostStatsUpdate::TPerHostStatsUpdate( TPerHostStatsUpdate&& other29) {
  per_host_stats = std::move(other29.per_host_stats);
}
TPerHostStatsUpdate& TPerHostStatsUpdate::operator=(const TPerHostStatsUpdate& other30) {
  per_host_stats = other30.per_host_stats;
  return *this;
}
TPerHostStatsUpdate& TPerHostStatsUpdate::operator=(TPerHostStatsUpdate&& other31) {
  per_host_stats = std::move(other31.per_host_stats);
  return *this;
}
void TPerHostStatsUpdate::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "TPerHostStatsUpdate(";
  out << "per_host_stats=" << to_string(per_host_stats);
  out << ")";
}


TTopicItem::~TTopicItem() throw() {
}


void TTopicItem::__set_key(const std::string& val) {
  this->key = val;
}

void TTopicItem::__set_value(const std::string& val) {
  this->value = val;
}

void TTopicItem::__set_deleted(const bool val) {
  this->deleted = val;
}
std::ostream& operator<<(std::ostream& out, const TTopicItem& obj)
{
  obj.printTo(out);
  return out;
}


void swap(TTopicItem &a, TTopicItem &b) {
  using ::std::swap;
  swap(a.key, b.key);
  swap(a.value, b.value);
  swap(a.deleted, b.deleted);
}

TTopicItem::TTopicItem(const TTopicItem& other32) {
  key = other32.key;
  value = other32.value;
  deleted = other32.deleted;
}
TTopicItem::TTopicItem( TTopicItem&& other33) {
  key = std::move(other33.key);
  value = std::move(other33.value);
  deleted = std::move(other33.deleted);
}
TTopicItem& TTopicItem::operator=(const TTopicItem& other34) {
  key = other34.key;
  value = other34.value;
  deleted = other34.deleted;
  return *this;
}
TTopicItem& TTopicItem::operator=(TTopicItem&& other35) {
  key = std::move(other35.key);
  value = std::move(other35.value);
  deleted = std::move(other35.deleted);
  return *this;
}
void TTopicItem::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "TTopicItem(";
  out << "key=" << to_string(key);
  out << ", " << "value=" << to_string(value);
  out << ", " << "deleted=" << to_string(deleted);
  out << ")";
}


TTopicDelta::~TTopicDelta() throw() {
}


void TTopicDelta::__set_topic_name(const std::string& val) {
  this->topic_name = val;
}

void TTopicDelta::__set_topic_entries(const std::vector<TTopicItem> & val) {
  this->topic_entries = val;
}

void TTopicDelta::__set_is_delta(const bool val) {
  this->is_delta = val;
}

void TTopicDelta::__set_from_version(const int64_t val) {
  this->from_version = val;
__isset.from_version = true;
}

void TTopicDelta::__set_to_version(const int64_t val) {
  this->to_version = val;
__isset.to_version = true;
}

void TTopicDelta::__set_min_subscriber_topic_version(const int64_t val) {
  this->min_subscriber_topic_version = val;
__isset.min_subscriber_topic_version = true;
}

void TTopicDelta::__set_clear_topic_entries(const bool val) {
  this->clear_topic_entries = val;
__isset.clear_topic_entries = true;
}
std::ostream& operator<<(std::ostream& out, const TTopicDelta& obj)
{
  obj.printTo(out);
  return out;
}


void swap(TTopicDelta &a, TTopicDelta &b) {
  using ::std::swap;
  swap(a.topic_name, b.topic_name);
  swap(a.topic_entries, b.topic_entries);
  swap(a.is_delta, b.is_delta);
  swap(a.from_version, b.from_version);
  swap(a.to_version, b.to_version);
  swap(a.min_subscriber_topic_version, b.min_subscriber_topic_version);
  swap(a.clear_topic_entries, b.clear_topic_entries);
  swap(a.__isset, b.__isset);
}

TTopicDelta::TTopicDelta(const TTopicDelta& other42) {
  topic_name = other42.topic_name;
  topic_entries = other42.topic_entries;
  is_delta = other42.is_delta;
  from_version = other42.from_version;
  to_version = other42.to_version;
  min_subscriber_topic_version = other42.min_subscriber_topic_version;
  clear_topic_entries = other42.clear_topic_entries;
  __isset = other42.__isset;
}
TTopicDelta::TTopicDelta( TTopicDelta&& other43) {
  topic_name = std::move(other43.topic_name);
  topic_entries = std::move(other43.topic_entries);
  is_delta = std::move(other43.is_delta);
  from_version = std::move(other43.from_version);
  to_version = std::move(other43.to_version);
  min_subscriber_topic_version = std::move(other43.min_subscriber_topic_version);
  clear_topic_entries = std::move(other43.clear_topic_entries);
  __isset = std::move(other43.__isset);
}
TTopicDelta& TTopicDelta::operator=(const TTopicDelta& other44) {
  topic_name = other44.topic_name;
  topic_entries = other44.topic_entries;
  is_delta = other44.is_delta;
  from_version = other44.from_version;
  to_version = other44.to_version;
  min_subscriber_topic_version = other44.min_subscriber_topic_version;
  clear_topic_entries = other44.clear_topic_entries;
  __isset = other44.__isset;
  return *this;
}
TTopicDelta& TTopicDelta::operator=(TTopicDelta&& other45) {
  topic_name = std::move(other45.topic_name);
  topic_entries = std::move(other45.topic_entries);
  is_delta = std::move(other45.is_delta);
  from_version = std::move(other45.from_version);
  to_version = std::move(other45.to_version);
  min_subscriber_topic_version = std::move(other45.min_subscriber_topic_version);
  clear_topic_entries = std::move(other45.clear_topic_entries);
  __isset = std::move(other45.__isset);
  return *this;
}
void TTopicDelta::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "TTopicDelta(";
  out << "topic_name=" << to_string(topic_name);
  out << ", " << "topic_entries=" << to_string(topic_entries);
  out << ", " << "is_delta=" << to_string(is_delta);
  out << ", " << "from_version="; (__isset.from_version ? (out << to_string(from_version)) : (out << "<null>"));
  out << ", " << "to_version="; (__isset.to_version ? (out << to_string(to_version)) : (out << "<null>"));
  out << ", " << "min_subscriber_topic_version="; (__isset.min_subscriber_topic_version ? (out << to_string(min_subscriber_topic_version)) : (out << "<null>"));
  out << ", " << "clear_topic_entries="; (__isset.clear_topic_entries ? (out << to_string(clear_topic_entries)) : (out << "<null>"));
  out << ")";
}


TTopicRegistration::~TTopicRegistration() throw() {
}


void TTopicRegistration::__set_topic_name(const std::string& val) {
  this->topic_name = val;
}

void TTopicRegistration::__set_is_transient(const bool val) {
  this->is_transient = val;
}

void TTopicRegistration::__set_populate_min_subscriber_topic_version(const bool val) {
  this->populate_min_subscriber_topic_version = val;
}

void TTopicRegistration::__set_filter_prefix(const std::string& val) {
  this->filter_prefix = val;
__isset.filter_prefix = true;
}
std::ostream& operator<<(std::ostream& out, const TTopicRegistration& obj)
{
  obj.printTo(out);
  return out;
}


void swap(TTopicRegistration &a, TTopicRegistration &b) {
  using ::std::swap;
  swap(a.topic_name, b.topic_name);
  swap(a.is_transient, b.is_transient);
  swap(a.populate_min_subscriber_topic_version, b.populate_min_subscriber_topic_version);
  swap(a.filter_prefix, b.filter_prefix);
  swap(a.__isset, b.__isset);
}

TTopicRegistration::TTopicRegistration(const TTopicRegistration& other46) {
  topic_name = other46.topic_name;
  is_transient = other46.is_transient;
  populate_min_subscriber_topic_version = other46.populate_min_subscriber_topic_version;
  filter_prefix = other46.filter_prefix;
  __isset = other46.__isset;
}
TTopicRegistration::TTopicRegistration( TTopicRegistration&& other47) {
  topic_name = std::move(other47.topic_name);
  is_transient = std::move(other47.is_transient);
  populate_min_subscriber_topic_version = std::move(other47.populate_min_subscriber_topic_version);
  filter_prefix = std::move(other47.filter_prefix);
  __isset = std::move(other47.__isset);
}
TTopicRegistration& TTopicRegistration::operator=(const TTopicRegistration& other48) {
  topic_name = other48.topic_name;
  is_transient = other48.is_transient;
  populate_min_subscriber_topic_version = other48.populate_min_subscriber_topic_version;
  filter_prefix = other48.filter_prefix;
  __isset = other48.__isset;
  return *this;
}
TTopicRegistration& TTopicRegistration::operator=(TTopicRegistration&& other49) {
  topic_name = std::move(other49.topic_name);
  is_transient = std::move(other49.is_transient);
  populate_min_subscriber_topic_version = std::move(other49.populate_min_subscriber_topic_version);
  filter_prefix = std::move(other49.filter_prefix);
  __isset = std::move(other49.__isset);
  return *this;
}
void TTopicRegistration::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "TTopicRegistration(";
  out << "topic_name=" << to_string(topic_name);
  out << ", " << "is_transient=" << to_string(is_transient);
  out << ", " << "populate_min_subscriber_topic_version=" << to_string(populate_min_subscriber_topic_version);
  out << ", " << "filter_prefix="; (__isset.filter_prefix ? (out << to_string(filter_prefix)) : (out << "<null>"));
  out << ")";
}


TRegisterSubscriberRequest::~TRegisterSubscriberRequest() throw() {
}


void TRegisterSubscriberRequest::__set_protocol_version(const StatestoreServiceVersion::type val) {
  this->protocol_version = val;
}

void TRegisterSubscriberRequest::__set_subscriber_id(const std::string& val) {
  this->subscriber_id = val;
}

void TRegisterSubscriberRequest::__set_subscriber_location(const  ::impala::TNetworkAddress& val) {
  this->subscriber_location = val;
}

void TRegisterSubscriberRequest::__set_topic_registrations(const std::vector<TTopicRegistration> & val) {
  this->topic_registrations = val;
}
std::ostream& operator<<(std::ostream& out, const TRegisterSubscriberRequest& obj)
{
  obj.printTo(out);
  return out;
}


void swap(TRegisterSubscriberRequest &a, TRegisterSubscriberRequest &b) {
  using ::std::swap;
  swap(a.protocol_version, b.protocol_version);
  swap(a.subscriber_id, b.subscriber_id);
  swap(a.subscriber_location, b.subscriber_location);
  swap(a.topic_registrations, b.topic_registrations);
}

TRegisterSubscriberRequest::TRegisterSubscriberRequest(const TRegisterSubscriberRequest& other57) {
  protocol_version = other57.protocol_version;
  subscriber_id = other57.subscriber_id;
  subscriber_location = other57.subscriber_location;
  topic_registrations = other57.topic_registrations;
}
TRegisterSubscriberRequest::TRegisterSubscriberRequest( TRegisterSubscriberRequest&& other58) {
  protocol_version = std::move(other58.protocol_version);
  subscriber_id = std::move(other58.subscriber_id);
  subscriber_location = std::move(other58.subscriber_location);
  topic_registrations = std::move(other58.topic_registrations);
}
TRegisterSubscriberRequest& TRegisterSubscriberRequest::operator=(const TRegisterSubscriberRequest& other59) {
  protocol_version = other59.protocol_version;
  subscriber_id = other59.subscriber_id;
  subscriber_location = other59.subscriber_location;
  topic_registrations = other59.topic_registrations;
  return *this;
}
TRegisterSubscriberRequest& TRegisterSubscriberRequest::operator=(TRegisterSubscriberRequest&& other60) {
  protocol_version = std::move(other60.protocol_version);
  subscriber_id = std::move(other60.subscriber_id);
  subscriber_location = std::move(other60.subscriber_location);
  topic_registrations = std::move(other60.topic_registrations);
  return *this;
}
void TRegisterSubscriberRequest::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "TRegisterSubscriberRequest(";
  out << "protocol_version=" << to_string(protocol_version);
  out << ", " << "subscriber_id=" << to_string(subscriber_id);
  out << ", " << "subscriber_location=" << to_string(subscriber_location);
  out << ", " << "topic_registrations=" << to_string(topic_registrations);
  out << ")";
}


TRegisterSubscriberResponse::~TRegisterSubscriberResponse() throw() {
}


void TRegisterSubscriberResponse::__set_status(const  ::impala::TStatus& val) {
  this->status = val;
}

void TRegisterSubscriberResponse::__set_registration_id(const  ::impala::TUniqueId& val) {
  this->registration_id = val;
__isset.registration_id = true;
}
std::ostream& operator<<(std::ostream& out, const TRegisterSubscriberResponse& obj)
{
  obj.printTo(out);
  return out;
}


void swap(TRegisterSubscriberResponse &a, TRegisterSubscriberResponse &b) {
  using ::std::swap;
  swap(a.status, b.status);
  swap(a.registration_id, b.registration_id);
  swap(a.__isset, b.__isset);
}

TRegisterSubscriberResponse::TRegisterSubscriberResponse(const TRegisterSubscriberResponse& other61) {
  status = other61.status;
  registration_id = other61.registration_id;
  __isset = other61.__isset;
}
TRegisterSubscriberResponse::TRegisterSubscriberResponse( TRegisterSubscriberResponse&& other62) {
  status = std::move(other62.status);
  registration_id = std::move(other62.registration_id);
  __isset = std::move(other62.__isset);
}
TRegisterSubscriberResponse& TRegisterSubscriberResponse::operator=(const TRegisterSubscriberResponse& other63) {
  status = other63.status;
  registration_id = other63.registration_id;
  __isset = other63.__isset;
  return *this;
}
TRegisterSubscriberResponse& TRegisterSubscriberResponse::operator=(TRegisterSubscriberResponse&& other64) {
  status = std::move(other64.status);
  registration_id = std::move(other64.registration_id);
  __isset = std::move(other64.__isset);
  return *this;
}
void TRegisterSubscriberResponse::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "TRegisterSubscriberResponse(";
  out << "status=" << to_string(status);
  out << ", " << "registration_id="; (__isset.registration_id ? (out << to_string(registration_id)) : (out << "<null>"));
  out << ")";
}


TUpdateStateRequest::~TUpdateStateRequest() throw() {
}


void TUpdateStateRequest::__set_protocol_version(const StatestoreServiceVersion::type val) {
  this->protocol_version = val;
}

void TUpdateStateRequest::__set_topic_deltas(const std::map<std::string, TTopicDelta> & val) {
  this->topic_deltas = val;
}

void TUpdateStateRequest::__set_registration_id(const  ::impala::TUniqueId& val) {
  this->registration_id = val;
__isset.registration_id = true;
}
std::ostream& operator<<(std::ostream& out, const TUpdateStateRequest& obj)
{
  obj.printTo(out);
  return out;
}


void swap(TUpdateStateRequest &a, TUpdateStateRequest &b) {
  using ::std::swap;
  swap(a.protocol_version, b.protocol_version);
  swap(a.topic_deltas, b.topic_deltas);
  swap(a.registration_id, b.registration_id);
  swap(a.__isset, b.__isset);
}

TUpdateStateRequest::TUpdateStateRequest(const TUpdateStateRequest& other74) {
  protocol_version = other74.protocol_version;
  topic_deltas = other74.topic_deltas;
  registration_id = other74.registration_id;
  __isset = other74.__isset;
}
TUpdateStateRequest::TUpdateStateRequest( TUpdateStateRequest&& other75) {
  protocol_version = std::move(other75.protocol_version);
  topic_deltas = std::move(other75.topic_deltas);
  registration_id = std::move(other75.registration_id);
  __isset = std::move(other75.__isset);
}
TUpdateStateRequest& TUpdateStateRequest::operator=(const TUpdateStateRequest& other76) {
  protocol_version = other76.protocol_version;
  topic_deltas = other76.topic_deltas;
  registration_id = other76.registration_id;
  __isset = other76.__isset;
  return *this;
}
TUpdateStateRequest& TUpdateStateRequest::operator=(TUpdateStateRequest&& other77) {
  protocol_version = std::move(other77.protocol_version);
  topic_deltas = std::move(other77.topic_deltas);
  registration_id = std::move(other77.registration_id);
  __isset = std::move(other77.__isset);
  return *this;
}
void TUpdateStateRequest::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "TUpdateStateRequest(";
  out << "protocol_version=" << to_string(protocol_version);
  out << ", " << "topic_deltas=" << to_string(topic_deltas);
  out << ", " << "registration_id="; (__isset.registration_id ? (out << to_string(registration_id)) : (out << "<null>"));
  out << ")";
}


TUpdateStateResponse::~TUpdateStateResponse() throw() {
}


void TUpdateStateResponse::__set_status(const  ::impala::TStatus& val) {
  this->status = val;
}

void TUpdateStateResponse::__set_topic_updates(const std::vector<TTopicDelta> & val) {
  this->topic_updates = val;
}

void TUpdateStateResponse::__set_skipped(const bool val) {
  this->skipped = val;
__isset.skipped = true;
}
std::ostream& operator<<(std::ostream& out, const TUpdateStateResponse& obj)
{
  obj.printTo(out);
  return out;
}


void swap(TUpdateStateResponse &a, TUpdateStateResponse &b) {
  using ::std::swap;
  swap(a.status, b.status);
  swap(a.topic_updates, b.topic_updates);
  swap(a.skipped, b.skipped);
  swap(a.__isset, b.__isset);
}

TUpdateStateResponse::TUpdateStateResponse(const TUpdateStateResponse& other84) {
  status = other84.status;
  topic_updates = other84.topic_updates;
  skipped = other84.skipped;
  __isset = other84.__isset;
}
TUpdateStateResponse::TUpdateStateResponse( TUpdateStateResponse&& other85) {
  status = std::move(other85.status);
  topic_updates = std::move(other85.topic_updates);
  skipped = std::move(other85.skipped);
  __isset = std::move(other85.__isset);
}
TUpdateStateResponse& TUpdateStateResponse::operator=(const TUpdateStateResponse& other86) {
  status = other86.status;
  topic_updates = other86.topic_updates;
  skipped = other86.skipped;
  __isset = other86.__isset;
  return *this;
}
TUpdateStateResponse& TUpdateStateResponse::operator=(TUpdateStateResponse&& other87) {
  status = std::move(other87.status);
  topic_updates = std::move(other87.topic_updates);
  skipped = std::move(other87.skipped);
  __isset = std::move(other87.__isset);
  return *this;
}
void TUpdateStateResponse::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "TUpdateStateResponse(";
  out << "status=" << to_string(status);
  out << ", " << "topic_updates=" << to_string(topic_updates);
  out << ", " << "skipped="; (__isset.skipped ? (out << to_string(skipped)) : (out << "<null>"));
  out << ")";
}


THeartbeatRequest::~THeartbeatRequest() throw() {
}


void THeartbeatRequest::__set_registration_id(const  ::impala::TUniqueId& val) {
  this->registration_id = val;
__isset.registration_id = true;
}
std::ostream& operator<<(std::ostream& out, const THeartbeatRequest& obj)
{
  obj.printTo(out);
  return out;
}


void swap(THeartbeatRequest &a, THeartbeatRequest &b) {
  using ::std::swap;
  swap(a.registration_id, b.registration_id);
  swap(a.__isset, b.__isset);
}

THeartbeatRequest::THeartbeatRequest(const THeartbeatRequest& other88) {
  registration_id = other88.registration_id;
  __isset = other88.__isset;
}
THeartbeatRequest::THeartbeatRequest( THeartbeatRequest&& other89) {
  registration_id = std::move(other89.registration_id);
  __isset = std::move(other89.__isset);
}
THeartbeatRequest& THeartbeatRequest::operator=(const THeartbeatRequest& other90) {
  registration_id = other90.registration_id;
  __isset = other90.__isset;
  return *this;
}
THeartbeatRequest& THeartbeatRequest::operator=(THeartbeatRequest&& other91) {
  registration_id = std::move(other91.registration_id);
  __isset = std::move(other91.__isset);
  return *this;
}
void THeartbeatRequest::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "THeartbeatRequest(";
  out << "registration_id="; (__isset.registration_id ? (out << to_string(registration_id)) : (out << "<null>"));
  out << ")";
}


THeartbeatResponse::~THeartbeatResponse() throw() {
}

std::ostream& operator<<(std::ostream& out, const THeartbeatResponse& obj)
{
  obj.printTo(out);
  return out;
}


void swap(THeartbeatResponse &a, THeartbeatResponse &b) {
  using ::std::swap;
  (void) a;
  (void) b;
}

THeartbeatResponse::THeartbeatResponse(const THeartbeatResponse& other92) {
  (void) other92;
}
THeartbeatResponse::THeartbeatResponse( THeartbeatResponse&& other93) {
  (void) other93;
}
THeartbeatResponse& THeartbeatResponse::operator=(const THeartbeatResponse& other94) {
  (void) other94;
  return *this;
}
THeartbeatResponse& THeartbeatResponse::operator=(THeartbeatResponse&& other95) {
  (void) other95;
  return *this;
}
void THeartbeatResponse::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "THeartbeatResponse(";
  out << ")";
}

} // namespace
