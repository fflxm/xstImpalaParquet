#include <snappy.h>
#include <iostream>
#include <sstream>
#include <vector>
#include <gflags/gflags.h>
#include <sys/time.h>

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
#include "util/thrift-debug-util.h"

#include "common/names.h"
#include "common/object-pool.h"
#include "common/status.h"
#include "common/init.h"

#include "testutil/desc-tbl-builder.h"

#include "exec/exec-node.h"
#include "exec/hdfs-scan-node-base.h"
#include "exec/hdfs-scan-node.h"

using namespace parquet;
using namespace impala;

class CParquetFileProccess {
 public:
  CParquetFileProccess(char* filename, int64_t file_size, int64_t threadnum) : pfile_(filename),file_size_(file_size),threadnum_(threadnum) {};
  ~CParquetFileProccess(){};
    
  Status process() {
    cout << "=========="<< __func__ <<" begin=========="<< endl;
    RETURN_IF_ERROR(CreateTestEnv(64 * 1024, 4L * 1024 * 1024 * 1024));

    ObjectPool* obj_pool = runtime_state_->query_state()->obj_pool();

    DescriptorTblBuilder builder(obj_pool);
    TTableDescriptor table_desc;
    CreateDescriptor(&table_desc);
    builder.SetTableDescriptor(table_desc);
    builder.DeclareTuple() << TYPE_BIGINT << TYPE_BIGINT << TYPE_BIGINT << TYPE_BIGINT << TYPE_DOUBLE << TYPE_DOUBLE << TYPE_DOUBLE << TYPE_DOUBLE << TYPE_STRING << TYPE_STRING << TYPE_DATE << TYPE_DATE << TYPE_DATE << TYPE_STRING << TYPE_STRING << TYPE_STRING;
    DescriptorTbl* desc_tbl = builder.BuildLocal();
    cout << desc_tbl->DebugString() << endl;

    TPlanNode* tnode = CreateNode();

    QueryState* qs = runtime_state_->query_state();
    qs->Set_desc_tbl(desc_tbl);

    CreateFragmentState(*tnode);

//    HdfsScanPlanNode* pnode = new HdfsScanPlanNode();
//    RETURN_IF_ERROR(pnode->Init(*tnode, fragment_state_));
HdfsScanPlanNode* pnode = (HdfsScanPlanNode*)fragment_state_->plan_tree();

///////////////////////////
    HdfsScanNode* pHdfsScanNode = new HdfsScanNode(obj_pool, *pnode, *desc_tbl);
    RETURN_IF_ERROR(pHdfsScanNode->Prepare(runtime_state_));
    RETURN_IF_ERROR(pHdfsScanNode->OpenLocal(runtime_state_));

    int64_t len = file_size_;
    uint8_t data[len];
    uint8_t* pdata = data;
    memset(&data, 0x0, len);
    io::BufferOpts buffer_opts = io::BufferOpts::ReadInto(io::BufferOpts::NO_CACHING, pdata, len);

    ScanRangeMetadata ori_meta_data(0, nullptr);
    io::ScanRange* pOriRange = io::ScanRange::AllocateScanRange(obj_pool, nullptr, pfile_, file_size_, 0, {}, &ori_meta_data, 0, false, 1105, buffer_opts);
    ScanRangeMetadata meta_data(0, pOriRange);
    io::ScanRange* pScanRange = io::ScanRange::AllocateScanRange(obj_pool, nullptr, pfile_, file_size_, 0, {}, &meta_data, 0, false, 1105, buffer_opts);

    struct timeval tv;
    gettimeofday(&tv,NULL);
    cout<< "begin time:tv_sec[" << tv.tv_sec <<"]tv_usec[" << tv.tv_usec <<"]" << endl;

    vector<FilterContext> filter_ctxs;
//    int64_t scanner_thread_reservation = 131072;
    int64_t scanner_thread_reservation = 17621789490;
    Status aa = pHdfsScanNode->ScannerLocal(runtime_state_, filter_ctxs, pScanRange, scanner_thread_reservation);
    if (!aa.ok()) {
      if(pHdfsScanNode != nullptr) delete pHdfsScanNode;
      return Status(Substitute("ScannerLocal error: process Range $0 error", pScanRange->DebugString()));
    }

    struct timeval tvend;
    gettimeofday(&tvend,NULL);
    cout<< "end time:tv_sec[" << tvend.tv_sec <<"]tv_usec[" << tvend.tv_usec <<"]" << endl;

    float timeused = (tvend.tv_sec- tv.tv_sec)*1000000+(tvend.tv_usec-tv.tv_usec);
    cout<< "used:" << timeused << endl;

    cout << "==========ReadFromLocal begin=========="<< endl;
    cout <<data<< endl;
    cout <<scanner_thread_reservation ++ <<endl;
    cout << "==========ReadFromLocal end=========="<< endl;

    pHdfsScanNode->Close(runtime_state_);
    cout << "=========="<< __func__ <<" end=========="<< endl;
    if(pHdfsScanNode != nullptr) delete pHdfsScanNode;
    return Status::OK();
  }

 private:
  char* pfile_ = nullptr;
  int64_t file_size_ = 0;
  int64_t threadnum_ = 0;
  unique_ptr<TestEnv> test_env_;
  RuntimeState* runtime_state_ = nullptr;
  FragmentState* fragment_state_ = nullptr;
  TExpr texpr_;

  Status CreateTestEnv(int64_t min_page_size = 64 * 1024,
      int64_t buffer_bytes_limit = 4L * 1024 * 1024 * 1024) {
    cout << "=========="<< __func__ <<" begin=========="<< endl;    
    test_env_.reset(new TestEnv());
    test_env_->SetBufferPoolArgs(min_page_size, buffer_bytes_limit);
    RETURN_IF_ERROR(test_env_->Init(threadnum_));
    TQueryOptions query_options;
    query_options.__set_default_spillable_buffer_size(min_page_size);
    query_options.__set_min_spillable_buffer_size(min_page_size);
    query_options.__set_buffer_pool_limit(buffer_bytes_limit);
    query_options.__set_parquet_late_materialization_threshold(1105);
    query_options.__set_parquet_fallback_schema_resolution(TSchemaResolutionStrategy::NAME);
    // Also initializes runtime_state_
    RETURN_IF_ERROR(test_env_->CreateQueryState(1105, &query_options, &runtime_state_));
    cout << "=========="<< __func__ <<" end=========="<< endl;
    return Status::OK();
  }

  TPlanNode* CreateNode() {
    cout << "=========="<< __func__ <<" begin=========="<< endl;

    TPlanNode* tnode = new TPlanNode();
    memset(tnode, 0x0, sizeof(TPlanNode));
    tnode->__set_node_type(TPlanNodeType::HDFS_SCAN_NODE);
    tnode->__set_node_id(0);
    tnode->__set_limit(-1);
      vector<TTupleId> val;
      val.push_back((TTupleId) 0);
    tnode->__set_row_tuples(val);
      vector<bool> bval;
      bval.push_back(true);
    tnode->__set_nullable_tuples(bval);
      THdfsScanNode thsn;
      thsn.__set_tuple_id((TTupleId) 0);
      thsn.__set_use_mt_scan_node(false);
      thsn.__set_stats_tuple_id((TTupleId) 0);
      thsn.__set_is_partition_key_scan(true);
    tnode->__set_hdfs_scan_node(thsn);
      TBackendResourceProfile trpf;
      trpf.__set_min_reservation(0);
      trpf.__set_max_reservation(65536);
      trpf.__set_spillable_buffer_size(65536);
      trpf.__set_max_row_buffer_size(65536);
    tnode->__set_resource_profile(trpf);

    cout << "=========="<< __func__ <<" end=========="<< endl;
    return tnode;
  }

  void CreateFragmentState(const TPlanNode tnode) {
    cout << "=========="<< __func__ <<" begin=========="<< endl;

    TPlanFragment tpf;
    tpf.__set_idx((TFragmentIdx) 0);
    tpf.__set_display_name("test");
      TPlan tp;
        vector<TPlanNode> vpn;
        vpn.push_back(tnode);
      tp.__set_nodes(vpn);    
    tpf.__set_plan(tp);
      TDataSink tds;
      tds.__set_type(TDataSinkType::TABLE_SINK);
        TDataStreamSink tdss;
        tdss.__set_dest_node_id((TPlanNodeId) 0);
          TDataPartition tdp;
          tdp.__set_type(TPartitionType::UNPARTITIONED);
            vector<TExpr> vte;
          //  vte.push_back(texpr_);
          tdp.__set_partition_exprs(vte);
        tdss.__set_output_partition(tdp);
      tds.__set_stream_sink(tdss);
        TTableSink tts;
        tts.__set_target_table_id((TTableId)0);
        tts.__set_type(TTableSinkType::HDFS);
        tts.__set_action(TSinkAction::INSERT);
          THdfsTableSink hts;
          hts.__set_partition_key_exprs(vte);
          hts.__set_overwrite(true);
          hts.__set_skip_header_line_count(1105);
          hts.__set_input_is_clustered(true);
            vector<int32_t>  vhhhh;
            vhhhh.push_back(1105);
          hts.__set_sort_columns(vhhhh);
          hts.__set_write_id(1105);
          hts.__set_sorting_order(TSortingOrder::LEXICAL);
          hts.__set_is_result_sink(true);
          hts.__set_external_output_dir("/dev/null");
          hts.__set_external_output_partition_depth(1105);
            map<string, int64_t> str11222;
            str11222.insert(make_pair("test",0));
          hts.__set_parquet_bloom_filter_col_info(str11222);
        tts.__set_hdfs_table_sink(hts);
//        tts.__set_kudu_table_sink(const TKuduTableSink& val);      
      tds.__set_table_sink(tts);
        TJoinBuildSink Tjbs;
        Tjbs.__set_dest_node_id((TPlanNodeId) 0);
        Tjbs.__set_join_op(TJoinOp::INNER_JOIN);
          TEqJoinCondition tejc;
          tejc.__set_left(texpr_);
          tejc.__set_right(texpr_);
          tejc.__set_is_not_distinct_from(false);
          vector<TEqJoinCondition> vejc;
          vejc.push_back(tejc);
        Tjbs.__set_eq_join_conjuncts(vejc);
          TRuntimeFilterDesc trfd;
          trfd.__set_filter_id(1105);
          trfd.__set_src_expr(texpr_);
            TRuntimeFilterTargetDesc trftd;
            trftd.__set_node_id((TPlanNodeId) 0);
            trftd.__set_target_expr(texpr_);
            trftd.__set_is_bound_by_partition_columns(false);
            trftd.__set_target_expr_slotids(vector<TSlotId>(1,(TSlotId)1105));
            trftd.__set_is_local_target(false);
//            trftd.__set_kudu_col_name(const std::string& val);
//            trftd.__set_kudu_col_type(const  ::impala::TColumnType& val);
              TColumnValue tcv;
              tcv.__set_int_val(0);
            trftd.__set_low_value(tcv);
              tcv.__set_int_val(1105);
            trftd.__set_high_value(tcv);
            trftd.__set_is_min_max_value_present(false);
            trftd.__set_is_column_in_data_file(false);
            vector<TRuntimeFilterTargetDesc>  vrftd;
            vrftd.push_back(trftd);
          trfd.__set_targets(vrftd);
            map< TPlanNodeId, int32_t> mal111;
            mal111.insert(make_pair((TPlanNodeId)1105,0));
          trfd.__set_planid_to_target_ndx(mal111);
          trfd.__set_is_broadcast_join(false);
          trfd.__set_has_local_targets(false);
          trfd.__set_has_remote_targets(false);
          trfd.__set_applied_on_partition_columns(false);
          trfd.__set_ndv_estimate(1105);
          trfd.__set_type(TRuntimeFilterType::BLOOM);
          trfd.__set_compareOp(extdatasource::TComparisonOp::NE);
          trfd.__set_filter_size_bytes(1105);
          trfd.__set_src_node_id((TPlanNodeId) 0);
          vector<TRuntimeFilterDesc> vrfd;
          vrfd.push_back(trfd);
        Tjbs.__set_runtime_filters(vrfd);
        Tjbs.__set_hash_seed(1105);
        Tjbs.__set_share_build(false);
      tds.__set_join_build_sink(Tjbs);
        TPlanRootSink plan_root_sink;
          TBackendResourceProfile tbrp;
          tbrp.__set_min_reservation(2*8192);
          tbrp.__set_max_reservation(4*8192);
          tbrp.__set_spillable_buffer_size(1105);
          tbrp.__set_max_row_buffer_size(1105);
          plan_root_sink.__set_resource_profile(tbrp);
      tds.__set_plan_root_sink(plan_root_sink);
      tds.__set_label("test");
        TExecStats tes11;
        tes11.__set_latency_ns(1);
        tes11.__set_cpu_time_ns(1);
        tes11.__set_cardinality(2);
        tes11.__set_memory_used(1024);
      tds.__set_estimated_stats(tes11);
      tds.__set_output_exprs(vte);
      tds.__set_resource_profile(tbrp);
    tpf.__set_output_sink(tds);
    tpf.__set_partition(tdp);
    tpf.__set_backend_min_mem_reservation_bytes(1105);
    tpf.__set_instance_min_mem_reservation_bytes(1105);
    tpf.__set_instance_initial_mem_reservation_total_claims(1105);
    tpf.__set_backend_initial_mem_reservation_total_claims(1105);
    tpf.__set_produced_runtime_filters_reservation_bytes(1105);
    tpf.__set_consumed_runtime_filters_reservation_bytes(1105);
    tpf.__set_thread_reservation(1105);
    vector<TPlanFragment> vpf;
    vpf.push_back(tpf);

//    PlanFragmentCtxPB fragment_ctx;
//    QueryState* qs = runtime_state_->query_state();
//    fragment_state_ = new FragmentState(qs, tpf, fragment_ctx);

    TPlanFragmentInstanceCtx tpfic;
    tpfic.__set_fragment_idx((TFragmentIdx) 0);
      TUniqueId tuid;
      tuid.__set_hi(0);
      tuid.__set_lo(0);
    tpfic.__set_fragment_instance_id(tuid);
    tpfic.__set_per_fragment_instance_idx(1105);
    tpfic.__set_per_exch_num_senders(mal111);
    tpfic.__set_sender_id(1105);
      TDebugOptions tdoption;
      tdoption.__set_node_id((TPlanNodeId) 0);
      tdoption.__set_phase(TExecNodePhase::GETNEXT);
      tdoption.__set_action(TDebugAction::DELAY);
      tdoption.__set_action_param("test");
    tpfic.__set_debug_options(tdoption);
      TRuntimeFilterSource trfs;
      trfs.__set_src_node_id((TPlanNodeId) 0);
      trfs.__set_filter_id(1105);
      vector<TRuntimeFilterSource> vrfs;
      vrfs.push_back(trfs);
    tpfic.__set_filters_produced(vrfs);
    tpfic.__set_num_join_build_outputs(1105);
    tpfic.__set_num_backends(1105);
    vector<TPlanFragmentInstanceCtx> vpfic;
    vpfic.push_back(tpfic);

    TExecPlanFragmentInfo fragment_info;
    fragment_info.__set_fragments(vpf);
    fragment_info.__set_fragment_instance_ctxs(vpfic);

    ExecQueryFInstancesRequestPB request;
    PlanFragmentInstanceCtxPB* instance_ctx_pb = request.add_fragment_instance_ctxs();
      ::google::protobuf::Map< ::google::protobuf::int32, ::impala::ScanRangesPB > srmap;
        ScanRangesPB srspb;
        ::impala::ScanRangeParamsPB* insSrPB = srspb.add_scan_ranges();
          ScanRangePB srpb;
            HdfsFileSplitPB hdfs_file_split;
            hdfs_file_split.set_partition_id(0);
            hdfs_file_split.set_file_length(file_size_);
            //hdfs_file_split.set_relative_path(pfile_);
            hdfs_file_split.set_mtime(1105);
            //hdfs_file_split.set_file_compression();
            hdfs_file_split.set_offset(0);
            hdfs_file_split.set_length(file_size_);
          *srpb.mutable_hdfs_file_split() = hdfs_file_split;
        *insSrPB->mutable_scan_range() = srpb;
      srmap.insert({0, srspb});
    *instance_ctx_pb->mutable_per_node_scan_ranges() = srmap;
    PlanFragmentCtxPB* fragment_ctxs = request.add_fragment_ctxs();
    fragment_ctxs->set_fragment_idx(0);
    request.set_initial_mem_reservation_total_claims(0);

    QueryState* qs = runtime_state_->query_state();
    Status bb = qs->CreateFragmentStateMapLocal(&fragment_info, &request);
    if(!bb.ok()){
      cout << "CreateFragmentStateMapLocal error"<<endl; 
    }
    fragment_state_ = qs->findFragmentState((TFragmentIdx) 0);

    cout << "=========="<< __func__ <<" end=========="<< endl;
  }

  void CreateDescriptor(TTableDescriptor *ttable) {
    cout << "=========="<< __func__ <<" begin=========="<< endl;

    ttable->__set_id((TTableId) 0);
    ttable->__set_tableType(TTableType::HDFS_TABLE);
    ttable->__set_numClusteringCols(0);
////////////////
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
            ten.__set_node_type(TExprNodeType::NULL_LITERAL);
//            ten.__set_type(tcype1);
            ten.__set_num_children(0);
            ten.__set_is_constant(false);
              TFunction tt2;
                TFunctionName tfn1;
                tfn1.__set_db_name("test");
                tfn1.__set_function_name("find1105");
              tt2.__set_name(tfn1);
              tt2.__set_binary_type(TFunctionBinaryType::NATIVE);
//              tt2.__set_arg_types(vector<TColumnType>(1,tcype1));
//              tt2.__set_ret_type(tcype1);
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
//                taf.__set_intermediate_type(tcype1);
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
//              taexpr.__set_arg_types(vector<TColumnType>(1,tcype1));
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
          
          memset(&texpr_, 0x0, sizeof(TExpr));
          memcpy(&texpr_, &te, sizeof(TExpr));

//        thp.__set_partitionKeyExprs(vte);
          THdfsPartitionLocation tpl;
          tpl.__set_prefix_index(-1);
          tpl.__set_suffix(pfile_);
        thp.__set_location(tpl);
        thp.__set_id(0);
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
        thp.__set_tbl_name("lineitem");
        thp.__set_partition_name("lineitem");
          THdfsStorageDescriptor thsd;
          thsd.__set_lineDelim(1);
          thsd.__set_fieldDelim(1);
          thsd.__set_collectionDelim(1);
          thsd.__set_mapKeyDelim(1);
          thsd.__set_escapeChar(1);
          thsd.__set_quoteChar(1);
          thsd.__set_fileFormat(THdfsFileFormat::PARQUET);
          thsd.__set_blockSize(file_size_);
        thp.__set_hdfs_storage_descriptor(thsd);
        map<int64_t, THdfsPartition> thpamp;
        thpamp.insert(make_pair(0, thp));

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
          spk.__set_table_name("lineitem");
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
    ttable->__set_hdfsTable(tht);

    ttable->__set_tableName("lineitem");
    ttable->__set_dbName("test");

    cout << "=========="<< __func__ <<" end=========="<< endl;
  }
};

int main(int argc, char* argv[]){
    //impala::InitCommonRuntime(argc, argv, false, impala::TestInfo::BE_TEST);

    if (argc <= 2) {
        cout << "Must specify input file." << endl;
        return -1;
    } 

    FILE* file = fopen(argv[1], "r");
    assert(file != NULL);

    fseek(file, 0L, SEEK_END);
    size_t file_len = ftell(file);
    cout << "file_len ="<< file_len << endl;
    int tnum = atoi(argv[2]);

    CParquetFileProccess aa(argv[1],file_len,tnum);

    Status ss = aa.process();
    if (!ss.ok()) {
      cout << "process error["<< ss.GetDetail() <<"]"<< endl;
      return -1;
    }

    return 0;
}