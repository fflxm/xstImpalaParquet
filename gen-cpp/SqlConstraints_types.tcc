/**
 * Autogenerated by Thrift Compiler (0.11.0)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef SqlConstraints_TYPES_TCC
#define SqlConstraints_TYPES_TCC

#include "hive_metastore_types.tcc"
#include "SqlConstraints_types.h"

namespace impala {

template <class Protocol_>
uint32_t TSqlConstraints::read(Protocol_* iprot) {

  ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;

  bool isset_primary_keys = false;
  bool isset_foreign_keys = false;

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
            this->primary_keys.clear();
            uint32_t _size0;
            ::apache::thrift::protocol::TType _etype3;
            xfer += iprot->readListBegin(_etype3, _size0);
            this->primary_keys.resize(_size0);
            uint32_t _i4;
            for (_i4 = 0; _i4 < _size0; ++_i4)
            {
              xfer += this->primary_keys[_i4].read(iprot);
            }
            xfer += iprot->readListEnd();
          }
          isset_primary_keys = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_LIST) {
          {
            this->foreign_keys.clear();
            uint32_t _size5;
            ::apache::thrift::protocol::TType _etype8;
            xfer += iprot->readListBegin(_etype8, _size5);
            this->foreign_keys.resize(_size5);
            uint32_t _i9;
            for (_i9 = 0; _i9 < _size5; ++_i9)
            {
              xfer += this->foreign_keys[_i9].read(iprot);
            }
            xfer += iprot->readListEnd();
          }
          isset_foreign_keys = true;
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

  if (!isset_primary_keys)
    throw TProtocolException(TProtocolException::INVALID_DATA);
  if (!isset_foreign_keys)
    throw TProtocolException(TProtocolException::INVALID_DATA);
  return xfer;
}

template <class Protocol_>
uint32_t TSqlConstraints::write(Protocol_* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("TSqlConstraints");

  xfer += oprot->writeFieldBegin("primary_keys", ::apache::thrift::protocol::T_LIST, 1);
  {
    xfer += oprot->writeListBegin(::apache::thrift::protocol::T_STRUCT, static_cast<uint32_t>(this->primary_keys.size()));
    std::vector< ::Apache::Hadoop::Hive::SQLPrimaryKey> ::const_iterator _iter10;
    for (_iter10 = this->primary_keys.begin(); _iter10 != this->primary_keys.end(); ++_iter10)
    {
      xfer += (*_iter10).write(oprot);
    }
    xfer += oprot->writeListEnd();
  }
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("foreign_keys", ::apache::thrift::protocol::T_LIST, 2);
  {
    xfer += oprot->writeListBegin(::apache::thrift::protocol::T_STRUCT, static_cast<uint32_t>(this->foreign_keys.size()));
    std::vector< ::Apache::Hadoop::Hive::SQLForeignKey> ::const_iterator _iter11;
    for (_iter11 = this->foreign_keys.begin(); _iter11 != this->foreign_keys.end(); ++_iter11)
    {
      xfer += (*_iter11).write(oprot);
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