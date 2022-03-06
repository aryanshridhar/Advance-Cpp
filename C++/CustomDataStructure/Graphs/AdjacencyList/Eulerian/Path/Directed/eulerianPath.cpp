#include <iostream>
#include <queue>
#include <string.h>
#include <vector>

using namespace std;

// Creates a adjacency matrix for the whole graph.
class Graph {
public:
  int n;
  vector<int> adj[10000];
  vector<vector<int>> edges;

  Graph(int num, vector<vector<int>> edge) {
    n = num;
    for (int i = 0; i < edge.size(); i++) {
      int vertex1 = edge[i][0];
      int vertex2 = edge[i][1];

      adj[vertex1].push_back(vertex2);
    }

    edges = edge;
  }

  bool checkIfPathExists() {
    vector<int> degrees(n, 0);
    for (auto e : edges) {
      degrees[e[0]]++;
      degrees[e[1]]++;
    }

    for (int i = 0; i < n; i++) {
      if (degrees[i] % 2 != 0) {
        return false;
      }
    }

    return true;
  }

  void getCircuit() {
    if (!checkIfPathExists()) {
      cout << "Circuit doesn't exists" << endl;
    }
  }
};

int main() {
  vector<vector<int>> edges{};
  Graph *g1 = new Graph(12, edges); // 1->12
  return 0;
}