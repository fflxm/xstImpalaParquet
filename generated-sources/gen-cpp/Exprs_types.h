/**
 * Autogenerated by Thrift Compiler (0.11.0)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef Exprs_TYPES_H
#define Exprs_TYPES_H

#include <iosfwd>

#include <thrift/Thrift.h>
#include <thrift/TApplicationException.h>
#include <thrift/TBase.h>
#include <thrift/protocol/TProtocol.h>
#include <thrift/transport/TTransport.h>

#include <thrift/stdcxx.h>
#include "Types_types.h"


namespace impala {

struct TExprNodeType {
  enum type {
    NULL_LITERAL = 0,
    BOOL_LITERAL = 1,
    INT_LITERAL = 2,
    FLOAT_LITERAL = 3,
    STRING_LITERAL = 4,
    DECIMAL_LITERAL = 5,
    TIMESTAMP_LITERAL = 6,
    CASE_EXPR = 7,
    COMPOUND_PRED = 8,
    IN_PRED = 9,
    IS_NULL_PRED = 10,
    LIKE_PRED = 11,
    SLOT_REF = 12,
    TUPLE_IS_NULL_PRED = 13,
    FUNCTION_CALL = 14,
    AGGREGATE_EXPR = 15,
    IS_NOT_EMPTY_PRED = 16,
    KUDU_PARTITION_EXPR = 17,
    VALID_TUPLE_ID_EXPR = 18,
    DATE_LITERAL = 19
  };
};

extern const std::map<int, const char*> _TExprNodeType_VALUES_TO_NAMES;

std::ostream& operator<<(std::ostream& out, const TExprNodeType::type& val);

struct TExtractField {
  enum type {
    INVALID_FIELD = 0,
    YEAR = 1,
    QUARTER = 2,
    MONTH = 3,
    DAY = 4,
    HOUR = 5,
    MINUTE = 6,
    SECOND = 7,
    MILLISECOND = 8,
    EPOCH = 9
  };
};

extern const std::map<int, const char*> _TExtractField_VALUES_TO_NAMES;

std::ostream& operator<<(std::ostream& out, const TExtractField::type& val);

class TBoolLiteral;

class TCaseExpr;

class TDateLiteral;

class TDecimalLiteral;

class TFloatLiteral;

class TIntLiteral;

class TTimestampLiteral;

class TInPredicate;

class TIsNullPredicate;

class TLiteralPredicate;

class TTupleIsNullPredicate;

class TSlotRef;

class TStringLiteral;

class TAggregateExpr;

class TKuduPartitionExpr;

class TCastExpr;

class TExprNode;

class TExpr;

class TExprBatch;


class TBoolLiteral {
 public:

  TBoolLiteral(const TBoolLiteral&);
  TBoolLiteral(TBoolLiteral&&);
  TBoolLiteral& operator=(const TBoolLiteral&);
  TBoolLiteral& operator=(TBoolLiteral&&);
  TBoolLiteral() : value(0) {
  }

  virtual ~TBoolLiteral() throw();
  bool value;

  void __set_value(const bool val);

  template <class Protocol_>
  uint32_t read(Protocol_* iprot);
  template <class Protocol_>
  uint32_t write(Protocol_* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(TBoolLiteral &a, TBoolLiteral &b);

std::ostream& operator<<(std::ostream& out, const TBoolLiteral& obj);


class TCaseExpr {
 public:

  TCaseExpr(const TCaseExpr&);
  TCaseExpr(TCaseExpr&&);
  TCaseExpr& operator=(const TCaseExpr&);
  TCaseExpr& operator=(TCaseExpr&&);
  TCaseExpr() : has_case_expr(0), has_else_expr(0) {
  }

  virtual ~TCaseExpr() throw();
  bool has_case_expr;
  bool has_else_expr;

  void __set_has_case_expr(const bool val);

  void __set_has_else_expr(const bool val);

  template <class Protocol_>
  uint32_t read(Protocol_* iprot);
  template <class Protocol_>
  uint32_t write(Protocol_* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(TCaseExpr &a, TCaseExpr &b);

std::ostream& operator<<(std::ostream& out, const TCaseExpr& obj);


class TDateLiteral {
 public:

  TDateLiteral(const TDateLiteral&);
  TDateLiteral(TDateLiteral&&);
  TDateLiteral& operator=(const TDateLiteral&);
  TDateLiteral& operator=(TDateLiteral&&);
  TDateLiteral() : days_since_epoch(0), date_string() {
  }

  virtual ~TDateLiteral() throw();
  int32_t days_since_epoch;
  std::string date_string;

  void __set_days_since_epoch(const int32_t val);

  void __set_date_string(const std::string& val);

  template <class Protocol_>
  uint32_t read(Protocol_* iprot);
  template <class Protocol_>
  uint32_t write(Protocol_* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(TDateLiteral &a, TDateLiteral &b);

std::ostream& operator<<(std::ostream& out, const TDateLiteral& obj);


class TDecimalLiteral {
 public:

  TDecimalLiteral(const TDecimalLiteral&);
  TDecimalLiteral(TDecimalLiteral&&);
  TDecimalLiteral& operator=(const TDecimalLiteral&);
  TDecimalLiteral& operator=(TDecimalLiteral&&);
  TDecimalLiteral() : value() {
  }

  virtual ~TDecimalLiteral() throw();
  std::string value;

  void __set_value(const std::string& val);

  template <class Protocol_>
  uint32_t read(Protocol_* iprot);
  template <class Protocol_>
  uint32_t write(Protocol_* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(TDecimalLiteral &a, TDecimalLiteral &b);

std::ostream& operator<<(std::ostream& out, const TDecimalLiteral& obj);


class TFloatLiteral {
 public:

  TFloatLiteral(const TFloatLiteral&);
  TFloatLiteral(TFloatLiteral&&);
  TFloatLiteral& operator=(const TFloatLiteral&);
  TFloatLiteral& operator=(TFloatLiteral&&);
  TFloatLiteral() : value(0) {
  }

  virtual ~TFloatLiteral() throw();
  double value;

  void __set_value(const double val);

  template <class Protocol_>
  uint32_t read(Protocol_* iprot);
  template <class Protocol_>
  uint32_t write(Protocol_* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(TFloatLiteral &a, TFloatLiteral &b);

std::ostream& operator<<(std::ostream& out, const TFloatLiteral& obj);


class TIntLiteral {
 public:

  TIntLiteral(const TIntLiteral&);
  TIntLiteral(TIntLiteral&&);
  TIntLiteral& operator=(const TIntLiteral&);
  TIntLiteral& operator=(TIntLiteral&&);
  TIntLiteral() : value(0) {
  }

  virtual ~TIntLiteral() throw();
  int64_t value;

  void __set_value(const int64_t val);

  template <class Protocol_>
  uint32_t read(Protocol_* iprot);
  template <class Protocol_>
  uint32_t write(Protocol_* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(TIntLiteral &a, TIntLiteral &b);

std::ostream& operator<<(std::ostream& out, const TIntLiteral& obj);


class TTimestampLiteral {
 public:

  TTimestampLiteral(const TTimestampLiteral&);
  TTimestampLiteral(TTimestampLiteral&&);
  TTimestampLiteral& operator=(const TTimestampLiteral&);
  TTimestampLiteral& operator=(TTimestampLiteral&&);
  TTimestampLiteral() : value() {
  }

  virtual ~TTimestampLiteral() throw();
  std::string value;

  void __set_value(const std::string& val);

  template <class Protocol_>
  uint32_t read(Protocol_* iprot);
  template <class Protocol_>
  uint32_t write(Protocol_* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(TTimestampLiteral &a, TTimestampLiteral &b);

std::ostream& operator<<(std::ostream& out, const TTimestampLiteral& obj);


class TInPredicate {
 public:

  TInPredicate(const TInPredicate&);
  TInPredicate(TInPredicate&&);
  TInPredicate& operator=(const TInPredicate&);
  TInPredicate& operator=(TInPredicate&&);
  TInPredicate() : is_not_in(0) {
  }

  virtual ~TInPredicate() throw();
  bool is_not_in;

  void __set_is_not_in(const bool val);

  template <class Protocol_>
  uint32_t read(Protocol_* iprot);
  template <class Protocol_>
  uint32_t write(Protocol_* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(TInPredicate &a, TInPredicate &b);

std::ostream& operator<<(std::ostream& out, const TInPredicate& obj);


class TIsNullPredicate {
 public:

  TIsNullPredicate(const TIsNullPredicate&);
  TIsNullPredicate(TIsNullPredicate&&);
  TIsNullPredicate& operator=(const TIsNullPredicate&);
  TIsNullPredicate& operator=(TIsNullPredicate&&);
  TIsNullPredicate() : is_not_null(0) {
  }

  virtual ~TIsNullPredicate() throw();
  bool is_not_null;

  void __set_is_not_null(const bool val);

  template <class Protocol_>
  uint32_t read(Protocol_* iprot);
  template <class Protocol_>
  uint32_t write(Protocol_* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(TIsNullPredicate &a, TIsNullPredicate &b);

std::ostream& operator<<(std::ostream& out, const TIsNullPredicate& obj);


class TLiteralPredicate {
 public:

  TLiteralPredicate(const TLiteralPredicate&);
  TLiteralPredicate(TLiteralPredicate&&);
  TLiteralPredicate& operator=(const TLiteralPredicate&);
  TLiteralPredicate& operator=(TLiteralPredicate&&);
  TLiteralPredicate() : value(0), is_null(0) {
  }

  virtual ~TLiteralPredicate() throw();
  bool value;
  bool is_null;

  void __set_value(const bool val);

  void __set_is_null(const bool val);

  template <class Protocol_>
  uint32_t read(Protocol_* iprot);
  template <class Protocol_>
  uint32_t write(Protocol_* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(TLiteralPredicate &a, TLiteralPredicate &b);

std::ostream& operator<<(std::ostream& out, const TLiteralPredicate& obj);


class TTupleIsNullPredicate {
 public:

  TTupleIsNullPredicate(const TTupleIsNullPredicate&);
  TTupleIsNullPredicate(TTupleIsNullPredicate&&);
  TTupleIsNullPredicate& operator=(const TTupleIsNullPredicate&);
  TTupleIsNullPredicate& operator=(TTupleIsNullPredicate&&);
  TTupleIsNullPredicate() {
  }

  virtual ~TTupleIsNullPredicate() throw();
  std::vector< ::impala::TTupleId>  tuple_ids;

  void __set_tuple_ids(const std::vector< ::impala::TTupleId> & val);

  template <class Protocol_>
  uint32_t read(Protocol_* iprot);
  template <class Protocol_>
  uint32_t write(Protocol_* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(TTupleIsNullPredicate &a, TTupleIsNullPredicate &b);

std::ostream& operator<<(std::ostream& out, const TTupleIsNullPredicate& obj);


class TSlotRef {
 public:

  TSlotRef(const TSlotRef&);
  TSlotRef(TSlotRef&&);
  TSlotRef& operator=(const TSlotRef&);
  TSlotRef& operator=(TSlotRef&&);
  TSlotRef() : slot_id(0) {
  }

  virtual ~TSlotRef() throw();
   ::impala::TSlotId slot_id;

  void __set_slot_id(const  ::impala::TSlotId val);

  template <class Protocol_>
  uint32_t read(Protocol_* iprot);
  template <class Protocol_>
  uint32_t write(Protocol_* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(TSlotRef &a, TSlotRef &b);

std::ostream& operator<<(std::ostream& out, const TSlotRef& obj);


class TStringLiteral {
 public:

  TStringLiteral(const TStringLiteral&);
  TStringLiteral(TStringLiteral&&);
  TStringLiteral& operator=(const TStringLiteral&);
  TStringLiteral& operator=(TStringLiteral&&);
  TStringLiteral() : value() {
  }

  virtual ~TStringLiteral() throw();
  std::string value;

  void __set_value(const std::string& val);

  template <class Protocol_>
  uint32_t read(Protocol_* iprot);
  template <class Protocol_>
  uint32_t write(Protocol_* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(TStringLiteral &a, TStringLiteral &b);

std::ostream& operator<<(std::ostream& out, const TStringLiteral& obj);


class TAggregateExpr {
 public:

  TAggregateExpr(const TAggregateExpr&);
  TAggregateExpr(TAggregateExpr&&);
  TAggregateExpr& operator=(const TAggregateExpr&);
  TAggregateExpr& operator=(TAggregateExpr&&);
  TAggregateExpr() : is_merge_agg(0) {
  }

  virtual ~TAggregateExpr() throw();
  bool is_merge_agg;
  std::vector< ::impala::TColumnType>  arg_types;

  void __set_is_merge_agg(const bool val);

  void __set_arg_types(const std::vector< ::impala::TColumnType> & val);

  template <class Protocol_>
  uint32_t read(Protocol_* iprot);
  template <class Protocol_>
  uint32_t write(Protocol_* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(TAggregateExpr &a, TAggregateExpr &b);

std::ostream& operator<<(std::ostream& out, const TAggregateExpr& obj);


class TKuduPartitionExpr {
 public:

  TKuduPartitionExpr(const TKuduPartitionExpr&);
  TKuduPartitionExpr(TKuduPartitionExpr&&);
  TKuduPartitionExpr& operator=(const TKuduPartitionExpr&);
  TKuduPartitionExpr& operator=(TKuduPartitionExpr&&);
  TKuduPartitionExpr() : target_table_id(0) {
  }

  virtual ~TKuduPartitionExpr() throw();
   ::impala::TTableId target_table_id;
  std::vector<int32_t>  referenced_columns;

  void __set_target_table_id(const  ::impala::TTableId val);

  void __set_referenced_columns(const std::vector<int32_t> & val);

  template <class Protocol_>
  uint32_t read(Protocol_* iprot);
  template <class Protocol_>
  uint32_t write(Protocol_* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(TKuduPartitionExpr &a, TKuduPartitionExpr &b);

std::ostream& operator<<(std::ostream& out, const TKuduPartitionExpr& obj);


class TCastExpr {
 public:

  TCastExpr(const TCastExpr&);
  TCastExpr(TCastExpr&&);
  TCastExpr& operator=(const TCastExpr&);
  TCastExpr& operator=(TCastExpr&&);
  TCastExpr() : cast_format() {
  }

  virtual ~TCastExpr() throw();
  std::string cast_format;

  void __set_cast_format(const std::string& val);

  template <class Protocol_>
  uint32_t read(Protocol_* iprot);
  template <class Protocol_>
  uint32_t write(Protocol_* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(TCastExpr &a, TCastExpr &b);

std::ostream& operator<<(std::ostream& out, const TCastExpr& obj);

typedef struct _TExprNode__isset {
  _TExprNode__isset() : fn(false), vararg_start_idx(false), bool_literal(false), case_expr(false), date_literal(false), float_literal(false), int_literal(false), in_predicate(false), is_null_pred(false), literal_pred(false), slot_ref(false), string_literal(false), tuple_is_null_pred(false), decimal_literal(false), agg_expr(false), timestamp_literal(false), kudu_partition_expr(false), cast_expr(false), is_codegen_disabled(false) {}
  bool fn :1;
  bool vararg_start_idx :1;
  bool bool_literal :1;
  bool case_expr :1;
  bool date_literal :1;
  bool float_literal :1;
  bool int_literal :1;
  bool in_predicate :1;
  bool is_null_pred :1;
  bool literal_pred :1;
  bool slot_ref :1;
  bool string_literal :1;
  bool tuple_is_null_pred :1;
  bool decimal_literal :1;
  bool agg_expr :1;
  bool timestamp_literal :1;
  bool kudu_partition_expr :1;
  bool cast_expr :1;
  bool is_codegen_disabled :1;
} _TExprNode__isset;

class TExprNode {
 public:

  TExprNode(const TExprNode&);
  TExprNode(TExprNode&&);
  TExprNode& operator=(const TExprNode&);
  TExprNode& operator=(TExprNode&&);
  TExprNode() : node_type((TExprNodeType::type)0), num_children(0), is_constant(0), vararg_start_idx(0), is_codegen_disabled(0) {
  }

  virtual ~TExprNode() throw();
  TExprNodeType::type node_type;
   ::impala::TColumnType type;
  int32_t num_children;
  bool is_constant;
   ::impala::TFunction fn;
  int32_t vararg_start_idx;
  TBoolLiteral bool_literal;
  TCaseExpr case_expr;
  TDateLiteral date_literal;
  TFloatLiteral float_literal;
  TIntLiteral int_literal;
  TInPredicate in_predicate;
  TIsNullPredicate is_null_pred;
  TLiteralPredicate literal_pred;
  TSlotRef slot_ref;
  TStringLiteral string_literal;
  TTupleIsNullPredicate tuple_is_null_pred;
  TDecimalLiteral decimal_literal;
  TAggregateExpr agg_expr;
  TTimestampLiteral timestamp_literal;
  TKuduPartitionExpr kudu_partition_expr;
  TCastExpr cast_expr;
  bool is_codegen_disabled;

  _TExprNode__isset __isset;

  void __set_node_type(const TExprNodeType::type val);

  void __set_type(const  ::impala::TColumnType& val);

  void __set_num_children(const int32_t val);

  void __set_is_constant(const bool val);

  void __set_fn(const  ::impala::TFunction& val);

  void __set_vararg_start_idx(const int32_t val);

  void __set_bool_literal(const TBoolLiteral& val);

  void __set_case_expr(const TCaseExpr& val);

  void __set_date_literal(const TDateLiteral& val);

  void __set_float_literal(const TFloatLiteral& val);

  void __set_int_literal(const TIntLiteral& val);

  void __set_in_predicate(const TInPredicate& val);

  void __set_is_null_pred(const TIsNullPredicate& val);

  void __set_literal_pred(const TLiteralPredicate& val);

  void __set_slot_ref(const TSlotRef& val);

  void __set_string_literal(const TStringLiteral& val);

  void __set_tuple_is_null_pred(const TTupleIsNullPredicate& val);

  void __set_decimal_literal(const TDecimalLiteral& val);

  void __set_agg_expr(const TAggregateExpr& val);

  void __set_timestamp_literal(const TTimestampLiteral& val);

  void __set_kudu_partition_expr(const TKuduPartitionExpr& val);

  void __set_cast_expr(const TCastExpr& val);

  void __set_is_codegen_disabled(const bool val);

  template <class Protocol_>
  uint32_t read(Protocol_* iprot);
  template <class Protocol_>
  uint32_t write(Protocol_* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(TExprNode &a, TExprNode &b);

std::ostream& operator<<(std::ostream& out, const TExprNode& obj);


class TExpr {
 public:

  TExpr(const TExpr&);
  TExpr(TExpr&&);
  TExpr& operator=(const TExpr&);
  TExpr& operator=(TExpr&&);
  TExpr() {
  }

  virtual ~TExpr() throw();
  std::vector<TExprNode>  nodes;

  void __set_nodes(const std::vector<TExprNode> & val);

  template <class Protocol_>
  uint32_t read(Protocol_* iprot);
  template <class Protocol_>
  uint32_t write(Protocol_* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(TExpr &a, TExpr &b);

std::ostream& operator<<(std::ostream& out, const TExpr& obj);


class TExprBatch {
 public:

  TExprBatch(const TExprBatch&);
  TExprBatch(TExprBatch&&);
  TExprBatch& operator=(const TExprBatch&);
  TExprBatch& operator=(TExprBatch&&);
  TExprBatch() {
  }

  virtual ~TExprBatch() throw();
  std::vector<TExpr>  exprs;

  void __set_exprs(const std::vector<TExpr> & val);

  template <class Protocol_>
  uint32_t read(Protocol_* iprot);
  template <class Protocol_>
  uint32_t write(Protocol_* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(TExprBatch &a, TExprBatch &b);

std::ostream& operator<<(std::ostream& out, const TExprBatch& obj);

} // namespace

#include "Exprs_types.tcc"

#endif
