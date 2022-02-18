#include <iostream>
#include <queue>
#include <vector>

// AKA Dijkstra's Algorithm

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
      adj[vertex2].push_back({vertex1, edge_weight});
    }
  }

  vector<int> getShortestDistance() {
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        pq;
    vector<int> distance(10000, INT_MAX);
    // Distance, root
    pq.push({0, 1});
    distance[1] = 0;

    while (!pq.empty()) {
      pair<int, int> top = pq.top();
      int current_distance = top.first;
      int current_root = top.second;
      pq.pop();

      for (pair<int, int> adjacent : adj[current_root]) {
        int element_path_cost = adjacent.second;
        int element = adjacent.first;

        if (distance[element] > current_distance + element_path_cost) {
          distance[element] = current_distance + element_path_cost;

          cout << "Element " << element << endl;
          cout << "Distance " << distance[element] << endl;

          pq.push({distance[element], element});
        }
      }
    }

    return distance;
  }
};

int main() {
  vector<vector<int>> edges{{1, 2, 2}, {1, 4, 1}, {4, 3, 3},
                            {2, 3, 4}, {2, 5, 5}, {3, 5, 1}};
  Graph *g1 = new Graph(edges);
  vector<int> distances;

  distances = g1->getShortestDistance();
  for (int i = 0; i < distances.size(); i++) {
    if (distances[i] != INT_MAX) {
      cout << "Node " << i << " Is at distance " << distances[i] << endl;
    }
  }

  return 0;
}