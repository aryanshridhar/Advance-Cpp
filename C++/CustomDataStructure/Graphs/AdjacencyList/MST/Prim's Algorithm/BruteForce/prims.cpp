#include <iostream>
#include <vector>
#include <queue>
#include <string.h>

using namespace std;

// Creates a adjacency matrix for the whole graph.
class Graph {
public:
  int n;
  vector<pair<int,int>> adj[10000];

  Graph(int num, vector<vector<int>> edge) {
    n = num;
    for (int i = 0; i < edge.size(); i++) {
      int vertex1 = edge[i][0];
      int vertex2 = edge[i][1];
      int egde_weight = edge[i][2];

      adj[vertex1].push_back({vertex2,egde_weight});
      adj[vertex2].push_back({vertex1,egde_weight});
    }
  }

  void PrimsAlgo(){
      bool MST[n]; // Is a part of MSt yet.
      int parent[n]; // Get the parent of the node added in MST.
      int key[n]; // Represents the edges weight added in MST.

      for(int i=0;i<n;i++){
          key[i] = INT32_MAX;
          MST[i] = false;
          parent[i] = -1;
      }

      // Starting from 0.
      key[0] = 0;
      parent[0] = -1;

      for(int count = 0;count < n-1;count++){
        // n-1 loop to get the n-1 edges of MST.
        int mini_key = INT32_MAX;
        int mini_key_index = -1;

        for(int i=0;i<n;i++){
          if(MST[i] == false && i < mini_key){
            mini_key = key[i];
            mini_key_index = i;
          }
        }

        MST[mini_key_index] = true;

        for(auto i:adj[mini_key_index]){
          // Loop in adjacent edges of minimum key found.
          int to_node = i.first;
          int edge_weight = i.second;

          if(MST[to_node] == false && edge_weight < key[to_node]){
            parent[to_node] = mini_key_index;
            key[to_node] = edge_weight;
          }
        }
      }

      for(int i=0;i<n;i++){
        cout << parent[i] << "----" << i << endl; 
      }
  }
};

int main() {
  vector<vector<int>> edges{{0,1,2},{0,3,6},{1,4,5},{3,1,8},{1,2,3},{2,4,7}};
  Graph *g1 = new Graph(5,edges);

  g1->PrimsAlgo();
  return 0;
}