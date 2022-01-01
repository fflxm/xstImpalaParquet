// Licensed to the Apache Software Foundation (ASF) under one
// or more contributor license agreements.  See the NOTICE file
// distributed with this work for additional information
// regarding copyright ownership.  The ASF licenses this file
// to you under the Apache License, Version 2.0 (the
// "License"); you may not use this file except in compliance
// with the License.  You may obtain a copy of the License at
//
//   http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing,
// software distributed under the License is distributed on an
// "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
// KIND, either express or implied.  See the License for the
// specific language governing permissions and limitations
// under the License.


#ifndef IMPALA_COMMON_CONFIG_H
#define IMPALA_COMMON_CONFIG_H

/// This is a template that is populated by CMake with config information.
/// See be/CMakeLists.txt for the definition of the CMake symbols.

#define HAVE_SCHED_GETCPU
#define IMPALA_HAVE_FALLOCATE
#define HAVE_PREADV
#define HAVE_PIPE2
#define HAVE_MAGIC_H
#define HAVE_SYNC_FILE_RANGE
/* #undef SLOW_BUILD */
/* #undef IMPALA_BUILD_SHARED_LIBS */
#define IMPALA_CMAKE_BUILD_TYPE DEBUG

#endif
