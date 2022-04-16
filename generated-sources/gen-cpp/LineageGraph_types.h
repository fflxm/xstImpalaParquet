/**
 * Autogenerated by Thrift Compiler (0.11.0)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef LineageGraph_TYPES_H
#define LineageGraph_TYPES_H

#include <iosfwd>

#include <thrift/Thrift.h>
#include <thrift/TApplicationException.h>
#include <thrift/TBase.h>
#include <thrift/protocol/TProtocol.h>
#include <thrift/transport/TTransport.h>

#include <thrift/stdcxx.h>
#include "Types_types.h"


namespace impala {

struct TEdgeType {
  enum type {
    PROJECTION = 0,
    PREDICATE = 1
  };
};

extern const std::map<int, const char*> _TEdgeType_VALUES_TO_NAMES;

std::ostream& operator<<(std::ostream& out, const TEdgeType::type& val);

class TVertexMetadata;

class TVertex;

class TMultiEdge;

class TLineageGraph;


class TVertexMetadata {
 public:

  TVertexMetadata(const TVertexMetadata&);
  TVertexMetadata(TVertexMetadata&&);
  TVertexMetadata& operator=(const TVertexMetadata&);
  TVertexMetadata& operator=(TVertexMetadata&&);
  TVertexMetadata() : table_name(), table_create_time(0) {
  }

  virtual ~TVertexMetadata() throw();
  std::string table_name;
  int64_t table_create_time;

  void __set_table_name(const std::string& val);

  void __set_table_create_time(const int64_t val);

  template <class Protocol_>
  uint32_t read(Protocol_* iprot);
  template <class Protocol_>
  uint32_t write(Protocol_* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(TVertexMetadata &a, TVertexMetadata &b);

std::ostream& operator<<(std::ostream& out, const TVertexMetadata& obj);

typedef struct _TVertex__isset {
  _TVertex__isset() : metadata(false) {}
  bool metadata :1;
} _TVertex__isset;

class TVertex {
 public:

  TVertex(const TVertex&);
  TVertex(TVertex&&);
  TVertex& operator=(const TVertex&);
  TVertex& operator=(TVertex&&);
  TVertex() : id(0), label() {
  }

  virtual ~TVertex() throw();
  int64_t id;
  std::string label;
  TVertexMetadata metadata;

  _TVertex__isset __isset;

  void __set_id(const int64_t val);

  void __set_label(const std::string& val);

  void __set_metadata(const TVertexMetadata& val);

  template <class Protocol_>
  uint32_t read(Protocol_* iprot);
  template <class Protocol_>
  uint32_t write(Protocol_* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(TVertex &a, TVertex &b);

std::ostream& operator<<(std::ostream& out, const TVertex& obj);

typedef struct _TMultiEdge__isset {
  _TMultiEdge__isset() : sources(false), targets(false), edgetype(false) {}
  bool sources :1;
  bool targets :1;
  bool edgetype :1;
} _TMultiEdge__isset;

class TMultiEdge {
 public:

  TMultiEdge(const TMultiEdge&);
  TMultiEdge(TMultiEdge&&);
  TMultiEdge& operator=(const TMultiEdge&);
  TMultiEdge& operator=(TMultiEdge&&);
  TMultiEdge() : edgetype((TEdgeType::type)0) {
  }

  virtual ~TMultiEdge() throw();
  std::vector<TVertex>  sources;
  std::vector<TVertex>  targets;
  TEdgeType::type edgetype;

  _TMultiEdge__isset __isset;

  void __set_sources(const std::vector<TVertex> & val);

  void __set_targets(const std::vector<TVertex> & val);

  void __set_edgetype(const TEdgeType::type val);

  template <class Protocol_>
  uint32_t read(Protocol_* iprot);
  template <class Protocol_>
  uint32_t write(Protocol_* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(TMultiEdge &a, TMultiEdge &b);

std::ostream& operator<<(std::ostream& out, const TMultiEdge& obj);

typedef struct _TLineageGraph__isset {
  _TLineageGraph__isset() : ended(false), edges(false), vertices(false), table_location(false) {}
  bool ended :1;
  bool edges :1;
  bool vertices :1;
  bool table_location :1;
} _TLineageGraph__isset;

class TLineageGraph {
 public:

  TLineageGraph(const TLineageGraph&);
  TLineageGraph(TLineageGraph&&);
  TLineageGraph& operator=(const TLineageGraph&);
  TLineageGraph& operator=(TLineageGraph&&);
  TLineageGraph() : query_text(), hash(), user(), started(0), ended(0), table_location() {
  }

  virtual ~TLineageGraph() throw();
  std::string query_text;
  std::string hash;
  std::string user;
  int64_t started;
  int64_t ended;
  std::vector<TMultiEdge>  edges;
  std::vector<TVertex>  vertices;
   ::impala::TUniqueId query_id;
  std::string table_location;

  _TLineageGraph__isset __isset;

  void __set_query_text(const std::string& val);

  void __set_hash(const std::string& val);

  void __set_user(const std::string& val);

  void __set_started(const int64_t val);

  void __set_ended(const int64_t val);

  void __set_edges(const std::vector<TMultiEdge> & val);

  void __set_vertices(const std::vector<TVertex> & val);

  void __set_query_id(const  ::impala::TUniqueId& val);

  void __set_table_location(const std::string& val);

  template <class Protocol_>
  uint32_t read(Protocol_* iprot);
  template <class Protocol_>
  uint32_t write(Protocol_* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(TLineageGraph &a, TLineageGraph &b);

std::ostream& operator<<(std::ostream& out, const TLineageGraph& obj);

} // namespace

#include "LineageGraph_types.tcc"

#endif