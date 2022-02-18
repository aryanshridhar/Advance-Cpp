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
      priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq; // {weight,key}
      bool MST[n];
      int parent[n];
      int key[n];
      
      for(int i=0;i<n;i++){
          key[i] = INT32_MAX;
          MST[i] = false;
          parent[i] = -1;
      }

      pq.push({0,0});
      key[0] = 0;
      parent[0] = -1;

      while(!pq.empty()){
          int mini_key_index = pq.top().second;
          pq.pop();
          MST[mini_key_index] = true;

          // Looping for all the adjacent.
          for(auto i:adj[mini_key_index]){
              int to_node = i.first;
              int node_weight = i.second;
              if(MST[to_node] == false && key[to_node] > node_weight){
                  pq.push({node_weight,to_node});
                  key[to_node] = node_weight;
                  parent[to_node] = mini_key_index;
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