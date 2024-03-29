/**
 * Autogenerated by Thrift Compiler (0.11.0)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef ExternalDataSource_TYPES_H
#define ExternalDataSource_TYPES_H

#include <iosfwd>

#include <thrift/Thrift.h>
#include <thrift/TApplicationException.h>
#include <thrift/TBase.h>
#include <thrift/protocol/TProtocol.h>
#include <thrift/transport/TTransport.h>

#include <thrift/stdcxx.h>
#include "Status_types.h"
#include "Data_types.h"
#include "Types_types.h"


namespace impala { namespace extdatasource {

struct TComparisonOp {
  enum type {
    LT = 0,
    LE = 1,
    EQ = 2,
    NE = 3,
    GE = 4,
    GT = 5,
    DISTINCT_FROM = 6,
    NOT_DISTINCT = 7
  };
};

extern const std::map<int, const char*> _TComparisonOp_VALUES_TO_NAMES;

std::ostream& operator<<(std::ostream& out, const TComparisonOp::type& val);

class TColumnDesc;

class TTableSchema;

class TRowBatch;

class TBinaryPredicate;

class TPrepareParams;

class TPrepareResult;

class TOpenParams;

class TOpenResult;

class TGetNextParams;

class TGetNextResult;

class TCloseParams;

class TCloseResult;

typedef struct _TColumnDesc__isset {
  _TColumnDesc__isset() : name(false), type(false) {}
  bool name :1;
  bool type :1;
} _TColumnDesc__isset;

class TColumnDesc {
 public:

  TColumnDesc(const TColumnDesc&);
  TColumnDesc(TColumnDesc&&);
  TColumnDesc& operator=(const TColumnDesc&);
  TColumnDesc& operator=(TColumnDesc&&);
  TColumnDesc() : name() {
  }

  virtual ~TColumnDesc() throw();
  std::string name;
   ::impala::TColumnType type;

  _TColumnDesc__isset __isset;

  void __set_name(const std::string& val);

  void __set_type(const  ::impala::TColumnType& val);

  template <class Protocol_>
  uint32_t read(Protocol_* iprot);
  template <class Protocol_>
  uint32_t write(Protocol_* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(TColumnDesc &a, TColumnDesc &b);

std::ostream& operator<<(std::ostream& out, const TColumnDesc& obj);

typedef struct _TTableSchema__isset {
  _TTableSchema__isset() : cols(false) {}
  bool cols :1;
} _TTableSchema__isset;

class TTableSchema {
 public:

  TTableSchema(const TTableSchema&);
  TTableSchema(TTableSchema&&);
  TTableSchema& operator=(const TTableSchema&);
  TTableSchema& operator=(TTableSchema&&);
  TTableSchema() {
  }

  virtual ~TTableSchema() throw();
  std::vector<TColumnDesc>  cols;

  _TTableSchema__isset __isset;

  void __set_cols(const std::vector<TColumnDesc> & val);

  template <class Protocol_>
  uint32_t read(Protocol_* iprot);
  template <class Protocol_>
  uint32_t write(Protocol_* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(TTableSchema &a, TTableSchema &b);

std::ostream& operator<<(std::ostream& out, const TTableSchema& obj);

typedef struct _TRowBatch__isset {
  _TRowBatch__isset() : cols(false), num_rows(false) {}
  bool cols :1;
  bool num_rows :1;
} _TRowBatch__isset;

class TRowBatch {
 public:

  TRowBatch(const TRowBatch&);
  TRowBatch(TRowBatch&&);
  TRowBatch& operator=(const TRowBatch&);
  TRowBatch& operator=(TRowBatch&&);
  TRowBatch() : num_rows(0) {
  }

  virtual ~TRowBatch() throw();
  std::vector< ::impala::TColumnData>  cols;
  int64_t num_rows;

  _TRowBatch__isset __isset;

  void __set_cols(const std::vector< ::impala::TColumnData> & val);

  void __set_num_rows(const int64_t val);

  template <class Protocol_>
  uint32_t read(Protocol_* iprot);
  template <class Protocol_>
  uint32_t write(Protocol_* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(TRowBatch &a, TRowBatch &b);

std::ostream& operator<<(std::ostream& out, const TRowBatch& obj);

typedef struct _TBinaryPredicate__isset {
  _TBinaryPredicate__isset() : col(false), op(false), value(false) {}
  bool col :1;
  bool op :1;
  bool value :1;
} _TBinaryPredicate__isset;

class TBinaryPredicate {
 public:

  TBinaryPredicate(const TBinaryPredicate&);
  TBinaryPredicate(TBinaryPredicate&&);
  TBinaryPredicate& operator=(const TBinaryPredicate&);
  TBinaryPredicate& operator=(TBinaryPredicate&&);
  TBinaryPredicate() : op((TComparisonOp::type)0) {
  }

  virtual ~TBinaryPredicate() throw();
  TColumnDesc col;
  TComparisonOp::type op;
   ::impala::TColumnValue value;

  _TBinaryPredicate__isset __isset;

  void __set_col(const TColumnDesc& val);

  void __set_op(const TComparisonOp::type val);

  void __set_value(const  ::impala::TColumnValue& val);

  template <class Protocol_>
  uint32_t read(Protocol_* iprot);
  template <class Protocol_>
  uint32_t write(Protocol_* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(TBinaryPredicate &a, TBinaryPredicate &b);

std::ostream& operator<<(std::ostream& out, const TBinaryPredicate& obj);

typedef struct _TPrepareParams__isset {
  _TPrepareParams__isset() : table_name(false), init_string(false), predicates(false) {}
  bool table_name :1;
  bool init_string :1;
  bool predicates :1;
} _TPrepareParams__isset;

class TPrepareParams {
 public:

  TPrepareParams(const TPrepareParams&);
  TPrepareParams(TPrepareParams&&);
  TPrepareParams& operator=(const TPrepareParams&);
  TPrepareParams& operator=(TPrepareParams&&);
  TPrepareParams() : table_name(), init_string() {
  }

  virtual ~TPrepareParams() throw();
  std::string table_name;
  std::string init_string;
  std::vector<std::vector<TBinaryPredicate> >  predicates;

  _TPrepareParams__isset __isset;

  void __set_table_name(const std::string& val);

  void __set_init_string(const std::string& val);

  void __set_predicates(const std::vector<std::vector<TBinaryPredicate> > & val);

  template <class Protocol_>
  uint32_t read(Protocol_* iprot);
  template <class Protocol_>
  uint32_t write(Protocol_* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(TPrepareParams &a, TPrepareParams &b);

std::ostream& operator<<(std::ostream& out, const TPrepareParams& obj);

typedef struct _TPrepareResult__isset {
  _TPrepareResult__isset() : num_rows_estimate(false), accepted_conjuncts(false) {}
  bool num_rows_estimate :1;
  bool accepted_conjuncts :1;
} _TPrepareResult__isset;

class TPrepareResult {
 public:

  TPrepareResult(const TPrepareResult&);
  TPrepareResult(TPrepareResult&&);
  TPrepareResult& operator=(const TPrepareResult&);
  TPrepareResult& operator=(TPrepareResult&&);
  TPrepareResult() : num_rows_estimate(0) {
  }

  virtual ~TPrepareResult() throw();
   ::impala::TStatus status;
  int64_t num_rows_estimate;
  std::vector<int32_t>  accepted_conjuncts;

  _TPrepareResult__isset __isset;

  void __set_status(const  ::impala::TStatus& val);

  void __set_num_rows_estimate(const int64_t val);

  void __set_accepted_conjuncts(const std::vector<int32_t> & val);

  template <class Protocol_>
  uint32_t read(Protocol_* iprot);
  template <class Protocol_>
  uint32_t write(Protocol_* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(TPrepareResult &a, TPrepareResult &b);

std::ostream& operator<<(std::ostream& out, const TPrepareResult& obj);

typedef struct _TOpenParams__isset {
  _TOpenParams__isset() : query_id(false), table_name(false), init_string(false), authenticated_user_name(false), row_schema(false), batch_size(false), predicates(false), limit(false) {}
  bool query_id :1;
  bool table_name :1;
  bool init_string :1;
  bool authenticated_user_name :1;
  bool row_schema :1;
  bool batch_size :1;
  bool predicates :1;
  bool limit :1;
} _TOpenParams__isset;

class TOpenParams {
 public:

  TOpenParams(const TOpenParams&);
  TOpenParams(TOpenParams&&);
  TOpenParams& operator=(const TOpenParams&);
  TOpenParams& operator=(TOpenParams&&);
  TOpenParams() : table_name(), init_string(), authenticated_user_name(), batch_size(0), limit(0) {
  }

  virtual ~TOpenParams() throw();
   ::impala::TUniqueId query_id;
  std::string table_name;
  std::string init_string;
  std::string authenticated_user_name;
  TTableSchema row_schema;
  int32_t batch_size;
  std::vector<std::vector<TBinaryPredicate> >  predicates;
  int64_t limit;

  _TOpenParams__isset __isset;

  void __set_query_id(const  ::impala::TUniqueId& val);

  void __set_table_name(const std::string& val);

  void __set_init_string(const std::string& val);

  void __set_authenticated_user_name(const std::string& val);

  void __set_row_schema(const TTableSchema& val);

  void __set_batch_size(const int32_t val);

  void __set_predicates(const std::vector<std::vector<TBinaryPredicate> > & val);

  void __set_limit(const int64_t val);

  template <class Protocol_>
  uint32_t read(Protocol_* iprot);
  template <class Protocol_>
  uint32_t write(Protocol_* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(TOpenParams &a, TOpenParams &b);

std::ostream& operator<<(std::ostream& out, const TOpenParams& obj);

typedef struct _TOpenResult__isset {
  _TOpenResult__isset() : scan_handle(false) {}
  bool scan_handle :1;
} _TOpenResult__isset;

class TOpenResult {
 public:

  TOpenResult(const TOpenResult&);
  TOpenResult(TOpenResult&&);
  TOpenResult& operator=(const TOpenResult&);
  TOpenResult& operator=(TOpenResult&&);
  TOpenResult() : scan_handle() {
  }

  virtual ~TOpenResult() throw();
   ::impala::TStatus status;
  std::string scan_handle;

  _TOpenResult__isset __isset;

  void __set_status(const  ::impala::TStatus& val);

  void __set_scan_handle(const std::string& val);

  template <class Protocol_>
  uint32_t read(Protocol_* iprot);
  template <class Protocol_>
  uint32_t write(Protocol_* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(TOpenResult &a, TOpenResult &b);

std::ostream& operator<<(std::ostream& out, const TOpenResult& obj);

typedef struct _TGetNextParams__isset {
  _TGetNextParams__isset() : scan_handle(false) {}
  bool scan_handle :1;
} _TGetNextParams__isset;

class TGetNextParams {
 public:

  TGetNextParams(const TGetNextParams&);
  TGetNextParams(TGetNextParams&&);
  TGetNextParams& operator=(const TGetNextParams&);
  TGetNextParams& operator=(TGetNextParams&&);
  TGetNextParams() : scan_handle() {
  }

  virtual ~TGetNextParams() throw();
  std::string scan_handle;

  _TGetNextParams__isset __isset;

  void __set_scan_handle(const std::string& val);

  template <class Protocol_>
  uint32_t read(Protocol_* iprot);
  template <class Protocol_>
  uint32_t write(Protocol_* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(TGetNextParams &a, TGetNextParams &b);

std::ostream& operator<<(std::ostream& out, const TGetNextParams& obj);

typedef struct _TGetNextResult__isset {
  _TGetNextResult__isset() : eos(false), rows(false) {}
  bool eos :1;
  bool rows :1;
} _TGetNextResult__isset;

class TGetNextResult {
 public:

  TGetNextResult(const TGetNextResult&);
  TGetNextResult(TGetNextResult&&);
  TGetNextResult& operator=(const TGetNextResult&);
  TGetNextResult& operator=(TGetNextResult&&);
  TGetNextResult() : eos(0) {
  }

  virtual ~TGetNextResult() throw();
   ::impala::TStatus status;
  bool eos;
  TRowBatch rows;

  _TGetNextResult__isset __isset;

  void __set_status(const  ::impala::TStatus& val);

  void __set_eos(const bool val);

  void __set_rows(const TRowBatch& val);

  template <class Protocol_>
  uint32_t read(Protocol_* iprot);
  template <class Protocol_>
  uint32_t write(Protocol_* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(TGetNextResult &a, TGetNextResult &b);

std::ostream& operator<<(std::ostream& out, const TGetNextResult& obj);

typedef struct _TCloseParams__isset {
  _TCloseParams__isset() : scan_handle(false) {}
  bool scan_handle :1;
} _TCloseParams__isset;

class TCloseParams {
 public:

  TCloseParams(const TCloseParams&);
  TCloseParams(TCloseParams&&);
  TCloseParams& operator=(const TCloseParams&);
  TCloseParams& operator=(TCloseParams&&);
  TCloseParams() : scan_handle() {
  }

  virtual ~TCloseParams() throw();
  std::string scan_handle;

  _TCloseParams__isset __isset;

  void __set_scan_handle(const std::string& val);

  template <class Protocol_>
  uint32_t read(Protocol_* iprot);
  template <class Protocol_>
  uint32_t write(Protocol_* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(TCloseParams &a, TCloseParams &b);

std::ostream& operator<<(std::ostream& out, const TCloseParams& obj);


class TCloseResult {
 public:

  TCloseResult(const TCloseResult&);
  TCloseResult(TCloseResult&&);
  TCloseResult& operator=(const TCloseResult&);
  TCloseResult& operator=(TCloseResult&&);
  TCloseResult() {
  }

  virtual ~TCloseResult() throw();
   ::impala::TStatus status;

  void __set_status(const  ::impala::TStatus& val);

  template <class Protocol_>
  uint32_t read(Protocol_* iprot);
  template <class Protocol_>
  uint32_t write(Protocol_* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(TCloseResult &a, TCloseResult &b);

std::ostream& operator<<(std::ostream& out, const TCloseResult& obj);

}} // namespace

#include "ExternalDataSource_types.tcc"

#endif
