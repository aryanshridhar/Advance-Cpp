#include <iostream>
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

  void displaymatrix() {
    for (int i = 0; i < V; i++) {
      cout << i << " ---> ";
      for (int j = 0; j < edges[i].size(); j++) {
        cout << edges[i][j] << " ";
      }
      cout << endl;
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

  g1->displaymatrix();

  return 0;
}