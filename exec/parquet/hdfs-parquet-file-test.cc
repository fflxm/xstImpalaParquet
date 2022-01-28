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

#include <snappy.h>
#include <iostream>
#include <sstream>
#include <vector>
#include <gflags/gflags.h>
#include "gen-cpp/parquet_types.h"
#include "gen-cpp/Types_types.h"
#include "gen-cpp/PlanNodes_types.h"
#include "gen-cpp/Planner_types.h"
#include "gen-cpp/control_service.pb.h"

#include "exec/parquet/parquet-common.h"

#include "runtime/mem-pool.h"
#include "runtime/mem-tracker.h"
#include "runtime/exec-env.h"
#include "runtime/runtime-state.h"
#include "runtime/descriptors.h"
#include "runtime/row-batch.h"
#include "runtime/test-env.h"
#include "runtime/query-state.h"
#include "runtime/fragment-state.h"

#include "util/codec.h"
#include "util/rle-encoding.h"

#include "common/names.h"
#include "common/object-pool.h"
#include "common/status.h"

#include "exec/exec-node.h"
#include "exec/hdfs-scan-node-base.h"
#include "exec/hdfs-scan-node.h"

using namespace parquet;
using namespace impala;

class CParquetFileProccess {
 public:
  char* pfile_ = nullptr;
  CParquetFileProccess(char* filename) : pfile_(filename) {};
  ~CParquetFileProccess(){};

  Status process() {
    RETURN_IF_ERROR(CreateTestEnv(64 * 1024, 4L * 1024 * 1024 * 1024));
  
    ExecNode* node;
    RETURN_IF_ERROR(CreateNode(&node));

    RETURN_IF_ERROR(node->Prepare(runtime_state_));
    RETURN_IF_ERROR(node->Open(runtime_state_));

    DescriptorTbl* desc_tbl = nullptr;
    TDescriptorTableSerialized serialized_thrift_tbl;
    ObjectPool* obj_pool = runtime_state_->query_state()->obj_pool();
    RETURN_IF_ERROR(DescriptorTbl::Create(obj_pool,serialized_thrift_tbl,&desc_tbl));
  
    vector<bool> nullable_tuples(1, false);
    vector<TTupleId> tuple_id(1, (TTupleId) 1105);
    RowDescriptor row_desc(*desc_tbl, tuple_id, nullable_tuples);

    MemTracker* tracker = test_env_->exec_env()->process_mem_tracker();
    RowBatch* row_batch = new RowBatch(&row_desc, 1024, tracker);
    bool eos; 

    RETURN_IF_ERROR(node->GetNext(runtime_state_, row_batch, &eos));

    node->Close(runtime_state_);

    return Status::OK();
  }

 private:
  unique_ptr<TestEnv> test_env_;
  RuntimeState* runtime_state_ = nullptr;
  FragmentState* fragment_state_ = nullptr;
  HdfsScanPlanNode* pnode_ = nullptr;

  Status CreateTestEnv(int64_t min_page_size = 64 * 1024,
      int64_t buffer_bytes_limit = 4L * 1024 * 1024 * 1024) {
    test_env_.reset(new TestEnv());
    test_env_->SetBufferPoolArgs(min_page_size, buffer_bytes_limit);
    RETURN_IF_ERROR(test_env_->Init());

    TQueryOptions query_options;
    query_options.__set_default_spillable_buffer_size(min_page_size);
    query_options.__set_min_spillable_buffer_size(min_page_size);
    query_options.__set_buffer_pool_limit(buffer_bytes_limit);
    // Also initializes runtime_state_
    RETURN_IF_ERROR(test_env_->CreateQueryState(0, &query_options, &runtime_state_));

    return Status::OK();
  }

  Status CreateNode(ExecNode** node) {
    QueryState* qs = runtime_state_->query_state();
    TPlanFragment* fragment = qs->obj_pool()->Add(new TPlanFragment());
    PlanFragmentCtxPB* fragment_ctx = qs->obj_pool()->Add(new PlanFragmentCtxPB());
    fragment_state_ = qs->obj_pool()->Add(new FragmentState(qs, *fragment, *fragment_ctx));

    pnode_ = new HdfsScanPlanNode();

    TPlanNode tnode;
    tnode.__set_node_type(TPlanNodeType::HDFS_SCAN_NODE);
    tnode.__set_node_id(1105);

    THdfsScanNode thsn;
    thsn.__set_tuple_id((TTupleId) 1105);
    thsn.__set_use_mt_scan_node(false);
    thsn.__set_stats_tuple_id((TTupleId) 1105);

    tnode.__set_hdfs_scan_node(thsn);

    RETURN_IF_ERROR(pnode_->Init(tnode, fragment_state_));
    RETURN_IF_ERROR(pnode_->CreateExecNode(runtime_state_, node));

    return Status::OK();
  }
};

int main(int argc, char* argv[]){

    if (argc < 2) {
        cout << "Must specify input file." << endl;
        return -1;
    } 

    FILE* file = fopen(argv[1], "r");
    assert(file != NULL);

    fseek(file, 0L, SEEK_END);
    size_t file_len = ftell(file);
    cerr << "file_len ="<< file_len << endl;

    CParquetFileProccess aa(argv[1]);

    Status ss = aa.process();
    if (!ss.ok()) {
      cerr << "process error["<< ss.GetDetail() <<"]"<< endl;
      return -1;
    }

    return 0;
}