/**
 * Autogenerated by Thrift Compiler (0.11.0)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#include "LineageGraph_types.h"

#include <algorithm>
#include <ostream>

#include <thrift/TToString.h>

namespace impala {

int _kTEdgeTypeValues[] = {
  TEdgeType::PROJECTION,
  TEdgeType::PREDICATE
};
const char* _kTEdgeTypeNames[] = {
  "PROJECTION",
  "PREDICATE"
};
const std::map<int, const char*> _TEdgeType_VALUES_TO_NAMES(::apache::thrift::TEnumIterator(2, _kTEdgeTypeValues, _kTEdgeTypeNames), ::apache::thrift::TEnumIterator(-1, NULL, NULL));

std::ostream& operator<<(std::ostream& out, const TEdgeType::type& val) {
  std::map<int, const char*>::const_iterator it = _TEdgeType_VALUES_TO_NAMES.find(val);
  if (it != _TEdgeType_VALUES_TO_NAMES.end()) {
    out << it->second;
  } else {
    out << static_cast<int>(val);
  }
  return out;
}


TVertexMetadata::~TVertexMetadata() throw() {
}


void TVertexMetadata::__set_table_name(const std::string& val) {
  this->table_name = val;
}

void TVertexMetadata::__set_table_create_time(const int64_t val) {
  this->table_create_time = val;
}
std::ostream& operator<<(std::ostream& out, const TVertexMetadata& obj)
{
  obj.printTo(out);
  return out;
}


void swap(TVertexMetadata &a, TVertexMetadata &b) {
  using ::std::swap;
  swap(a.table_name, b.table_name);
  swap(a.table_create_time, b.table_create_time);
}

TVertexMetadata::TVertexMetadata(const TVertexMetadata& other0) {
  table_name = other0.table_name;
  table_create_time = other0.table_create_time;
}
TVertexMetadata::TVertexMetadata( TVertexMetadata&& other1) {
  table_name = std::move(other1.table_name);
  table_create_time = std::move(other1.table_create_time);
}
TVertexMetadata& TVertexMetadata::operator=(const TVertexMetadata& other2) {
  table_name = other2.table_name;
  table_create_time = other2.table_create_time;
  return *this;
}
TVertexMetadata& TVertexMetadata::operator=(TVertexMetadata&& other3) {
  table_name = std::move(other3.table_name);
  table_create_time = std::move(other3.table_create_time);
  return *this;
}
void TVertexMetadata::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "TVertexMetadata(";
  out << "table_name=" << to_string(table_name);
  out << ", " << "table_create_time=" << to_string(table_create_time);
  out << ")";
}


TVertex::~TVertex() throw() {
}


void TVertex::__set_id(const int64_t val) {
  this->id = val;
}

void TVertex::__set_label(const std::string& val) {
  this->label = val;
}

void TVertex::__set_metadata(const TVertexMetadata& val) {
  this->metadata = val;
__isset.metadata = true;
}
std::ostream& operator<<(std::ostream& out, const TVertex& obj)
{
  obj.printTo(out);
  return out;
}


void swap(TVertex &a, TVertex &b) {
  using ::std::swap;
  swap(a.id, b.id);
  swap(a.label, b.label);
  swap(a.metadata, b.metadata);
  swap(a.__isset, b.__isset);
}

TVertex::TVertex(const TVertex& other4) {
  id = other4.id;
  label = other4.label;
  metadata = other4.metadata;
  __isset = other4.__isset;
}
TVertex::TVertex( TVertex&& other5) {
  id = std::move(other5.id);
  label = std::move(other5.label);
  metadata = std::move(other5.metadata);
  __isset = std::move(other5.__isset);
}
TVertex& TVertex::operator=(const TVertex& other6) {
  id = other6.id;
  label = other6.label;
  metadata = other6.metadata;
  __isset = other6.__isset;
  return *this;
}
TVertex& TVertex::operator=(TVertex&& other7) {
  id = std::move(other7.id);
  label = std::move(other7.label);
  metadata = std::move(other7.metadata);
  __isset = std::move(other7.__isset);
  return *this;
}
void TVertex::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "TVertex(";
  out << "id=" << to_string(id);
  out << ", " << "label=" << to_string(label);
  out << ", " << "metadata="; (__isset.metadata ? (out << to_string(metadata)) : (out << "<null>"));
  out << ")";
}


TMultiEdge::~TMultiEdge() throw() {
}


void TMultiEdge::__set_sources(const std::vector<TVertex> & val) {
  this->sources = val;
}

void TMultiEdge::__set_targets(const std::vector<TVertex> & val) {
  this->targets = val;
}

void TMultiEdge::__set_edgetype(const TEdgeType::type val) {
  this->edgetype = val;
}
std::ostream& operator<<(std::ostream& out, const TMultiEdge& obj)
{
  obj.printTo(out);
  return out;
}


void swap(TMultiEdge &a, TMultiEdge &b) {
  using ::std::swap;
  swap(a.sources, b.sources);
  swap(a.targets, b.targets);
  swap(a.edgetype, b.edgetype);
  swap(a.__isset, b.__isset);
}

TMultiEdge::TMultiEdge(const TMultiEdge& other21) {
  sources = other21.sources;
  targets = other21.targets;
  edgetype = other21.edgetype;
  __isset = other21.__isset;
}
TMultiEdge::TMultiEdge( TMultiEdge&& other22) {
  sources = std::move(other22.sources);
  targets = std::move(other22.targets);
  edgetype = std::move(other22.edgetype);
  __isset = std::move(other22.__isset);
}
TMultiEdge& TMultiEdge::operator=(const TMultiEdge& other23) {
  sources = other23.sources;
  targets = other23.targets;
  edgetype = other23.edgetype;
  __isset = other23.__isset;
  return *this;
}
TMultiEdge& TMultiEdge::operator=(TMultiEdge&& other24) {
  sources = std::move(other24.sources);
  targets = std::move(other24.targets);
  edgetype = std::move(other24.edgetype);
  __isset = std::move(other24.__isset);
  return *this;
}
void TMultiEdge::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "TMultiEdge(";
  out << "sources=" << to_string(sources);
  out << ", " << "targets=" << to_string(targets);
  out << ", " << "edgetype=" << to_string(edgetype);
  out << ")";
}


TLineageGraph::~TLineageGraph() throw() {
}


void TLineageGraph::__set_query_text(const std::string& val) {
  this->query_text = val;
}

void TLineageGraph::__set_hash(const std::string& val) {
  this->hash = val;
}

void TLineageGraph::__set_user(const std::string& val) {
  this->user = val;
}

void TLineageGraph::__set_started(const int64_t val) {
  this->started = val;
}

void TLineageGraph::__set_ended(const int64_t val) {
  this->ended = val;
__isset.ended = true;
}

void TLineageGraph::__set_edges(const std::vector<TMultiEdge> & val) {
  this->edges = val;
}

void TLineageGraph::__set_vertices(const std::vector<TVertex> & val) {
  this->vertices = val;
}

void TLineageGraph::__set_query_id(const  ::impala::TUniqueId& val) {
  this->query_id = val;
}

void TLineageGraph::__set_table_location(const std::string& val) {
  this->table_location = val;
__isset.table_location = true;
}
std::ostream& operator<<(std::ostream& out, const TLineageGraph& obj)
{
  obj.printTo(out);
  return out;
}


void swap(TLineageGraph &a, TLineageGraph &b) {
  using ::std::swap;
  swap(a.query_text, b.query_text);
  swap(a.hash, b.hash);
  swap(a.user, b.user);
  swap(a.started, b.started);
  swap(a.ended, b.ended);
  swap(a.edges, b.edges);
  swap(a.vertices, b.vertices);
  swap(a.query_id, b.query_id);
  swap(a.table_location, b.table_location);
  swap(a.__isset, b.__isset);
}

TLineageGraph::TLineageGraph(const TLineageGraph& other37) {
  query_text = other37.query_text;
  hash = other37.hash;
  user = other37.user;
  started = other37.started;
  ended = other37.ended;
  edges = other37.edges;
  vertices = other37.vertices;
  query_id = other37.query_id;
  table_location = other37.table_location;
  __isset = other37.__isset;
}
TLineageGraph::TLineageGraph( TLineageGraph&& other38) {
  query_text = std::move(other38.query_text);
  hash = std::move(other38.hash);
  user = std::move(other38.user);
  started = std::move(other38.started);
  ended = std::move(other38.ended);
  edges = std::move(other38.edges);
  vertices = std::move(other38.vertices);
  query_id = std::move(other38.query_id);
  table_location = std::move(other38.table_location);
  __isset = std::move(other38.__isset);
}
TLineageGraph& TLineageGraph::operator=(const TLineageGraph& other39) {
  query_text = other39.query_text;
  hash = other39.hash;
  user = other39.user;
  started = other39.started;
  ended = other39.ended;
  edges = other39.edges;
  vertices = other39.vertices;
  query_id = other39.query_id;
  table_location = other39.table_location;
  __isset = other39.__isset;
  return *this;
}
TLineageGraph& TLineageGraph::operator=(TLineageGraph&& other40) {
  query_text = std::move(other40.query_text);
  hash = std::move(other40.hash);
  user = std::move(other40.user);
  started = std::move(other40.started);
  ended = std::move(other40.ended);
  edges = std::move(other40.edges);
  vertices = std::move(other40.vertices);
  query_id = std::move(other40.query_id);
  table_location = std::move(other40.table_location);
  __isset = std::move(other40.__isset);
  return *this;
}
void TLineageGraph::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "TLineageGraph(";
  out << "query_text=" << to_string(query_text);
  out << ", " << "hash=" << to_string(hash);
  out << ", " << "user=" << to_string(user);
  out << ", " << "started=" << to_string(started);
  out << ", " << "ended="; (__isset.ended ? (out << to_string(ended)) : (out << "<null>"));
  out << ", " << "edges=" << to_string(edges);
  out << ", " << "vertices=" << to_string(vertices);
  out << ", " << "query_id=" << to_string(query_id);
  out << ", " << "table_location="; (__isset.table_location ? (out << to_string(table_location)) : (out << "<null>"));
  out << ")";
}

} // namespace
