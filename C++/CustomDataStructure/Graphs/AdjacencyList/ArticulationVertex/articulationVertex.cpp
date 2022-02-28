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

  Graph(int num, vector<vector<int>> edge) {
    n = num;
    for (int i = 0; i < edge.size(); i++) {
      int vertex1 = edge[i][0];
      int vertex2 = edge[i][1];

      adj[vertex1].push_back(vertex2);
      adj[vertex2].push_back(vertex1);
    }
  }

  void dfs(int start, int parent, vector<int> adj[], vector<bool> &visi,
           vector<int> &discovery, vector<int> &low, vector<bool> &bridges,
           int &timer) {
    discovery[start] = timer;
    low[start] = timer;
    visi[start] = true;
    int traversed = 0;
    timer++;

    for (auto adjacent : adj[start]) {
      if (parent == adjacent) {
        continue;
      } else if (visi[adjacent] == true) {
        low[start] = min(low[start], discovery[adjacent]);
      } else {
        dfs(adjacent, start, adj, visi, discovery, low, bridges, timer);
        low[start] = min(low[start], low[adjacent]);

        if (low[adjacent] >= discovery[start] && parent != -1) {
          bridges[start] = true;
        }
        traversed++;
      }
    }

    if (parent == -1 && traversed > 1) {
      bridges[start] = true;
    }
  }

  void getbridgesVertex() {
    vector<bool> visi(n + 1, false);
    vector<bool> bridges(n + 1, false);
    vector<int> discovery(n + 1, INT16_MAX);
    vector<int> low(n + 1, INT16_MAX);

    int timer = 1;
    for (int i = 1; i <= n; i++) {
      if (visi[i] == false) {
        dfs(i, -1, adj, visi, discovery, low, bridges, timer);
      }
    }

    cout << "bridges Vertex/Cut Vertex are: " << endl;
    for (int i = 1; i <= n; i++) {
      if (bridges[i] == true) {
        cout << i << endl;
      }
    }
  }
};

int main() {
  vector<vector<int>> edges{{1, 2},  {1, 4},   {2, 3},   {3, 4},  {4, 5},
                            {5, 6},  {6, 7},   {7, 8},   {8, 9},  {9, 6},
                            {8, 10}, {10, 11}, {11, 12}, {12, 10}};
  Graph *g1 = new Graph(12, edges); // 1->12

  g1->getbridgesVertex();
  return 0;
}