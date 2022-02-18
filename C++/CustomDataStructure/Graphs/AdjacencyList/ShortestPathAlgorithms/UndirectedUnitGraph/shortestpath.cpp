#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Graph {
public:
  vector<int> adj[10000];

  Graph(vector<vector<int>> edge) {

    for (int i = 0; i < edge.size(); i++) {
      int vertex1 = edge[i][0];
      int vertex2 = edge[i][1];

      adj[vertex1].push_back(vertex2);
      adj[vertex2].push_back(vertex1);
    }
  }

  vector<int> getShortestDistance() {
    queue<pair<int, int>> q;
    vector<int> distance_vec(10000, INT_MAX);
    distance_vec[0] = 0;
    q.push({0, 0}); // Initially node 1 is at distance 0.

    while (!q.empty()) {
      pair<int, int> top = q.front();
      q.pop();

      for (auto adjacent : adj[top.first]) {
        if (distance_vec[adjacent] > top.second + 1) {
          distance_vec[adjacent] = top.second + 1;
          q.push({adjacent, top.second + 1});
        }
      }
    }

    return distance_vec;
  }
};

int main() {
  vector<vector<int>> edges{{0, 1}, {0, 3}, {1, 0}, {1, 2}, {1, 3}, {2, 1},
                            {2, 6}, {3, 0}, {3, 4}, {4, 3}, {4, 5}, {5, 4},
                            {5, 6}, {6, 2}, {6, 5}, {6, 7}, {6, 8}, {7, 6},
                            {7, 8}, {8, 6}, {8, 7}};
  Graph *g1 = new Graph(edges);

  vector<int> distances = g1->getShortestDistance();
  for (int i = 0; i < distances.size(); i++) {
    if (distances[i] != INT_MAX) {
      cout << "Node " << i << " Is at distance " << distances[i] << endl;
    }
  }

  return 0;
}