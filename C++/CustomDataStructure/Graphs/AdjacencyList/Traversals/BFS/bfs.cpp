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
  void bfs() {
    vector<int> visi(V + 1, 0);
    // Traverse for all componenets in graph. (In this case, the grpah has only
    // a single component).
    for (int i = 0; i < V; i++) {
      if (visi[i] == 0) {
        queue<int> q;
        q.push(i);
        visi[i] = 1;

        while (!q.empty()) {
          int current = q.front();
          q.pop();
          // Traverse for all its adjacent vertices and only traverse them if
          // not visited.
          for (int vertex : edges[current]) {
            if (visi[vertex] == 0) {
              cout << vertex << " ";
              q.push(vertex);
              visi[vertex] = 1;
            }
          }
        }
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
  g1->bfs();
  return 0;
}