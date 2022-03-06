#include <iostream>
#include <vector>

using namespace std;

// Creates a adjacency matrix for the whole graph.
class Graph {
public:
  int V; // number of vertices
  int E; // number of edges
  vector<vector<int>> edges;

  Graph(int v, int e, vector<vector<int>> edge) {
    V = v;
    E = e;

    for (int i = 0; i < v + 1; i++) {
      vector<int> temp;
      for (int j = 0; j < v + 1; j++) {
        temp.push_back(0);
      }
      edges.push_back(temp);
    }

    for (int i = 0; i < edge.size(); i++) {
      int vertex1 = edge[i][0];
      int vertex2 = edge[i][1];
      int edge_weight = edge[i][2];

      edges[vertex1][vertex2] = edge_weight;
    }
  }

  void displaymatrix() {
    for (int i = 1; i < V + 1; i++) {
      cout << i << " -> ";
      for (int j = 1; j < V + 1; j++) {
        cout << edges[i][j] << " ";
      }
      cout << endl;
    }
  }

  void transitiveClosure() {
    bool transitive[V + 1][V + 1];
    for (int i = 1; i <= V; i++) {
      for (int j = 1; j <= V; j++) {
        if (i == j) {
          edges[i][j] = true;
          continue;
        }
        if (edges[i][j] != 0) {
          edges[i][j] = true;
        }
      }
    }
    for (int k = 1; k <= V; k++) {
      for (int i = 1; i <= V; i++) {
        for (int j = 1; j <= V; j++) {
          edges[i][j] =
              ((edges[i][j] == true) || (edges[i][k] && edges[k][j]) == true);
        }
      }
    }
  }
};

int main() {
  vector<vector<int>> edges{{1, 2, 1}, {2, 4, 2}, {4, 6, 1},
                            {4, 5, 3}, {5, 6, 2}, {2, 5, 1},
                            {3, 5, 2}, {2, 3, 2}, {1, 3, 5}};
  Graph *g1 = new Graph(6, 9, edges);
  cout << "Initial distances are " << endl;
  g1->displaymatrix();
  cout << "After floyd's warshall " << endl;
  g1->transitiveClosure();
  g1->displaymatrix();

  return 0;
}