/**
 * Autogenerated by Thrift Compiler (0.11.0)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#include "Metrics_types.h"

#include <algorithm>
#include <ostream>

#include <thrift/TToString.h>

namespace impala {

int _kTUnitValues[] = {
  TUnit::UNIT,
  TUnit::UNIT_PER_SECOND,
  TUnit::CPU_TICKS,
  TUnit::BYTES,
  TUnit::BYTES_PER_SECOND,
  TUnit::TIME_NS,
  TUnit::DOUBLE_VALUE,
  TUnit::NONE,
  TUnit::TIME_MS,
  TUnit::TIME_S,
  TUnit::TIME_US,
  TUnit::BASIS_POINTS
};
const char* _kTUnitNames[] = {
  "UNIT",
  "UNIT_PER_SECOND",
  "CPU_TICKS",
  "BYTES",
  "BYTES_PER_SECOND",
  "TIME_NS",
  "DOUBLE_VALUE",
  "NONE",
  "TIME_MS",
  "TIME_S",
  "TIME_US",
  "BASIS_POINTS"
};
const std::map<int, const char*> _TUnit_VALUES_TO_NAMES(::apache::thrift::TEnumIterator(12, _kTUnitValues, _kTUnitNames), ::apache::thrift::TEnumIterator(-1, NULL, NULL));

std::ostream& operator<<(std::ostream& out, const TUnit::type& val) {
  std::map<int, const char*>::const_iterator it = _TUnit_VALUES_TO_NAMES.find(val);
  if (it != _TUnit_VALUES_TO_NAMES.end()) {
    out << it->second;
  } else {
    out << static_cast<int>(val);
  }
  return out;
}

int _kTMetricKindValues[] = {
  TMetricKind::GAUGE,
  TMetricKind::COUNTER,
  TMetricKind::PROPERTY,
  TMetricKind::STATS,
  TMetricKind::SET,
  TMetricKind::HISTOGRAM
};
const char* _kTMetricKindNames[] = {
  "GAUGE",
  "COUNTER",
  "PROPERTY",
  "STATS",
  "SET",
  "HISTOGRAM"
};
const std::map<int, const char*> _TMetricKind_VALUES_TO_NAMES(::apache::thrift::TEnumIterator(6, _kTMetricKindValues, _kTMetricKindNames), ::apache::thrift::TEnumIterator(-1, NULL, NULL));

std::ostream& operator<<(std::ostream& out, const TMetricKind::type& val) {
  std::map<int, const char*>::const_iterator it = _TMetricKind_VALUES_TO_NAMES.find(val);
  if (it != _TMetricKind_VALUES_TO_NAMES.end()) {
    out << it->second;
  } else {
    out << static_cast<int>(val);
  }
  return out;
}

} // namespace
