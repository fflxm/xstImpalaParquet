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
#include "gen-cpp/Descriptors_types.h"
#include "gen-cpp/SqlConstraints_types.h"

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

#include "util/disk-info.h"
#include "util/codec.h"
#include "util/rle-encoding.h"

#include "common/names.h"
#include "common/object-pool.h"
#include "common/status.h"
#include "common/init.h"

#include "exec/exec-node.h"
#include "exec/hdfs-scan-node-base.h"
#include "exec/hdfs-scan-node.h"

using namespace parquet;
using namespace impala;

class CParquetFileProccess {
 public:
  char* pfile_ = nullptr;
  int64_t file_size_ = 0;
  CParquetFileProccess(char* filename, int64_t file_size) : pfile_(filename),file_size_(file_size) {};
  ~CParquetFileProccess(){};

  Status process() {
    RETURN_IF_ERROR(CreateTestEnv(64 * 1024, 4L * 1024 * 1024 * 1024));
cout << "111111111111." << endl;
    DescriptorTbl* desc_tbl = nullptr;
    TDescriptorTableSerialized serialized_thrift_tbl;
    ObjectPool* obj_pool = runtime_state_->query_state()->obj_pool();
    
    TDescriptorTable thrift_tbl;
    CreateDescriptor(&thrift_tbl);

    RETURN_IF_ERROR(DescriptorTbl::CreateLocal(obj_pool,thrift_tbl,serialized_thrift_tbl,&desc_tbl));
cout << "222222222222." << endl;
    ExecNode* node;
    RETURN_IF_ERROR(CreateNode(&node));
cout << "3333333333333." << endl;
    RETURN_IF_ERROR(node->Prepare(runtime_state_));
    RETURN_IF_ERROR(node->Open(runtime_state_));
cout << "444444444444444444." << endl;
    vector<bool> nullable_tuples(1, false);
    vector<TTupleId> tuple_id(1, (TTupleId) 1105);
    RowDescriptor row_desc(*desc_tbl, tuple_id, nullable_tuples);
cout << "555555555555555555." << endl;
    MemTracker* tracker = test_env_->exec_env()->process_mem_tracker();
    RowBatch* row_batch = new RowBatch(&row_desc, 1024, tracker);
    bool eos; 
cout << "666666666666666666." << endl;
    RETURN_IF_ERROR(node->GetNext(runtime_state_, row_batch, &eos));
cout << "777777777777777777." << endl;
    node->Close(runtime_state_);
cout << "888888888888888888." << endl;
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
    RETURN_IF_ERROR(test_env_->CreateQueryState(1105, &query_options, &runtime_state_));

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
    vector<TTupleId> val;
    val.push_back((TTupleId) 1105);
    tnode.__set_row_tuples(val);
    vector<bool> bval;
    bval.push_back(true);
    tnode.__set_nullable_tuples(bval);

    THdfsScanNode thsn;
    thsn.__set_tuple_id((TTupleId) 1105);
    thsn.__set_use_mt_scan_node(false);
    thsn.__set_stats_tuple_id((TTupleId) 1105);

    tnode.__set_hdfs_scan_node(thsn);
    RETURN_IF_ERROR(pnode_->Init(tnode, fragment_state_));
    RETURN_IF_ERROR(pnode_->CreateExecNode(runtime_state_, node));

    return Status::OK();
  }

  void CreateDescriptor(TDescriptorTable *thrift_tbl) {
    // create DescriptorTbl
    TSlotDescriptor tslot;
    tslot.__set_id((TSlotId) 1105);
    tslot.__set_parent((TTupleId) 1105);
    tslot.__set_itemTupleId((TTupleId) 1105);
      TTypeNode tn;
      tn.__set_type(TTypeNodeType::ARRAY);
        TScalarType st;
        st.__set_type(TPrimitiveType::BIGINT);
        st.__set_len(1105);
        st.__set_precision(1105);
        st.__set_scale(1105);
      tn.__set_scalar_type(st);
        vector<TStructField> vsf;
        TStructField tsf;
        memset(&tsf,0x0,sizeof(TStructField));
        tsf.__set_name("l_orderkey");
        tsf.__set_comment("l_orderkey");
        tsf.__set_field_id(32);
        vsf.push_back(tsf);
        memset(&tsf,0x0,sizeof(TStructField));
        tsf.__set_name("l_partkey");
        tsf.__set_comment("l_partkey");
        tsf.__set_field_id(32);
        vsf.push_back(tsf);
        memset(&tsf,0x0,sizeof(TStructField));
        tsf.__set_name("l_suppkey");
        tsf.__set_comment("l_suppkey");
        tsf.__set_field_id(32);
        vsf.push_back(tsf);
        memset(&tsf,0x0,sizeof(TStructField));
        tsf.__set_name("l_linenumber");
        tsf.__set_comment("l_linenumber");
        tsf.__set_field_id(32);
        vsf.push_back(tsf);
        memset(&tsf,0x0,sizeof(TStructField));
        tsf.__set_name("l_quantity");
        tsf.__set_comment("l_quantity");
        tsf.__set_field_id(32);
        vsf.push_back(tsf);
        memset(&tsf,0x0,sizeof(TStructField));
        tsf.__set_name("l_extendedprice");
        tsf.__set_comment("l_extendedprice");
        tsf.__set_field_id(32);
        vsf.push_back(tsf);
        memset(&tsf,0x0,sizeof(TStructField));
        tsf.__set_name("l_discount");
        tsf.__set_comment("l_discount");
        tsf.__set_field_id(32);
        vsf.push_back(tsf);
        memset(&tsf,0x0,sizeof(TStructField));
        tsf.__set_name("l_tax");
        tsf.__set_comment("l_tax");
        tsf.__set_field_id(32);
        vsf.push_back(tsf);
        memset(&tsf,0x0,sizeof(TStructField));
        tsf.__set_name("l_returnflag");
        tsf.__set_comment("l_returnflag");
        tsf.__set_field_id(32);
        vsf.push_back(tsf);
        memset(&tsf,0x0,sizeof(TStructField));
        tsf.__set_name("l_linestatus");
        tsf.__set_comment("l_linestatus");
        tsf.__set_field_id(32);
        vsf.push_back(tsf);
        memset(&tsf,0x0,sizeof(TStructField));
        tsf.__set_name("l_shipdate");
        tsf.__set_comment("l_shipdate");
        tsf.__set_field_id(32);
        vsf.push_back(tsf);
        memset(&tsf,0x0,sizeof(TStructField));
        tsf.__set_name("l_commitdate");
        tsf.__set_comment("l_commitdate");
        tsf.__set_field_id(32);
        vsf.push_back(tsf);
        memset(&tsf,0x0,sizeof(TStructField));
        tsf.__set_name("l_receiptdate");
        tsf.__set_comment("l_receiptdate");
        tsf.__set_field_id(32);
        vsf.push_back(tsf);
        memset(&tsf,0x0,sizeof(TStructField));
        tsf.__set_name("l_shipinstruct");
        tsf.__set_comment("l_shipinstruct");
        tsf.__set_field_id(32);
        vsf.push_back(tsf);
        memset(&tsf,0x0,sizeof(TStructField));
        tsf.__set_name("l_shipmode");
        tsf.__set_comment("l_shipmode");
        tsf.__set_field_id(32);
        vsf.push_back(tsf);
        memset(&tsf,0x0,sizeof(TStructField));
        tsf.__set_name("l_comment");
        tsf.__set_comment("l_comment");
        tsf.__set_field_id(32);
        vsf.push_back(tsf);
      tn.__set_struct_fields(vsf);
      vector<TTypeNode> vtn;
      vtn.push_back(tn);
      TColumnType tcype;
      tcype.__set_types(vtn);
    tslot.__set_slotType(tcype);
    tslot.__set_materializedPath(vector<int32_t>(1,1105));
    tslot.__set_byteOffset(0);
    tslot.__set_nullIndicatorByte(0);
    tslot.__set_nullIndicatorBit(-1);
    tslot.__set_slotIdx(0);
    vector<TSlotDescriptor>  slot;
    slot.push_back(tslot);
    thrift_tbl->__set_slotDescriptors(slot);

    TTupleDescriptor ttuple;
    ttuple.__set_id((TTupleId) 1105);
    ttuple.__set_byteSize(32);
    ttuple.__set_numNullBytes(0);
    ttuple.__set_tableId((TTableId) 1105);
    ttuple.__set_tuplePath(vector<int32_t>(1,1105));
    vector<TTupleDescriptor>  vtuple;
    vtuple.push_back(ttuple);
    thrift_tbl->__set_tupleDescriptors(vtuple);

    TTableDescriptor ttable;
    ttable.__set_id((TTableId) 1105);
    ttable.__set_tableType(TTableType::HDFS_TABLE);
      vector<TColumnDescriptor> vtcc;
      TColumnDescriptor tcc;
      memset(&tcc, 0x0, sizeof(TColumnDescriptor));
      tcc.__set_name("l_orderkey");
      tcc.__set_type(tcype);
      vtcc.push_back(tcc);
    ttable.__set_columnDescriptors(vtcc);
    ttable.__set_numClusteringCols(32);
      THdfsTable tht;
      tht.__set_hdfsBaseDir(pfile_);
        vector<string> vcn;
        vcn.push_back("l_orderkey");
        vcn.push_back("l_partkey");
        vcn.push_back("l_suppkey");
        vcn.push_back("l_linenumber");
        vcn.push_back("l_quantity");
        vcn.push_back("l_extendedprice");
        vcn.push_back("l_discount");
        vcn.push_back("l_tax");
        vcn.push_back("l_returnflag");
        vcn.push_back("l_linestatus");
        vcn.push_back("l_shipdate");
        vcn.push_back("l_commitdate");
        vcn.push_back("l_receiptdate");
        vcn.push_back("l_shipinstruct");
        vcn.push_back("l_shipmode");
        vcn.push_back("l_comment");
      tht.__set_colNames(vcn);
      tht.__set_nullPartitionKeyValue("l_orderkey");
      tht.__set_nullColumnValue("l_orderkey");
        THdfsPartition thp;
          TExpr te;
            TExprNode ten;
            ten.__set_node_type(TExprNodeType::INT_LITERAL);
            ten.__set_type(tcype);
            ten.__set_num_children(1105);
            ten.__set_is_constant(false);
              TFunction tt2;
                TFunctionName tfn1;
                tfn1.__set_db_name("test");
                tfn1.__set_function_name("find1105");
              tt2.__set_name(tfn1);
              tt2.__set_binary_type(TFunctionBinaryType::NATIVE);
              tt2.__set_arg_types(vector<TColumnType>(1,tcype));
              tt2.__set_ret_type(tcype);
              tt2.__set_has_var_args(false);
              tt2.__set_comment("test function");
              tt2.__set_signature("test function");
              tt2.__set_hdfs_location(pfile_);
                TScalarFunction tsfunc;
                tsfunc.__set_symbol("tsf");
                tsfunc.__set_prepare_fn_symbol("tsf pre");
                tsfunc.__set_close_fn_symbol("tsf close");
              tt2.__set_scalar_fn(tsfunc);
                TAggregateFunction taf;
                taf.__set_intermediate_type(tcype);
                taf.__set_is_analytic_only_fn(false);
                taf.__set_update_fn_symbol("taf");
                taf.__set_init_fn_symbol("taf");
                taf.__set_serialize_fn_symbol("taf");
                taf.__set_merge_fn_symbol("taf");
                taf.__set_finalize_fn_symbol("taf");
                taf.__set_get_value_fn_symbol("taf");
                taf.__set_remove_fn_symbol("taf");
                taf.__set_ignores_distinct(false);
              tt2.__set_aggregate_fn(taf);
              tt2.__set_is_persistent(false);
              tt2.__set_last_modified_time(1105);
            ten.__set_fn(tt2);
            ten.__set_vararg_start_idx(0);
              TBoolLiteral tblit;
              tblit.__set_value(false);
            ten.__set_bool_literal(tblit);
              TCaseExpr tclit;
              tclit.__set_has_case_expr(false);
              tclit.__set_has_else_expr(false);
            ten.__set_case_expr(tclit);
              TDateLiteral tdlit;
              tdlit.__set_days_since_epoch(1105);
              tdlit.__set_date_string("20220126");
            ten.__set_date_literal(tdlit);
              TFloatLiteral tflit;
              tflit.__set_value(11.05);
            ten.__set_float_literal(tflit);
              TIntLiteral tilit;
              tilit.__set_value(1105);
            ten.__set_int_literal(tilit);
              TInPredicate tipre;
              tipre.__set_is_not_in(false);
            ten.__set_in_predicate(tipre);
              TIsNullPredicate tinpre;
              tinpre.__set_is_not_null(false);
            ten.__set_is_null_pred(tinpre);
              TLiteralPredicate tlpre;
              tlpre.__set_value(false);
              tlpre.__set_is_null(false);
            ten.__set_literal_pred(tlpre);
              TSlotRef tsref;
              tsref.__set_slot_id(1105);
            ten.__set_slot_ref(tsref);
              TStringLiteral tslit;
              tslit.__set_value("test");
            ten.__set_string_literal(tslit);
              TTupleIsNullPredicate ttinpre;
              ttinpre.__set_tuple_ids(vector<TTupleId>(1,1105));
            ten. __set_tuple_is_null_pred(ttinpre);
              TDecimalLiteral tdliter;
              tdliter.__set_value("test");
            ten.__set_decimal_literal(tdliter);
              TAggregateExpr taexpr;
              taexpr.__set_is_merge_agg(false);
              taexpr.__set_arg_types(vector<TColumnType>(1,tcype));
            ten.__set_agg_expr(taexpr);
              TTimestampLiteral ttimelit;
              ttimelit.__set_value("20220126");
            ten.__set_timestamp_literal(ttimelit);
              TKuduPartitionExpr tkpexpr;
              tkpexpr.__set_target_table_id(1105);
              tkpexpr.__set_referenced_columns(vector<int32_t>(1,1105));
            ten.__set_kudu_partition_expr(tkpexpr);
              TCastExpr tcexpr;
              tcexpr.__set_cast_format("test");
            ten.__set_cast_expr(tcexpr);
            vector<TExprNode> vten;
            vten.push_back(ten);
          te.__set_nodes(vten);
          vector<TExpr> vte;
          vte.push_back(te);
        thp.__set_partitionKeyExprs(vte);
          THdfsPartitionLocation tpl;
          tpl.__set_prefix_index(1105);
          tpl.__set_suffix(pfile_);
        thp.__set_location(tpl);
        thp.__set_id(1105);
        thp.__set_prev_id(1105);
          THdfsFileDesc hfd;
          hfd.__set_file_desc_data(pfile_);
          vector<THdfsFileDesc> vhfd;
          vhfd.push_back(hfd);
        thp.__set_file_desc(vhfd);
        thp.__set_insert_file_desc(vhfd);
        thp.__set_delete_file_desc(vhfd);
        thp.__set_access_level(TAccessLevel::READ_WRITE);
        TTableStats ts;
        ts.__set_num_rows(file_size_);
        ts.__set_total_file_bytes(file_size_);
        thp.__set_stats(ts);
        thp.__set_is_marked_cached(false);
        map<string, string> str11;
        str11.insert(make_pair("1","1"));
        thp.__set_hms_parameters(str11);
        thp.__set_num_blocks(1024);
        thp.__set_total_file_size_bytes(file_size_);
        thp.__set_partition_stats("ok");
        thp.__set_has_incremental_stats(false);
        thp.__set_write_id(1105);
        thp.__set_db_name("test");
        thp.__set_tbl_name("testtable");
        thp.__set_partition_name("testtablepat");
          THdfsStorageDescriptor thsd;
          thsd.__set_lineDelim(1);
          thsd.__set_fieldDelim(1);
          thsd.__set_collectionDelim(1);
          thsd.__set_mapKeyDelim(1);
          thsd.__set_escapeChar(1);
          thsd.__set_quoteChar(1);
          thsd.__set_fileFormat(THdfsFileFormat::PARQUET);
          thsd.__set_blockSize(32);
        thp.__set_hdfs_storage_descriptor(thsd);
        map<int64_t, THdfsPartition> thpamp;
        thpamp.insert(make_pair(1105, thp));
      tht.__set_partitions(thpamp);
      tht.__set_has_full_partitions(false);
      tht.__set_has_partition_names("l_orderkey");
      tht.__set_prototype_partition(thp);
      tht.__set_partition_prefixes(vector<string>(1,"l_orderkey"));
        TNetworkAddress tnwa;
        tnwa.__set_hostname("loacalhost");
        tnwa.__set_port(1105);
      tht.__set_network_addresses(vector<TNetworkAddress>(1,tnwa));
        TSqlConstraints tscon;
          Apache::Hadoop::Hive::SQLPrimaryKey spk;
          spk.__set_table_db("test");
          spk.__set_table_name("testtable");
          spk.__set_column_name("testclo");
          spk.__set_key_seq(1105);
          spk.__set_pk_name("spk");
          spk.__set_enable_cstr(false);
          spk.__set_validate_cstr(false);
          spk.__set_rely_cstr(false);
          spk.__set_catName("test");
        tscon.__set_primary_keys(vector< ::Apache::Hadoop::Hive::SQLPrimaryKey>(1,spk));
          Apache::Hadoop::Hive::SQLForeignKey sfk;
          sfk.__set_pktable_db("sfk");
          sfk.__set_pktable_name("sfk");
          sfk.__set_pkcolumn_name("sfk");
          sfk.__set_fktable_db("sfk");
          sfk.__set_fktable_name("sfk");
          sfk.__set_fkcolumn_name("sfk");
          sfk.__set_key_seq(1105);
          sfk.__set_update_rule(1105);
          sfk.__set_delete_rule(1105);
          sfk.__set_fk_name("sfk");
          sfk.__set_pk_name("sfk");
          sfk.__set_enable_cstr(false);
          sfk.__set_validate_cstr(false);
          sfk.__set_rely_cstr(false);
          sfk.__set_catName("sfk");
        tscon.__set_foreign_keys(vector< ::Apache::Hadoop::Hive::SQLForeignKey>(1,sfk));
      tht.__set_sql_constraints(tscon);
      tht.__set_is_full_acid(false);
        TValidWriteIdList tvwlist;
        tvwlist.__set_high_watermark(1105);
        tvwlist.__set_min_open_write_id(1105);
        tvwlist.__set_invalid_write_ids(vector<int64_t>(1,1105));
        tvwlist.__set_aborted_indexes(vector<int32_t>(1,1105));
      tht.__set_valid_write_ids(tvwlist);
    ttable.__set_hdfsTable(tht);
    ttable.__set_tableName("testtable");
    ttable.__set_dbName("test");
    vector<TTableDescriptor>  vtable;
    vtable.push_back(ttable);
    thrift_tbl->__set_tableDescriptors(vtable);
  }
};

int main(int argc, char* argv[]){
    impala::InitCommonRuntime(argc, argv, false, impala::TestInfo::BE_TEST);

    if (argc < 2) {
        cout << "Must specify input file." << endl;
        return -1;
    } 

    FILE* file = fopen(argv[1], "r");
    assert(file != NULL);

    fseek(file, 0L, SEEK_END);
    size_t file_len = ftell(file);
    cerr << "file_len ="<< file_len << endl;

    CParquetFileProccess aa(argv[1],file_len);

    Status ss = aa.process();
    if (!ss.ok()) {
      cerr << "process error["<< ss.GetDetail() <<"]"<< endl;
      return -1;
    }

    return 0;
}