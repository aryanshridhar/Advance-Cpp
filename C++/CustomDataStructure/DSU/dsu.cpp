#include <iostream>

using namespace std;

const int N = 1e5 + 10;

// TC: O(4*alpha) - Amortized O(1).
class DSU {
public:
  int parent[N];
  int size[N];

  void add(int v) {
    parent[v] = v;
    size[v] = 1;
  }

  void unionn(int a, int b) {
    int root_a = find(a);
    int root_b = find(b);

    // Always attach a smaller tree to the bigger tree. (Union by size)
    if (root_a != root_b) {
      if (size[root_a] > size[root_b]) {
        parent[root_b] = root_a;
        size[root_a] += size[root_b];
      } else {
        parent[root_a] = root_b;
        size[root_b] += size[root_a];
      }
    }
  }

  int find(int v) {
    if (v == parent[v]) {
      return v;
    }
    // Path compression.
    return parent[v] = find(parent[v]);
  }
};

int main() { return 0; }