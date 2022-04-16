/**
 * Autogenerated by Thrift Compiler (0.11.0)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef SqlConstraints_TYPES_H
#define SqlConstraints_TYPES_H

#include <iosfwd>

#include <thrift/Thrift.h>
#include <thrift/TApplicationException.h>
#include <thrift/TBase.h>
#include <thrift/protocol/TProtocol.h>
#include <thrift/transport/TTransport.h>

#include <thrift/stdcxx.h>
#include "hive_metastore_types.h"


namespace impala {

class TSqlConstraints;


class TSqlConstraints {
 public:

  TSqlConstraints(const TSqlConstraints&);
  TSqlConstraints(TSqlConstraints&&);
  TSqlConstraints& operator=(const TSqlConstraints&);
  TSqlConstraints& operator=(TSqlConstraints&&);
  TSqlConstraints() {
  }

  virtual ~TSqlConstraints() throw();
  std::vector< ::Apache::Hadoop::Hive::SQLPrimaryKey>  primary_keys;
  std::vector< ::Apache::Hadoop::Hive::SQLForeignKey>  foreign_keys;

  void __set_primary_keys(const std::vector< ::Apache::Hadoop::Hive::SQLPrimaryKey> & val);

  void __set_foreign_keys(const std::vector< ::Apache::Hadoop::Hive::SQLForeignKey> & val);

  template <class Protocol_>
  uint32_t read(Protocol_* iprot);
  template <class Protocol_>
  uint32_t write(Protocol_* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(TSqlConstraints &a, TSqlConstraints &b);

std::ostream& operator<<(std::ostream& out, const TSqlConstraints& obj);

} // namespace

#include "SqlConstraints_types.tcc"

#endif
