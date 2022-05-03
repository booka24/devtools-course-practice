// Copyright 2022 Abuyassen Albara

#include <vector>

#include <algorithm>

#include "include/Kruskal_MST.h"

node::node(): parent(-1), rank(0) {}

node::node(const int parent_, const unsigned int rank_):
    parent(parent_), rank(rank_) {}

Edge::Edge(): src(0), dst(0), weight(0) {}

Edge::Edge(const unsigned int src_, const unsigned int dst_,
    const int weight_):
src(src_), dst(dst_), weight(weight_) {}

bool Edge::operator == (const Edge & a) {
  return src == a.src && dst == a.dst && weight == a.weight;
}

bool comparator(Edge a, Edge b) {
  return a.weight < b.weight;
}

Graph::Graph(const unsigned int edges_,
  const unsigned int vertices_): V(vertices_), E(edges_) {
  vertices = std::vector < node > (vertices_);
  edges = std::vector < Edge > ();
}

Graph::Graph(const Graph & graph): V(graph.V), E(graph.E) {
  vertices = graph.vertices;
  edges = graph.edges;
}

int Graph::getVerticesCount() const {
  return V;
}

int Graph::getEdgesCount() const {
  return E;
}

void Graph::setEdgesCount(const unsigned int e) {
  if (e >= E)
    E = e;
  else
    throw "The new number of edges should should be biger than :" + E;
}

void Graph::insertEdge(const Edge & edge) {
  if (edge.src >= V || edge.dst >= V)
    throw "out of range";
  else if (static_cast<unsigned int>(edges.size()) == E)
    throw "cannot insert more elemnts";
  edges.push_back(edge);
}

bool Graph::contains(const Edge & edge) {
  if (edges.empty())
    return false;
  return std::count(edges.begin(), edges.end(), edge);
}

int Graph::findAbsoluteParent(const unsigned int index) {
  if (vertices[index].parent == -1)
    return index;
  return vertices[index].parent = findAbsoluteParent(vertices[index].parent);
}

std::vector < Edge > Graph::KruskalMST() {
  sort(edges.begin(), edges.end(), comparator);
  std::vector < Edge > MST;

  unsigned int i = 0, j = 0;
  while (i < V - 1 && j < E) {
    // FIND absolute parent of subset
    int fromP = findAbsoluteParent(edges[j].src);
    int toP = findAbsoluteParent(edges[j].dst);

    if (fromP == toP) {
      ++j;
      continue;
    }

    // UNION operation
    union_op(fromP, toP);  // UNION of 2 sets
    MST.push_back(edges[j]);
    ++i;
  }
  return MST;
}

void Graph::union_op(const unsigned int fromP, const unsigned int toP) {
  if (vertices[fromP].rank > vertices[toP].rank) {  // fromP has higher rank
    vertices[toP].parent = fromP;
  } else if (vertices[fromP].rank < vertices[toP].rank) {
      vertices[fromP].parent = toP;  // toP has higher rank
  } else {
    // Both have same rank and so anyone can be made as parent
    vertices[fromP].parent = toP;
    vertices[toP].rank += 1;  // Increase rank of parent
  }
}
