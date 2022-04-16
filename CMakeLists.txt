# Licensed to the Apache Software Foundation (ASF) under one
# or more contributor license agreements.  See the NOTICE file
# distributed with this work for additional information
# regarding copyright ownership.  The ASF licenses this file
# to you under the Apache License, Version 2.0 (the
# "License"); you may not use this file except in compliance
# with the License.  You may obtain a copy of the License at
#
#   http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing,
# software distributed under the License is distributed on an
# "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
# KIND, either express or implied.  See the License for the
# specific language governing permissions and limitations
# under the License.

cmake_minimum_required(VERSION 2.6)
PROJECT(TESTPARQUET)

set(SOURCE_DIR "/home/ff/Impala")

set(UTIL_SRC_DIR "${SOURCE_DIR}/be/src/util")
set(EXEC_SRC_DIR "${SOURCE_DIR}/be/src/exec")
set(UDF_SRC_DIR "${SOURCE_DIR}/be/src/udf")
set(RUNTIME_SRC_DIR "${SOURCE_DIR}/be/src/runtime")
set(BUFF_SRC_DIR "${SOURCE_DIR}/be/src/runtime/bufferpool")
set(TESTUTIL_SRC_DIR "${SOURCE_DIR}/be/src/testutil")
set(COMMON_SRC_DIR "${SOURCE_DIR}/be/src/common")
set(IO_SRC_DIR "${SOURCE_DIR}/be/src/runtime/io")
set(GUTIL_SRC_DIR "${SOURCE_DIR}/be/src/gutil")
set(EXPRS_SRC_DIR "${SOURCE_DIR}/be/src/exprs")
set(RPC_SRC_DIR "${SOURCE_DIR}/be/src/rpc")
set(THRIFT_SRC_DIR "${SOURCE_DIR}/be/generated-sources/gen-cpp")
set(Toolchain_SRC_DIR "${SOURCE_DIR}/toolchain/toolchain-packages-gcc7.5.0")

set(BUILD_OUTPUT_ROOT_DIRECTORY "${SOURCE_DIR}/be/build/debug/")
# where to put generated libraries
set(LIBRARY_OUTPUT_PATH "${BUILD_OUTPUT_ROOT_DIRECTORY}/testparquet")

# where to put generated binaries
set(EXECUTABLE_OUTPUT_PATH "${BUILD_OUTPUT_ROOT_DIRECTORY}/testparquet")

include_directories(${SOURCE_DIR}/be/src)
include_directories(${SOURCE_DIR}/be/generated-sources)

set(GLog_INCLUDE_DIRS "${Toolchain_SRC_DIR}/glog-0.3.5-p3/include")
set(GFlags_INCLUDE_DIRS "${Toolchain_SRC_DIR}/gflags-2.2.0-p2/include")
set(Thrift_INCLUDE_DIRS "${Toolchain_SRC_DIR}/thrift-0.11.0-p4/include")
set(Boost_INCLUDE_DIRS "${Toolchain_SRC_DIR}/boost-1.74.0-p1/include")
set(Rapidjson_INCLUDE_DIRS "${Toolchain_SRC_DIR}/rapidjson-1.1.0/include")
set(Llvm_INCLUDE_DIRS "${Toolchain_SRC_DIR}/llvm-5.0.1-p3/include")
set(Protobuf_INCLUDE_DIRS "${Toolchain_SRC_DIR}/protobuf-3.14.0/include")
set(Hadoop_INCLUDE_DIRS "/home/ff/Impala/toolchain/cdp_components-18462549/hadoop-3.1.1.7.2.14.0-21/include")
set(Cctz_INCLUDE_DIRS "${Toolchain_SRC_DIR}/cctz-2.2/include")
set(Flatbuffers_INCLUDE_DIRS "${Toolchain_SRC_DIR}/flatbuffers-1.6.0/include")
set(Re_INCLUDE_DIRS "${Toolchain_SRC_DIR}/re2-20190301/include")
set(Gperftools_INCLUDE_DIRS "${Toolchain_SRC_DIR}/gperftools-2.5-p4/include")
set(Zlib_INCLUDE_DIRS "${Toolchain_SRC_DIR}/zlib-1.2.11/include")
set(Zstd_INCLUDE_DIRS "${Toolchain_SRC_DIR}/zstd-1.4.9/include")
set(Bzlib_INCLUDE_DIRS "${Toolchain_SRC_DIR}/bzip2-1.0.8-p2/include")
set(Lz4_INCLUDE_DIRS "${Toolchain_SRC_DIR}/lz4-1.9.3/include")
set(Snappy_INCLUDE_DIRS "${Toolchain_SRC_DIR}/snappy-1.1.8/include")
include_directories(SYSTEM ${Boost_INCLUDE_DIRS} ${GFlags_INCLUDE_DIRS} ${GLog_INCLUDE_DIRS} ${Thrift_INCLUDE_DIRS} ${Rapidjson_INCLUDE_DIRS} ${Protobuf_INCLUDE_DIRS} ${Hadoop_INCLUDE_DIRS} ${Cctz_INCLUDE_DIRS} ${JAVA_INCLUDE_PATH} ${Llvm_INCLUDE_DIRS} ${Zlib_INCLUDE_DIRS} ${Zstd_INCLUDE_DIRS} ${Gperftools_INCLUDE_DIRS} ${Flatbuffers_INCLUDE_DIRS} ${Re_INCLUDE_DIRS} ${Bzlib_INCLUDE_DIRS} ${Lz4_INCLUDE_DIRS} ${Snappy_INCLUDE_DIRS})

SET(CXX_COMMON_FLAGS "${CXX_COMMON_FLAGS} -Wall -Wno-sign-compare -Wno-unknown-pragmas -pthread")
SET(CXX_COMMON_FLAGS "${CXX_COMMON_FLAGS} -fno-strict-aliasing -fno-omit-frame-pointer")
SET(CXX_COMMON_FLAGS "${CXX_COMMON_FLAGS} -fsigned-char")
SET(CXX_COMMON_FLAGS "${CXX_COMMON_FLAGS} -std=c++14")
SET(CXX_COMMON_FLAGS "${CXX_COMMON_FLAGS} -Wno-deprecated -Wno-vla")
SET(CXX_COMMON_FLAGS "${CXX_COMMON_FLAGS} -DBOOST_DATE_TIME_POSIX_TIME_STD_CONFIG")
SET(CXX_COMMON_FLAGS "${CXX_COMMON_FLAGS} -DBOOST_SYSTEM_NO_DEPRECATED")
SET(CXX_COMMON_FLAGS "${CXX_COMMON_FLAGS} -DBOOST_BIND_GLOBAL_PLACEHOLDERS")
SET(CXX_COMMON_FLAGS "${CXX_COMMON_FLAGS} -DBOOST_ALLOW_DEPRECATED_HEADERS")

SET(CXX_CLANG_FLAGS "-Qunused-arguments -fcolor-diagnostics -Wno-unused-local-typedef")
SET(CXX_CLANG_FLAGS "${CXX_CLANG_FLAGS} -fsigned-char")
SET(CXX_CLANG_FLAGS "${CXX_CLANG_FLAGS} -Wno-zero-as-null-pointer-constant")
SET(CXX_CLANG_FLAGS "${CXX_CLANG_FLAGS} -Wno-c++17-extensions")
SET(CXX_CLANG_FLAGS "${CXX_CLANG_FLAGS} -Wno-inconsistent-missing-destructor-override")
SET(CXX_CLANG_FLAGS "${CXX_CLANG_FLAGS} -Wno-return-type-c-linkage")
SET(CXX_CLANG_FLAGS "${CXX_CLANG_FLAGS} -DCALLONCEHACK")

SET(CXX_GCC_FLAGS "-g -Wno-unused-local-typedefs -gdwarf-4 -Wno-maybe-uninitialized")
SET(CXX_GCC_FLAGS "${CXX_GCC_FLAGS} -faligned-new")
#SET(CXX_COMMON_FLAGS "${CXX_COMMON_FLAGS} -Wall -Wno-sign-compare -Wno-unknown-pragmas -pthread -DLLVM_DISABLE_ABI_BREAKING_CHECK_ENFORCING=1")

SET(CMAKE_CXX_FLAGS "${CXX_COMMON_FLAGS} ${CXX_COMMON_FLAGS} ${CMAKE_CXX_FLAGS}")
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fverbose-asm")
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${CXX_GCC_FLAGS}")

add_library(BufferPoolParquet
  ${BUFF_SRC_DIR}/buffer-allocator.cc
  ${BUFF_SRC_DIR}/buffer-pool.cc
  ${BUFF_SRC_DIR}/reservation-tracker.cc
  ${BUFF_SRC_DIR}/reservation-util.cc
  ${BUFF_SRC_DIR}/suballocator.cc
  ${BUFF_SRC_DIR}/system-allocator.cc
)
add_dependencies(BufferPoolParquet RuntimeParquet)

add_library(GlobalFlagsParquet
  ${COMMON_SRC_DIR}/global-flags.cc
)

add_library(RpcParquet
  ${RPC_SRC_DIR}/thrift-util.cc
)

add_library(GUtilParquet
  ${GUTIL_SRC_DIR}/strings/ascii_ctype.cc
  ${GUTIL_SRC_DIR}/strings/charset.cc
  ${GUTIL_SRC_DIR}/strings/escaping.cc
  ${GUTIL_SRC_DIR}/strings/human_readable.cc
  ${GUTIL_SRC_DIR}/strings/join.cc
  ${GUTIL_SRC_DIR}/strings/memutil.cc
  ${GUTIL_SRC_DIR}/strings/numbers.cc
  ${GUTIL_SRC_DIR}/strings/serialize.cc
  ${GUTIL_SRC_DIR}/strings/split.cc
  ${GUTIL_SRC_DIR}/strings/strcat.cc
  ${GUTIL_SRC_DIR}/strings/stringpiece.cc
  ${GUTIL_SRC_DIR}/strings/strip.cc
  ${GUTIL_SRC_DIR}/strings/substitute.cc
  ${GUTIL_SRC_DIR}/strings/util.cc
  ${GUTIL_SRC_DIR}/stringprintf.cc
  ${GUTIL_SRC_DIR}/strtoint.cc
  ${GUTIL_SRC_DIR}/spinlock.cc
  ${GUTIL_SRC_DIR}/spinlock_internal.cc
  ${GUTIL_SRC_DIR}/threading/thread_collision_warner.cc
  ${GUTIL_SRC_DIR}/sysinfo.cc
  ${GUTIL_SRC_DIR}/once.cc
  ${GUTIL_SRC_DIR}/hash/jenkins.cc
  ${GUTIL_SRC_DIR}/utf/rune.c
)

add_library(ExprsParquet 
  ${EXPRS_SRC_DIR}/timestamp-functions.cc
  ${EXPRS_SRC_DIR}/anyval-util.cc
  ${EXPRS_SRC_DIR}/scalar-expr.cc
  ${EXPRS_SRC_DIR}/scalar-expr-evaluator.cc
  ${EXPRS_SRC_DIR}/expr.cc
)
add_dependencies(ExprsParquet UdfParquet)

add_library(UdfParquet 
  ${UDF_SRC_DIR}/udf.cc
  ${UDF_SRC_DIR}/udf-ir.cc
)

add_library(ImpalaThriftParquet 
  ${THRIFT_SRC_DIR}/Data_types.cpp
  ${THRIFT_SRC_DIR}/Descriptors_types.cpp
  ${THRIFT_SRC_DIR}/ErrorCodes_types.cpp
  ${THRIFT_SRC_DIR}/ExecStats_types.cpp
  ${THRIFT_SRC_DIR}/Exprs_types.cpp
  ${THRIFT_SRC_DIR}/Metrics_types.cpp
  ${THRIFT_SRC_DIR}/MetricDefs_types.cpp
  ${THRIFT_SRC_DIR}/PlanNodes_types.cpp
  ${THRIFT_SRC_DIR}/Results_types.cpp
  ${THRIFT_SRC_DIR}/Partitions_types.cpp
  ${THRIFT_SRC_DIR}/Planner_types.cpp
  ${THRIFT_SRC_DIR}/parquet_types.cpp
  ${THRIFT_SRC_DIR}/ResourceProfile_types.cpp
  ${THRIFT_SRC_DIR}/RuntimeProfile_types.cpp
  ${THRIFT_SRC_DIR}/Status_types.cpp
  ${THRIFT_SRC_DIR}/Types_types.cpp
  ${THRIFT_SRC_DIR}/control_service.pb.cc
  ${THRIFT_SRC_DIR}/CatalogObjects_types.cpp
  ${THRIFT_SRC_DIR}/DataSinks_types.cpp
  ${THRIFT_SRC_DIR}/common.pb.cc
  ${THRIFT_SRC_DIR}/SqlConstraints_types.cpp
  ${THRIFT_SRC_DIR}/planner.pb.cc
  ${THRIFT_SRC_DIR}/ExternalDataSource_types.cpp
  ${THRIFT_SRC_DIR}/Query_types.cpp
  ${THRIFT_SRC_DIR}/LineageGraph_types.cpp
  ${THRIFT_SRC_DIR}/ImpalaInternalService_types.cpp
  ${THRIFT_SRC_DIR}/ErrorCodes_constants.cpp
  ${THRIFT_SRC_DIR}/Frontend_types.cpp
  ${THRIFT_SRC_DIR}/TCLIService_types.cpp
  ${THRIFT_SRC_DIR}/JniCatalog_types.cpp
  ${THRIFT_SRC_DIR}/CatalogService_types.cpp
  ${THRIFT_SRC_DIR}/CatalogObjects_constants.cpp
  ${THRIFT_SRC_DIR}/hive_metastore_types.cpp
  ${THRIFT_SRC_DIR}/MetricDefs_constants.cpp
  ${THRIFT_SRC_DIR}/row_batch.pb.cc
  ${THRIFT_SRC_DIR}/data_stream_service.pb.cc
  ${THRIFT_SRC_DIR}/StatestoreService_types.cpp
)

add_library(IoParquet
  ${IO_SRC_DIR}/disk-io-mgr.cc
  ${IO_SRC_DIR}/disk-io-mgr-stress.cc
  ${IO_SRC_DIR}/disk-file.cc
  ${IO_SRC_DIR}/local-file-system.cc
  ${IO_SRC_DIR}/local-file-system-with-fault-injection.cc
  ${IO_SRC_DIR}/error-converter.cc
  ${IO_SRC_DIR}/request-context.cc
  ${IO_SRC_DIR}/scan-range.cc
  ${IO_SRC_DIR}/scan-buffer-manager.cc
  ${IO_SRC_DIR}/local-file-reader.cc
  ${IO_SRC_DIR}/local-file-writer.cc
)

add_library(ExecParquet
  ${EXEC_SRC_DIR}/exec-node.cc
  ${EXEC_SRC_DIR}/hdfs-columnar-scanner.cc
  ${EXEC_SRC_DIR}/hdfs-scan-node-base.cc
  ${EXEC_SRC_DIR}/hdfs-scan-node.cc
  ${EXEC_SRC_DIR}/hdfs-scanner.cc
  ${EXEC_SRC_DIR}/hdfs-scanner-ir.cc
  ${EXEC_SRC_DIR}/scanner-context.cc
  ${EXEC_SRC_DIR}/scan-node.cc
  ${EXEC_SRC_DIR}/file-metadata-utils.cc
  ${EXEC_SRC_DIR}/filter-context.cc
  ${EXEC_SRC_DIR}/text-converter.cc
)
add_dependencies(ExecParquet PParquet)

add_library(CommonParquet
  ${COMMON_SRC_DIR}/init.cc
  ${COMMON_SRC_DIR}/logging.cc
  ${COMMON_SRC_DIR}/status.cc
  ${COMMON_SRC_DIR}/thread-debug-info.cc
)
add_dependencies(CommonParquet UtilParquet)

add_library(RuntimeParquet
  ${RUNTIME_SRC_DIR}/blocking-row-batch-queue.cc
  ${RUNTIME_SRC_DIR}/buffered-tuple-stream.cc
  ${RUNTIME_SRC_DIR}/collection-value.cc
  ${RUNTIME_SRC_DIR}/debug-options.cc
  ${RUNTIME_SRC_DIR}/descriptors.cc
  ${RUNTIME_SRC_DIR}/exec-env.cc
  ${RUNTIME_SRC_DIR}/fragment-state.cc
  ${RUNTIME_SRC_DIR}/fragment-instance-state.cc
  ${RUNTIME_SRC_DIR}/initial-reservations.cc
  ${RUNTIME_SRC_DIR}/mem-tracker.cc
  ${RUNTIME_SRC_DIR}/mem-pool.cc
  ${RUNTIME_SRC_DIR}/test-env.cc
  ${RUNTIME_SRC_DIR}/types.cc
  ${RUNTIME_SRC_DIR}/raw-value.cc
  ${RUNTIME_SRC_DIR}/raw-value-ir.cc
  ${RUNTIME_SRC_DIR}/reservation-manager.cc
  ${RUNTIME_SRC_DIR}/row-batch.cc
  ${RUNTIME_SRC_DIR}/runtime-filter.cc
  ${RUNTIME_SRC_DIR}/runtime-filter-bank.cc
  ${RUNTIME_SRC_DIR}/runtime-filter-ir.cc
  ${RUNTIME_SRC_DIR}/runtime-state.cc
  ${RUNTIME_SRC_DIR}/scanner-mem-limiter.cc
  ${RUNTIME_SRC_DIR}/sorted-run-merger.cc
  ${RUNTIME_SRC_DIR}/sorter.cc
  ${RUNTIME_SRC_DIR}/sorter-ir.cc
  ${RUNTIME_SRC_DIR}/spillable-row-batch-queue.cc
  ${RUNTIME_SRC_DIR}/string-value.cc
  ${RUNTIME_SRC_DIR}/thread-resource-mgr.cc
  ${RUNTIME_SRC_DIR}/timestamp-parse-util.cc
  ${RUNTIME_SRC_DIR}/timestamp-value.cc
  ${RUNTIME_SRC_DIR}/datetime-simple-date-format-parser.cc
  ${RUNTIME_SRC_DIR}/tuple.cc
  ${RUNTIME_SRC_DIR}/tuple-ir.cc
  ${RUNTIME_SRC_DIR}/tuple-row.cc
  ${RUNTIME_SRC_DIR}/tmp-file-mgr.cc
  ${RUNTIME_SRC_DIR}/datetime-parser-common.cc
  ${RUNTIME_SRC_DIR}/query-state.cc
  ${RUNTIME_SRC_DIR}/query-exec-mgr.cc
  ${RUNTIME_SRC_DIR}/date-parse-util.cc
  ${RUNTIME_SRC_DIR}/date-value.cc
  ${RUNTIME_SRC_DIR}/datetime-iso-sql-format-parser.cc
  ${RUNTIME_SRC_DIR}/datetime-iso-sql-format-tokenizer.cc
)
add_dependencies(RuntimeParquet UtilParquet)

add_library(TestUtilParquet
  ${TESTUTIL_SRC_DIR}/desc-tbl-builder.cc
)

add_library(UtilParquet
  ${UTIL_SRC_DIR}/bitmap.cc
  ${UTIL_SRC_DIR}/bit-packing.cc
  ${UTIL_SRC_DIR}/bit-util.cc
  ${UTIL_SRC_DIR}/cgroup-util.cc
  ${UTIL_SRC_DIR}/coding-util.cc
  ${UTIL_SRC_DIR}/codec.cc
  ${UTIL_SRC_DIR}/collection-metrics.cc
  ${UTIL_SRC_DIR}/compression-util.cc
  ${UTIL_SRC_DIR}/compress.cc
  ${UTIL_SRC_DIR}/cpu-info.cc
  ${UTIL_SRC_DIR}/cyclic-barrier.cc
  ${UTIL_SRC_DIR}/dynamic-util.cc
  ${UTIL_SRC_DIR}/debug-util.cc
  ${UTIL_SRC_DIR}/decompress.cc
  ${UTIL_SRC_DIR}/disk-info.cc
  ${UTIL_SRC_DIR}/error-util.cc
  ${UTIL_SRC_DIR}/event-metrics.cc
  ${UTIL_SRC_DIR}/flat_buffer.cc
  ${UTIL_SRC_DIR}/hdfs-util.cc
  ${UTIL_SRC_DIR}/hdfs-bulk-ops.cc
  ${UTIL_SRC_DIR}/hdr-histogram.cc
  ${UTIL_SRC_DIR}/impalad-metrics.cc
  ${UTIL_SRC_DIR}/in-list-filter.cc
  ${UTIL_SRC_DIR}/in-list-filter-ir.cc
  ${UTIL_SRC_DIR}/json-util.cc
  ${UTIL_SRC_DIR}/mem-info.cc
  ${UTIL_SRC_DIR}/memusage-path-handlers.cc
  ${UTIL_SRC_DIR}/metrics.cc
  ${UTIL_SRC_DIR}/min-max-filter.cc
  ${UTIL_SRC_DIR}/min-max-filter-ir.cc
  ${UTIL_SRC_DIR}/mpfit-util.cc
  ${UTIL_SRC_DIR}/openssl-util.cc
  ${UTIL_SRC_DIR}/os-info.cc
  ${UTIL_SRC_DIR}/os-util.cc
  ${UTIL_SRC_DIR}/parquet-bloom-filter.cc
  ${UTIL_SRC_DIR}/parse-util.cc
  ${UTIL_SRC_DIR}/path-builder.cc
  ${UTIL_SRC_DIR}/periodic-counter-updater.cc
  ${UTIL_SRC_DIR}/progress-updater.cc
  ${UTIL_SRC_DIR}/process-state-info.cc
  ${UTIL_SRC_DIR}/redactor.cc
  ${UTIL_SRC_DIR}/runtime-profile.cc
  ${UTIL_SRC_DIR}/simple-logger.cc
  ${UTIL_SRC_DIR}/string-parser.cc
  ${UTIL_SRC_DIR}/string-util.cc
  ${UTIL_SRC_DIR}/symbols-util.cc
  ${UTIL_SRC_DIR}/static-asserts.cc
  ${UTIL_SRC_DIR}/summary-util.cc
  ${UTIL_SRC_DIR}/table-printer.cc
  ${UTIL_SRC_DIR}/test-info.cc
  ${UTIL_SRC_DIR}/thread.cc
  ${UTIL_SRC_DIR}/time.cc
  ${UTIL_SRC_DIR}/uid-util.cc
  ${UTIL_SRC_DIR}/url-parser.cc
  ${UTIL_SRC_DIR}/network-util.cc
  ${UTIL_SRC_DIR}/filesystem-util.cc
  ${UTIL_SRC_DIR}/memory-metrics.cc
  ${UTIL_SRC_DIR}/histogram-metric.cc
  ${UTIL_SRC_DIR}/os-util.cc
)
add_dependencies(UtilParquet ImpalaThriftParquet)

add_library(PParquet
  ${EXEC_SRC_DIR}/parquet/hdfs-parquet-scanner.cc
  ${EXEC_SRC_DIR}/parquet/hdfs-parquet-table-writer.cc
  ${EXEC_SRC_DIR}/parquet/parquet-bloom-filter-util.cc
  ${EXEC_SRC_DIR}/parquet/parquet-bool-decoder.cc
  ${EXEC_SRC_DIR}/parquet/parquet-collection-column-reader.cc
  ${EXEC_SRC_DIR}/parquet/parquet-column-readers.cc
  ${EXEC_SRC_DIR}/parquet/parquet-column-stats.cc
  ${EXEC_SRC_DIR}/parquet/parquet-level-decoder.cc
  ${EXEC_SRC_DIR}/parquet/parquet-metadata-utils.cc
  ${EXEC_SRC_DIR}/parquet/parquet-column-chunk-reader.cc
  ${EXEC_SRC_DIR}/parquet/parquet-page-reader.cc
  ${EXEC_SRC_DIR}/parquet/parquet-common.cc
  ${EXEC_SRC_DIR}/parquet/parquet-page-index.cc
  ${EXEC_SRC_DIR}/exec-node.cc
  ${EXEC_SRC_DIR}/hdfs-columnar-scanner.cc
  ${EXEC_SRC_DIR}/hdfs-columnar-scanner-ir.cc
  ${EXEC_SRC_DIR}/hdfs-scan-node-base.cc
  ${EXEC_SRC_DIR}/hdfs-scan-node.cc
  ${EXEC_SRC_DIR}/hdfs-scanner.cc
  ${EXEC_SRC_DIR}/hdfs-scanner-ir.cc
  ${EXEC_SRC_DIR}/scanner-context.cc
  ${EXEC_SRC_DIR}/scan-node.cc
  ${EXEC_SRC_DIR}/file-metadata-utils.cc
  ${EXEC_SRC_DIR}/filter-context.cc
  ${EXEC_SRC_DIR}/text-converter.cc
  ${EXEC_SRC_DIR}/read-write-util.cc
)
add_dependencies(PParquet ImpalaThriftParquet)

set (PARQUET_DEP_LIBS
  PParquet
#  ExecParquet
  GlobalFlagsParquet
  TestUtilParquet
  RuntimeParquet
  ExprsParquet
  UdfParquet
  CommonParquet
  IoParquet
  BufferPoolParquet
  RpcParquet
  UtilParquet
  GUtilParquet
  ImpalaThriftParquet
)

set(GLog_LIBS "${Toolchain_SRC_DIR}/glog-0.3.5-p3/lib/libglog.a")
set(Protobuf_LIBS "${Toolchain_SRC_DIR}/protobuf-3.14.0/lib/libprotobuf.a")
set(GFlags_LIBS "${Toolchain_SRC_DIR}/gflags-2.2.0-p2/lib/libgflags.a")
set(Zlib_LIBS "${Toolchain_SRC_DIR}/zlib-1.2.11/lib/libz.a")
set(Snappy_LIBS "${Toolchain_SRC_DIR}/snappy-1.1.8/lib/libsnappy.a")
set(openssl_LIBS "${Toolchain_SRC_DIR}/openssl-1.0.2l/lib/libcrypto.a")
set(re2_LIBS "${Toolchain_SRC_DIR}/re2-20190301/lib/libre2.a")
set(zstd_LIBS "${Toolchain_SRC_DIR}/zstd-1.4.9/lib/libzstd.a")
set(bzip2_LIBS "${Toolchain_SRC_DIR}/bzip2-1.0.8-p2/lib/libbz2.a")
set(boost_thread_LIBS "${Toolchain_SRC_DIR}/boost-1.74.0-p1/lib/libboost_thread.a")
set(thrift_thread_LIBS "${Toolchain_SRC_DIR}/thrift-0.11.0-p4/lib/libthrift.a")
set(lz4_thread_LIBS "${Toolchain_SRC_DIR}/lz4-1.9.3/lib/liblz4.a")
set(boostfile_thread_LIBS "${Toolchain_SRC_DIR}/boost-1.74.0-p1/lib/libboost_filesystem.a")
set(cctz_thread_LIBS "${Toolchain_SRC_DIR}/cctz-2.2/lib/libcctz.a")
set(Gperftools_thread_LIBS "${Toolchain_SRC_DIR}/gperftools-2.5-p4/lib/libtcmalloc.a")

#set(Hdfs_util_LIBS "/home/ff/Impala/toolchain/cdp_components-18462549/hadoop-3.1.1.7.2.14.0-21/lib/native/libhdfs.a")

ADD_EXECUTABLE(hdfs-parquet-file-test hdfs-parquet-file-test.cc)
TARGET_LINK_LIBRARIES(hdfs-parquet-file-test ${PARQUET_DEP_LIBS} ${GLog_LIBS} ${Protobuf_LIBS} ${Zlib_LIBS} ${Snappy_LIBS} ${openssl_LIBS} ${re2_LIBS} ${zstd_LIBS} ${bzip2_LIBS} ${boost_thread_LIBS} ${GFlags_LIBS} ${thrift_thread_LIBS} ${lz4_thread_LIBS} ${Hdfs_util_LIBS} ${boostfile_thread_LIBS} ${cctz_thread_LIBS} ${Gperftools_thread_LIBS} -ldl -lrt )

