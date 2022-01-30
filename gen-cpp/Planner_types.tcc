/**
 * Autogenerated by Thrift Compiler (0.11.0)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef Planner_TYPES_TCC
#define Planner_TYPES_TCC

#include "Types_types.tcc"
#include "Exprs_types.tcc"
#include "DataSinks_types.tcc"
#include "PlanNodes_types.tcc"
#include "Partitions_types.tcc"
#include "Planner_types.h"

namespace impala {

template <class Protocol_>
uint32_t TPlanFragment::read(Protocol_* iprot) {

  ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;

  bool isset_idx = false;
  bool isset_display_name = false;
  bool isset_partition = false;

  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->idx);
          isset_idx = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->display_name);
          isset_display_name = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_STRUCT) {
          xfer += this->plan.read(iprot);
          this->__isset.plan = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 5:
        if (ftype == ::apache::thrift::protocol::T_STRUCT) {
          xfer += this->output_sink.read(iprot);
          this->__isset.output_sink = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 6:
        if (ftype == ::apache::thrift::protocol::T_STRUCT) {
          xfer += this->partition.read(iprot);
          isset_partition = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 7:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->backend_min_mem_reservation_bytes);
          this->__isset.backend_min_mem_reservation_bytes = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 12:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->instance_min_mem_reservation_bytes);
          this->__isset.instance_min_mem_reservation_bytes = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 8:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->instance_initial_mem_reservation_total_claims);
          this->__isset.instance_initial_mem_reservation_total_claims = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 13:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->backend_initial_mem_reservation_total_claims);
          this->__isset.backend_initial_mem_reservation_total_claims = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 9:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->produced_runtime_filters_reservation_bytes);
          this->__isset.produced_runtime_filters_reservation_bytes = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 11:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->consumed_runtime_filters_reservation_bytes);
          this->__isset.consumed_runtime_filters_reservation_bytes = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 10:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->thread_reservation);
          this->__isset.thread_reservation = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  if (!isset_idx)
    throw TProtocolException(TProtocolException::INVALID_DATA);
  if (!isset_display_name)
    throw TProtocolException(TProtocolException::INVALID_DATA);
  if (!isset_partition)
    throw TProtocolException(TProtocolException::INVALID_DATA);
  return xfer;
}

template <class Protocol_>
uint32_t TPlanFragment::write(Protocol_* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("TPlanFragment");

  xfer += oprot->writeFieldBegin("idx", ::apache::thrift::protocol::T_I32, 1);
  xfer += oprot->writeI32(this->idx);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("display_name", ::apache::thrift::protocol::T_STRING, 2);
  xfer += oprot->writeString(this->display_name);
  xfer += oprot->writeFieldEnd();

  if (this->__isset.plan) {
    xfer += oprot->writeFieldBegin("plan", ::apache::thrift::protocol::T_STRUCT, 3);
    xfer += this->plan.write(oprot);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.output_sink) {
    xfer += oprot->writeFieldBegin("output_sink", ::apache::thrift::protocol::T_STRUCT, 5);
    xfer += this->output_sink.write(oprot);
    xfer += oprot->writeFieldEnd();
  }
  xfer += oprot->writeFieldBegin("partition", ::apache::thrift::protocol::T_STRUCT, 6);
  xfer += this->partition.write(oprot);
  xfer += oprot->writeFieldEnd();

  if (this->__isset.backend_min_mem_reservation_bytes) {
    xfer += oprot->writeFieldBegin("backend_min_mem_reservation_bytes", ::apache::thrift::protocol::T_I64, 7);
    xfer += oprot->writeI64(this->backend_min_mem_reservation_bytes);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.instance_initial_mem_reservation_total_claims) {
    xfer += oprot->writeFieldBegin("instance_initial_mem_reservation_total_claims", ::apache::thrift::protocol::T_I64, 8);
    xfer += oprot->writeI64(this->instance_initial_mem_reservation_total_claims);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.produced_runtime_filters_reservation_bytes) {
    xfer += oprot->writeFieldBegin("produced_runtime_filters_reservation_bytes", ::apache::thrift::protocol::T_I64, 9);
    xfer += oprot->writeI64(this->produced_runtime_filters_reservation_bytes);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.thread_reservation) {
    xfer += oprot->writeFieldBegin("thread_reservation", ::apache::thrift::protocol::T_I64, 10);
    xfer += oprot->writeI64(this->thread_reservation);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.consumed_runtime_filters_reservation_bytes) {
    xfer += oprot->writeFieldBegin("consumed_runtime_filters_reservation_bytes", ::apache::thrift::protocol::T_I64, 11);
    xfer += oprot->writeI64(this->consumed_runtime_filters_reservation_bytes);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.instance_min_mem_reservation_bytes) {
    xfer += oprot->writeFieldBegin("instance_min_mem_reservation_bytes", ::apache::thrift::protocol::T_I64, 12);
    xfer += oprot->writeI64(this->instance_min_mem_reservation_bytes);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.backend_initial_mem_reservation_total_claims) {
    xfer += oprot->writeFieldBegin("backend_initial_mem_reservation_total_claims", ::apache::thrift::protocol::T_I64, 13);
    xfer += oprot->writeI64(this->backend_initial_mem_reservation_total_claims);
    xfer += oprot->writeFieldEnd();
  }
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

template <class Protocol_>
uint32_t TScanRangeLocation::read(Protocol_* iprot) {

  ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;

  bool isset_host_idx = false;

  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->host_idx);
          isset_host_idx = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->volume_id);
          this->__isset.volume_id = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_BOOL) {
          xfer += iprot->readBool(this->is_cached);
          this->__isset.is_cached = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  if (!isset_host_idx)
    throw TProtocolException(TProtocolException::INVALID_DATA);
  return xfer;
}

template <class Protocol_>
uint32_t TScanRangeLocation::write(Protocol_* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("TScanRangeLocation");

  xfer += oprot->writeFieldBegin("host_idx", ::apache::thrift::protocol::T_I32, 1);
  xfer += oprot->writeI32(this->host_idx);
  xfer += oprot->writeFieldEnd();

  if (this->__isset.volume_id) {
    xfer += oprot->writeFieldBegin("volume_id", ::apache::thrift::protocol::T_I32, 2);
    xfer += oprot->writeI32(this->volume_id);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.is_cached) {
    xfer += oprot->writeFieldBegin("is_cached", ::apache::thrift::protocol::T_BOOL, 3);
    xfer += oprot->writeBool(this->is_cached);
    xfer += oprot->writeFieldEnd();
  }
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

template <class Protocol_>
uint32_t TScanRangeLocationList::read(Protocol_* iprot) {

  ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;

  bool isset_scan_range = false;

  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_STRUCT) {
          xfer += this->scan_range.read(iprot);
          isset_scan_range = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_LIST) {
          {
            this->locations.clear();
            uint32_t _size8;
            ::apache::thrift::protocol::TType _etype11;
            xfer += iprot->readListBegin(_etype11, _size8);
            this->locations.resize(_size8);
            uint32_t _i12;
            for (_i12 = 0; _i12 < _size8; ++_i12)
            {
              xfer += this->locations[_i12].read(iprot);
            }
            xfer += iprot->readListEnd();
          }
          this->__isset.locations = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  if (!isset_scan_range)
    throw TProtocolException(TProtocolException::INVALID_DATA);
  return xfer;
}

template <class Protocol_>
uint32_t TScanRangeLocationList::write(Protocol_* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("TScanRangeLocationList");

  xfer += oprot->writeFieldBegin("scan_range", ::apache::thrift::protocol::T_STRUCT, 1);
  xfer += this->scan_range.write(oprot);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("locations", ::apache::thrift::protocol::T_LIST, 2);
  {
    xfer += oprot->writeListBegin(::apache::thrift::protocol::T_STRUCT, static_cast<uint32_t>(this->locations.size()));
    std::vector<TScanRangeLocation> ::const_iterator _iter13;
    for (_iter13 = this->locations.begin(); _iter13 != this->locations.end(); ++_iter13)
    {
      xfer += (*_iter13).write(oprot);
    }
    xfer += oprot->writeListEnd();
  }
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

template <class Protocol_>
uint32_t TScanRangeSpec::read(Protocol_* iprot) {

  ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_LIST) {
          {
            this->concrete_ranges.clear();
            uint32_t _size18;
            ::apache::thrift::protocol::TType _etype21;
            xfer += iprot->readListBegin(_etype21, _size18);
            this->concrete_ranges.resize(_size18);
            uint32_t _i22;
            for (_i22 = 0; _i22 < _size18; ++_i22)
            {
              xfer += this->concrete_ranges[_i22].read(iprot);
            }
            xfer += iprot->readListEnd();
          }
          this->__isset.concrete_ranges = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_LIST) {
          {
            this->split_specs.clear();
            uint32_t _size23;
            ::apache::thrift::protocol::TType _etype26;
            xfer += iprot->readListBegin(_etype26, _size23);
            this->split_specs.resize(_size23);
            uint32_t _i27;
            for (_i27 = 0; _i27 < _size23; ++_i27)
            {
              xfer += this->split_specs[_i27].read(iprot);
            }
            xfer += iprot->readListEnd();
          }
          this->__isset.split_specs = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

template <class Protocol_>
uint32_t TScanRangeSpec::write(Protocol_* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("TScanRangeSpec");

  if (this->__isset.concrete_ranges) {
    xfer += oprot->writeFieldBegin("concrete_ranges", ::apache::thrift::protocol::T_LIST, 1);
    {
      xfer += oprot->writeListBegin(::apache::thrift::protocol::T_STRUCT, static_cast<uint32_t>(this->concrete_ranges.size()));
      std::vector<TScanRangeLocationList> ::const_iterator _iter28;
      for (_iter28 = this->concrete_ranges.begin(); _iter28 != this->concrete_ranges.end(); ++_iter28)
      {
        xfer += (*_iter28).write(oprot);
      }
      xfer += oprot->writeListEnd();
    }
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.split_specs) {
    xfer += oprot->writeFieldBegin("split_specs", ::apache::thrift::protocol::T_LIST, 2);
    {
      xfer += oprot->writeListBegin(::apache::thrift::protocol::T_STRUCT, static_cast<uint32_t>(this->split_specs.size()));
      std::vector< ::impala::TFileSplitGeneratorSpec> ::const_iterator _iter29;
      for (_iter29 = this->split_specs.begin(); _iter29 != this->split_specs.end(); ++_iter29)
      {
        xfer += (*_iter29).write(oprot);
      }
      xfer += oprot->writeListEnd();
    }
    xfer += oprot->writeFieldEnd();
  }
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

template <class Protocol_>
uint32_t TPlanFragmentTree::read(Protocol_* iprot) {

  ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;

  bool isset_cohort_id = false;
  bool isset_fragments = false;

  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->cohort_id);
          isset_cohort_id = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_LIST) {
          {
            this->fragments.clear();
            uint32_t _size34;
            ::apache::thrift::protocol::TType _etype37;
            xfer += iprot->readListBegin(_etype37, _size34);
            this->fragments.resize(_size34);
            uint32_t _i38;
            for (_i38 = 0; _i38 < _size34; ++_i38)
            {
              xfer += this->fragments[_i38].read(iprot);
            }
            xfer += iprot->readListEnd();
          }
          isset_fragments = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  if (!isset_cohort_id)
    throw TProtocolException(TProtocolException::INVALID_DATA);
  if (!isset_fragments)
    throw TProtocolException(TProtocolException::INVALID_DATA);
  return xfer;
}

template <class Protocol_>
uint32_t TPlanFragmentTree::write(Protocol_* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("TPlanFragmentTree");

  xfer += oprot->writeFieldBegin("cohort_id", ::apache::thrift::protocol::T_I32, 1);
  xfer += oprot->writeI32(this->cohort_id);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("fragments", ::apache::thrift::protocol::T_LIST, 2);
  {
    xfer += oprot->writeListBegin(::apache::thrift::protocol::T_STRUCT, static_cast<uint32_t>(this->fragments.size()));
    std::vector<TPlanFragment> ::const_iterator _iter39;
    for (_iter39 = this->fragments.begin(); _iter39 != this->fragments.end(); ++_iter39)
    {
      xfer += (*_iter39).write(oprot);
    }
    xfer += oprot->writeListEnd();
  }
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

} // namespace

#endif