#include <bits/stdc++.h>
using namespace std;

struct DSU {
  size_t n;
  vector<size_t> parent;
  vector<size_t> rank;

  explicit DSU(size_t n) : n(n), parent(n, 0), rank(n, 0) {
    for (size_t i = 0; i < n; ++i) {
      this->parent[i] = i;
    }
  }

  size_t leader(size_t v) {
    if (this->parent[v] == v) {
      return v;
    }

    this->parent[v] = leader(this->parent[v]);
    return this->parent[v];
  }

  void unite(size_t a, size_t b) {
    a = leader(a);
    b = leader(b);

    if (a == b) {
      return;
    }

    if (this->rank[a] > this->rank[b]) {
      swap(a,b);
    }

    this->parent[a] = b;
    this->rank[b] = max(this->rank[a] + 1, this->rank[b]);
  }
};
