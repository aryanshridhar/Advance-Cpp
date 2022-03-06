#include <iostream>
#include <map>
#include <stack>
#include <unordered_map>
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

  vector<int> getDegree() {
    vector<int> degrees(n, 0);
    for (auto e : edges) {
      degrees[e[0]]++;
      degrees[e[1]]++;
    }

    return degrees;
  }

  bool checkIfCircuitExists() {
    vector<int> degrees = getDegree();

    for (int i = 0; i < n; i++) {
      if (degrees[i] % 2 != 0) {
        return false;
      }
    }

    return true;
  }

  void removeEdge(int node1, int node2,
                  vector<unordered_map<int, bool>> &graph) {
    graph[node1].erase(node2);
  }

  void dfs(int source, vector<unordered_map<int, bool>> &graph,
           stack<int> &circuit) {
    if (graph[source].size() == 0) {
      circuit.push(source);
      return;
    }

    for (auto adjacent : graph[source]) {
      if (adjacent.second) {
        removeEdge(source, adjacent.first, graph);
        removeEdge(adjacent.first, source, graph);
        dfs(adjacent.first, graph, circuit);
        if (graph[source].size() == 0) {
          circuit.push(source);
          break;
        }
      }
    }
  }

  void getCircuit() {
    if (!checkIfCircuitExists()) {
      cout << "Circuit doesn't exists" << endl;
    }
    // Since it's a circuit, we can start with any node.
    int source = 0;
    // We also need to remove edges from the graph,hence the graph
    // representation as below is much viable.

    vector<unordered_map<int, bool>> graph(n);
    stack<int> circuit;
    for (auto e : edges) {
      graph[e[0]][e[1]] = true;
      graph[e[1]][e[0]] = true;
    }

    dfs(source, graph, circuit);

    while (!circuit.empty()) {
      cout << circuit.top() << " ";
      circuit.pop();
    }
  };
};

int main() {
  vector<vector<int>> edges{{0, 1}, {1, 2}, {2, 3}, {3, 4},
                            {1, 3}, {1, 4}, {3, 5}, {5, 0}};
  Graph *g1 = new Graph(6, edges); // 0->5
  g1->getCircuit();
  return 0;
}