/**
 * Autogenerated by Thrift Compiler (0.11.0)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef CatalogObjects_CONSTANTS_H
#define CatalogObjects_CONSTANTS_H

#include "CatalogObjects_types.h"

namespace impala {

class CatalogObjectsConstants {
 public:
  CatalogObjectsConstants();

  std::map<std::string, THdfsCompression::type>  COMPRESSION_MAP;
  int64_t PROTOTYPE_PARTITION_ID;
};

extern const CatalogObjectsConstants g_CatalogObjects_constants;

} // namespace

#endif