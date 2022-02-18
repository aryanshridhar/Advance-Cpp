#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <algorithm>

using namespace std;
const int N = 1e5+10;

// TC: O(4*alpha) - Amortized O(1).
class DSU {
    public:
    int parent[N];
    int size[N];

    void add(int v){
        parent[v] = v;
        size[v] = 1;
    }
    
    void unionn(int a, int b){
        int root_a = find(a);
        int root_b = find(b);

        // Always attach a smaller tree to the bigger tree. (Union by size)
        if(root_a != root_b){
            if(size[root_a] > size[root_b]){
                parent[root_b] = root_a;
                size[root_a] += size[root_b];
            } else {
                parent[root_a] = root_b;
                size[root_b] += size[root_a];
            }
        }
    }

    int find(int v){
        if(v == parent[v]){
            return v;
        }
        // Path compression.
        return parent[v] = find(parent[v]);
    }
};

class Graph {
public:
  vector<pair<pair<int,int>,int>> adj;
  int n;

  Graph(int num, vector<vector<int>> edge) {
    n = num;
    for (int i = 0; i < edge.size(); i++) {
      int vertex1 = edge[i][0];
      int vertex2 = edge[i][1];
      int egde_weight = edge[i][2];

      adj.push_back({{vertex1,vertex2},egde_weight});
      adj.push_back({{vertex2,vertex1},egde_weight});
    }
  }

  static bool compareFunc(pair<pair<int,int>,int> &p1,pair<pair<int,int>,int> &p2){
    return p1.second < p2.second;
  }

  void KruskalsAlgo(){
      DSU *d = new DSU();
      vector<pair<int,int>> MST;
      
      sort(adj.begin(), adj.end(), compareFunc);
      for(int i=0;i<n;i++){
        d->add(i);
      }

      int cost = 0;
      for(auto i:adj){
          if(d->find(i.first.first) != d->find(i.first.second)){
              cost += i.second;
              d->unionn(i.first.first, i.first.second);
              MST.push_back({i.first.first, i.first.second});
          }
      }

      cout << "The MST is having a total cost of " << cost << endl;
      cout << "MST" << endl;
      for(auto i:MST){
          cout << i.first << "----" << i.second << endl;
      }
  }
};

int main() {
  vector<vector<int>> edges{{0,1,2},{0,3,6},{1,4,5},{3,1,8},{1,2,3},{2,4,7}};
  Graph *g1 = new Graph(6,edges);

  g1->KruskalsAlgo();
  return 0;
}