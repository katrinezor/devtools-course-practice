// Copyright 2017 Kalinin Vladimir

#ifndef MODULES_DIJKSTRA_INCLUDE_GRAPH_H_
#define MODULES_DIJKSTRA_INCLUDE_GRAPH_H_

struct Edge {
 public:
  Edge();
  Edge(const int _weight, const int _key);
  void SetNext(Edge* _next);
  Edge* GetNext();
  int GetWeight();
  int GetKey();

 private:
  int weight_;
  int key_;
  Edge* next_;
};

class Graph {
 public:
  Graph();
  explicit Graph(int size);

  void AddEdge(const int _weight, const int key1, const int key2);
  bool IsConnect(const int key1, const int key2);
  int GetSize();
  Edge* GetNode(int n);

  int * Dijkstra(int node_index);

 private:
  int size_;
  Edge **node_;
};

#endif  // MODULES_DIJKSTRA_INCLUDE_GRAPH_H_
