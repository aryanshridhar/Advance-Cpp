#include <bits/stdc++.h>
using namespace std;
using li = long int;
using lli = long long int;

#define eb emplace_back
#define mt make_tuple
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define pi pair<int, int>
#define vi vector<int>
#define vl vector<lli>
#define p(x) cout << #x << " is " << (x) << " on Line:" << __LINE__ << " \n";
#define pl(x)                                                                  \
  for (auto &y : x)                                                            \
    cout << y << " ";                                                          \
  cout << "\n";

void dfs(int src, int parent, vi &s, int vis[], vector<vi> &graph) {
  vis[src] = 1;
  s.eb(src);
  for (auto &x : graph[src]) {
    if (vis[x] == 0) {
      dfs(x, src, s, vis, graph);
    } else if (vis[x] == 1) {
      if (x != parent) {
        cout << "cycle \n";
        cout << x << " ";
        int pos = ((int)s.size()) - 1;
        while (pos >= 0 && s[pos] != x) {
          cout << s[pos] << " ";
          --pos;
        }
        cout << "\n";
      }
    }
  }
  vis[src] = 2;
  s.pop_back();
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<vi> graph(n, vi(0));
  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    graph[a].eb(b);
    graph[b].eb(a);
  }
  int vis[n] = {0};
  vi s;
  for (int i = 0; i < n; ++i) {
    if (vis[i] == 0) {
      dfs(i, -1, s, vis, graph);
    }
  }
}
// Sample Input

// 12 13c
// 0 1
// 1 2
// 2 3
// 3 4
// 4 5
// 5 6
// 6 7
// 7 8
// 8 5
// 5 9
// 9 10
// 10 11
// 11 3

// Sample Output

// cycle
// 5 8 7 6
// cycle
// 3 11 10 9 5 4
