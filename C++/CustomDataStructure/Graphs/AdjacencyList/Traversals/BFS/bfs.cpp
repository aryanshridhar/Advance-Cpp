#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Graph {
public:
  int V; // number of vertices
  int E; // number of edges
  vector<int> adj[10000];

  Graph(int v, int e, vector<vector<int>> edge) {
    V = v;
    E = e;

    for (int i = 0; i < edge.size(); i++) {
      int vertex1 = edge[i][0];
      int vertex2 = edge[i][1];

      adj[vertex1].push_back(vertex2);
      adj[vertex2].push_back(vertex1);
    }
  }

  void bfs() {
    queue<int> q;
    vector<int> visited(10000, -1);
    q.push(0); // Generally given in question as root.

    while (!q.empty()) {
      int element = q.front();
      cout << element << endl;
      visited[element] = 1;
      q.pop();

      for (int adjacent : adj[element]) {
        if (visited[adjacent] == -1) {
          q.push(adjacent);
        }
      }
    }
  }
};

int main() {
  vector<vector<int>> edges{{0, 1}, {1, 4}, {4, 6}, {0, 2}, {1, 3}, {2, 5}};
  Graph *g1 = new Graph(7, 6, edges);

  g1->bfs();
  return 0;
}