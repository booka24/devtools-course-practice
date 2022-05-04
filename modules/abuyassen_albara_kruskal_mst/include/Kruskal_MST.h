// Copyright 2022 Abuyassen Albara

#ifndef MODULES_ABUYASSEN_ALBARA_KRUSKAL_MST_INCLUDE_KRUSKAL_MST_H_
#define MODULES_ABUYASSEN_ALBARA_KRUSKAL_MST_INCLUDE_KRUSKAL_MST_H_

#include <vector>

struct node {
  int parent;
  unsigned int rank;

  node();
  node(const int parent_, const unsigned int rank_);
};

struct Edge {
  unsigned int src;
  unsigned int dst;
  int weight;

  Edge();
  Edge(const unsigned int src_, const unsigned int dst_, const int weight_);
  bool operator == (const Edge & a);
};

bool comparator(Edge a, Edge b);

class Graph {
 public:
    Graph(const unsigned int edges_, const unsigned int vertices_);

    Graph(const Graph & graph);

    int getVerticesCount() const;

    int getEdgesCount() const;

    void setEdgesCount(const unsigned int e);

    void insertEdge(const Edge & edge);

    bool contains(const Edge & edge);

    std::vector < Edge > KruskalMST();

 private:
    int findAbsoluteParent(const unsigned int index);
    void union_op(const unsigned int fromP, const unsigned int toP);
    unsigned int V;  // number of vertices
    unsigned int E;  // number of edges
    std::vector < node > vertices;
    std::vector < Edge > edges;
};

#endif  // MODULES_ABUYASSEN_ALBARA_KRUSKAL_MST_INCLUDE_KRUSKAL_MST_H_
