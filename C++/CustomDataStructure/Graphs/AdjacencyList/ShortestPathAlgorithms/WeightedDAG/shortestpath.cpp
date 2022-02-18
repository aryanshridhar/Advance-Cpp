#include <iostream>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

class Graph {
public:
  vector<pair<int, int>> adj[10000];

  Graph(vector<vector<int>> edge) {
    for (int i = 0; i < edge.size(); i++) {
      int vertex1 = edge[i][0];
      int vertex2 = edge[i][1];
      int edge_weight = edge[i][2];

      adj[vertex1].push_back({vertex2, edge_weight});
    }
  }

  void getTopoSortUtil(int src, vector<pair<int, int>> adj[],
                       stack<int> &toposort, vector<int> &visited) {
    visited[src] = 1;
    for (pair<int, int> adjacent : adj[src]) {
      if (visited[adjacent.first] == -1) {
        getTopoSortUtil(adjacent.first, adj, toposort, visited);
      }
    }

    toposort.push(src);
  }

  stack<int> getTopoSort() {
    stack<int> toposort;
    vector<int> visited(10000, -1);
    getTopoSortUtil(0, adj, toposort, visited);

    return toposort;
  }

  vector<int> getShortestDistance() {
    vector<int> distance(10000, INT_MAX);
    stack<int> toposort = getTopoSort();
    distance[toposort.top()] = 0;

    while (!toposort.empty()) {
      int top = toposort.top();
      toposort.pop();

      if (distance[top] != INT_MAX) {
        for (pair<int, int> adjacent : adj[top]) {
          if (distance[top] + adjacent.second < distance[adjacent.first]) {
            distance[adjacent.first] = distance[top] + adjacent.second;
          }
        }
      }
    }

    return distance;
  }
};

int main() {
  vector<vector<int>> edges{{0, 1, 2}, {1, 2, 3}, {2, 3, 6}, {0, 4, 1},
                            {4, 2, 2}, {4, 5, 4}, {5, 3, 1}};
  Graph *g1 = new Graph(edges);
  vector<int> distances = g1->getShortestDistance();
  for (int i = 0; i < distances.size(); i++) {
    if (distances[i] != INT_MAX) {
      cout << "Node " << i << " Is at distance " << distances[i] << endl;
    }
  }

  return 0;
}