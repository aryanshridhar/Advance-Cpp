#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// Creates a adjacency list for the whole graph.
class Graph {
public:
  int V; // number of vertices
  int E; // number of edges
  vector<int> *edges;

  Graph(int v, int e, vector<vector<int>> edge) {
    V = v;
    E = e;
    edges = new vector<int>[v];

    for (int i = 0; i < edge.size(); i++) {
      int vertex1 = edge[i][0];
      int vertex2 = edge[i][1];

      edges[vertex1].push_back(vertex2);
      edges[vertex2].push_back(vertex1);
    }
  }

  void dfsUtil(int v, vector<int> &visi) {
    for (auto vertex : edges[v]) {
      if (visi[vertex] == 0) {
        cout << vertex << " ";
        visi[vertex] = 1;
        dfsUtil(vertex, visi);
      }
    }
  }

  void dfs() {
    vector<int> visi(V + 1, 0);
    for (int i = 0; i < V; i++) {
      if (visi[i] == 0) {
        visi[i] = 1;
        cout << i << " ";
        dfsUtil(i, visi);
      }
    }
  }
};

int main() {
  vector<vector<int>> edges{{0, 1}, {1, 4}, {4, 6}, {0, 2}, {1, 3}, {2, 5}};
  Graph *g1 = new Graph(7, 6, edges);

  // clang-format off

    // 0 - 1 - 4 - 6
    // |   |
    // 2   3
    // |
    // 5

  // clang-format on
  g1->dfs();
  return 0;
}