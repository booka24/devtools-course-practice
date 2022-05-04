// Copyright 2022 Abuyassen Albara

#include <gtest/gtest.h>

#include <algorithm>

#include <vector>

#include "include/Kruskal_MST.h"

TEST(Kruskal_Algorithm, Trows_if_edge_out_of_range) {
  int V = 3;
  int E = 3;
  int src = 4;
  int dst = 5;
  int weight = 3;
  Edge edge(src, dst, weight);
  Graph sample(E, V);

  EXPECT_ANY_THROW(sample.insertEdge(edge));
}

TEST(Kruskal_Algorithm, Throws_if_full) {
  int V = 3;
  int E = 3;
  int srcs[] = { 0, 1, 2 };
  int dsts[] = { 1, 2, 0 };
  int weights[] = { 3, 2, 1 };

  Graph sample(E, V);
  for (int i = 0; i < E; i++) {
    Edge temp(srcs[i], dsts[i], weights[i]);
    sample.insertEdge(temp);
  }

  Edge edge(1, 2, 3);
  EXPECT_ANY_THROW(sample.insertEdge(edge));
}

TEST(Kruskal_Algorithm, set_new_number_of_edges) {
  int V = 3;
  int E = 3;
  int srcs[] = { 0, 1, 2 };
  int dsts[] = { 1, 2, 0 };
  int weights[] = { 3, 2, 1 };

  Graph sample(E, V);
  for (int i = 0; i < E; i++) {
    Edge temp(srcs[i], dsts[i], weights[i]);
    sample.insertEdge(temp);
  }
  sample.setEdgesCount(4);
  Edge edge(1, 2, 3);
  EXPECT_NO_THROW(sample.insertEdge(edge));
}

TEST(Kruskal_Algorithm, cannot_set_smaller_number_of_edges) {
  int V = 3;
  int E = 3;
  int srcs[] = { 0, 1, 2 };
  int dsts[] = { 1, 2, 0 };
  int weights[] = { 3, 2, 1 };

  Graph sample(E, V);
  for (int i = 0; i < E; i++) {
    Edge temp(srcs[i], dsts[i], weights[i]);
    sample.insertEdge(temp);
  }
  EXPECT_ANY_THROW(sample.setEdgesCount(2));
}

TEST(Kruskal_Algorithm, can_get_vertices) {
  int V = 3;
  int E = 3;

  Graph sample(E, V);

  EXPECT_EQ(sample.getVerticesCount(), V);
}

TEST(Kruskal_Algorithm, can_get_edges) {
  int V = 3;
  int E = 3;

  Graph sample(E, V);

  EXPECT_EQ(sample.getEdgesCount(), V);
}

TEST(Kruskal_Algorithm, can_insert_edge) {
  int V = 2;
  int E = 1;
  Edge edge(0, 1, 0);

  Graph sample(E, V);
  sample.insertEdge(edge);

  EXPECT_TRUE(sample.contains(edge));
}

TEST(Kruskal_Algorithm, contains_function_returns_false_if_empty) {
  int V = 3;
  int E = 3;
  Edge edge(0, 1, 2);
  Graph sample(E, V);

  EXPECT_FALSE(sample.contains(edge));
}

TEST(Kruskal_Algorithm, Kruskal_works) {
  int V = 5;
  int E = 5;
  int srcs[] = { 0, 1, 2, 3, 4 };
  int dsts[] = { 1, 2, 3, 4, 0 };
  int weights[] = { 2, 2, 1, 1, 3 };

  Graph sample(E, V);
  for (int i = 0; i < E; i++) {
    Edge temp(srcs[i], dsts[i], weights[i]);
    sample.insertEdge(temp);
  }

  std::vector < Edge > result = sample.KruskalMST();
  std::vector < Edge > check = {
    Edge(2, 3, 1),
    Edge(3, 4, 1),
    Edge(0, 1, 2),
    Edge(1, 2, 2),
  };

  for (size_t i = 0; i < result.size(); i++)
    EXPECT_TRUE(check[i] == result[i]);
}

TEST(Kruskal_Algorithm, always_have_correct_size) {
  int V = 3;
  int E = 3;
  int srcs[] = { 0, 1, 2 };
  int dsts[] = { 1, 2, 0 };
  int weights[] = { 3, 2, 1 };

  Graph sample(E, V);
  for (int i = 0; i < E; i++) {
    Edge temp(srcs[i], dsts[i], weights[i]);
    sample.insertEdge(temp);
  }

  std::vector < Edge > result = sample.KruskalMST();

  EXPECT_EQ(static_cast<int>(result.size()), V - 1);
}

TEST(Kruskal_Algorithm, avoiding_cycles) {
  int V = 3;
  int E = 3;
  int srcs[] = { 0, 1, 2 };
  int dsts[] = { 1, 2, 0 };
  int weights[] = { 3, 2, 1 };

  Graph sample(E, V);
  for (int i = 0; i < E; i++) {
    Edge temp(srcs[i], dsts[i], weights[i]);
    sample.insertEdge(temp);
  }

  std::vector < Edge > result = sample.KruskalMST();

  EXPECT_FALSE(std::count(result.begin(), result.end(), Edge(0, 1, 3)));
}

TEST(Kruskal_Algorithm, always_have_minimum_cast) {
  int V = 5;
  int E = 5;
  int srcs[] = { 0, 1, 2, 3, 4 };
  int dsts[] = { 1, 2, 3, 4, 0 };
  int weights[] = { 2, 2, 1, 1, 3 };
  int minimum_cast = 6;

  Graph sample(E, V);
  for (int i = 0; i < E; i++) {
    Edge temp(srcs[i], dsts[i], weights[i]);
    sample.insertEdge(temp);
  }

  std::vector < Edge > result = sample.KruskalMST();

  int cast = 0;
  for (size_t i = 0; i < result.size(); i++)
    cast += result[i].weight;
  EXPECT_EQ(cast, minimum_cast);
}

TEST(Kruskal_Algorithm, edges_are_sortable) {
    int srcs[] = { 0, 1, 2, 3, 4 };
    int dsts[] = { 1, 2, 3, 4, 0 };
    int weights[] = { 2, 2, 1, 1, 3 };
    std::vector < Edge > result;

    for (int i = 0; i < 5; i++)
        result.push_back(Edge(srcs[i], dsts[i], weights[i]));
    sort(result.begin(), result.end(), comparator);

    std::vector < Edge > check = { Edge(2, 3, 1) , Edge(3, 4, 1),
        Edge(0, 1, 2), Edge(1, 2, 2), Edge(4, 0, 3) };

    for (size_t i = 0; i < result.size(); i++)
        EXPECT_TRUE(result[i] == check[i]);
}
