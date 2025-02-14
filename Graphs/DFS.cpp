#include <bits/stdc++.h>
using namespace std;

struct Graph {
  size_t n;
  vector<vector<size_t>> graph;
  vector<size_t> visited;

  explicit Graph(size_t n) : n(n), graph(n), visited(n, 0) {}

  virtual void addEdge(size_t a, size_t b) {
    graph[a].push_back(b);
    graph[b].push_back(a);
  }

  void dfs(size_t v) {
    visited[v] = 1;

    for (size_t to : graph[v]) {
      if (visited[to] == 0) {
        dfs(to);
      }
    }
  }
};

struct DirectedGraph : Graph {
  explicit DirectedGraph(size_t n) : Graph(n) {}

  void addEdge(size_t a, size_t b) override {
    graph[a].push_back(b);
  }
};