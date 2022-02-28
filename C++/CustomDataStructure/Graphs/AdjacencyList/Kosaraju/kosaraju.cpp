#include <iostream>
#include <queue>
#include <stack>
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

  // Much similar to logic in topo sort i.e to push elemnts according to thier
  // finishing time.
  void getOrdering(int start, vector<int> adj[], vector<bool> &visi,
                   stack<int> &ordering) {
    visi[start] = true;
    for (auto adjacent : adj[start]) {
      if (visi[adjacent] == false) {
        getOrdering(adjacent, adj, visi, ordering);
      }
    }

    ordering.push(start);
  }

  void reverseDFS(int start, vector<int> transpose[], vector<bool> &visi_new) {
    cout << start << endl;
    visi_new[start] = true;
    for (auto adjacent : transpose[start]) {
      if (visi_new[adjacent] == false) {
        reverseDFS(adjacent, transpose, visi_new);
      }
    }
  }

  void kosaraju() {
    stack<int> ordering;
    vector<bool> visi(n + 1, false);
    vector<bool> visi_new(n + 1, false);
    for (int i = 1; i <= n; i++) {
      if (visi[i] == false) {
        getOrdering(i, adj, visi, ordering);
      }
    }

    vector<int> transpose[n + 1];
    for (int i = 0; i < edges.size(); i++) {
      int vertex1 = edges[i][0];
      int vertex2 = edges[i][1];

      transpose[vertex2].push_back(vertex1);
    }

    while (!ordering.empty()) {
      int node = ordering.top();
      ordering.pop();
      if (visi_new[node] == false) {
        reverseDFS(node, transpose, visi_new);
        cout << "-------" << endl;
      }
    }
  }
};

int main() {
  vector<vector<int>> edges{{1, 2}, {2, 3}, {3, 1}, {2, 4}, {4, 5}};
  Graph *g1 = new Graph(5, edges); // 1 - 5

  g1->kosaraju();
  return 0;
}