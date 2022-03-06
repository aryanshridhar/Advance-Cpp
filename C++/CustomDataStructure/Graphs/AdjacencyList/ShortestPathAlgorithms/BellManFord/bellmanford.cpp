#include <iostream>
#include <queue>
#include <string.h>
#include <vector>

using namespace std;

int INF = 10000000;

// Creates a adjacency matrix for the whole graph.
class Graph {
public:
  int n;
  vector<pair<int, int>> adj[10000];

  Graph(int num, vector<vector<int>> edge) {
    n = num;
    for (int i = 0; i < edge.size(); i++) {
      int vertex1 = edge[i][0];
      int vertex2 = edge[i][1];
      int egde_weight = edge[i][2];

      adj[vertex1].push_back({vertex2, egde_weight});
    }
  }

  void bellmanFord() {
    int src = 0;
    vector<int> dist(n, 10000000);
    dist[src] = 0;
    // Releasing vertices nodes-1 times.
    for (int i = 0; i <= n - 1; i++) {
      for (int j = 0; j < n; j++) {
        for (auto adjacent : adj[j]) {
          if (dist[j] + adjacent.second < dist[adjacent.first]) {
            dist[adjacent.first] = dist[j] + adjacent.second;
          }
        }
      }
    }

    cout << "Minimum distances from node 0 to others are: " << endl;
    for (int i = 0; i < n; i++) {
      cout << i << " ";
      cout << dist[i] << endl;
    }

    // Checking for negative cycle.
    for (int j = 0; j < n; j++) {
      for (auto adjacent : adj[j]) {
        if (dist[j] + adjacent.second < dist[adjacent.first]) {
          cout << "Negative cycle is present" << endl;
          break;
        }
      }
    }
  }
};

int main() {
  vector<vector<int>> edges{{0, 1, 5},  {2, 1, -2}, {2, 4, 3}, {3, 4, -2},
                            {3, 2, -6}, {5, 3, 1},  {1, 5, -3}};
  Graph *g1 = new Graph(6, edges);

  g1->bellmanFord();
  return 0;
}