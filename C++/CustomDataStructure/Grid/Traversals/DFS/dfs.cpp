#include <iostream>
#include <vector>

using namespace std;

// Creates a 2d matrix.

// Exclusively for dfs.
vector<vector<int>> visi(4, vector<int>(5, 0));

class Grid {
public:
  int R; // number of rows
  int C; // number of columns
  vector<vector<int>> matrix;

  // Exclusively for dfs.
  vector<int> dRow{-1, 0, 1, 0};
  vector<int> dCol{0, 1, 0, -1};

  Grid(int r, int c, vector<vector<int>> mat) {
    R = r;
    C = c;
    matrix = mat;
  }

  bool is_Valid(int r, int c, vector<vector<int>> &visi) {
    // Checks if the coordinate is unvisited and within the range of matrix.
    if (r < 0 || c < 0 || r >= R || c >= C) {
      return false;
    } else {
      if (visi[r][c] == 1) {
        return false;
      }
    }

    return true;
  }
  void dfs(pair<int, int> coordinate) {
    int x = coordinate.first;
    int y = coordinate.second;

    cout << matrix[x][y] << " ";
    visi[x][y] = 1;

    for (int i = 0; i < 4; i++) {

      int adjx = x + dRow[i];
      int adjy = y + dCol[i];

      if (is_Valid(adjx, adjy, visi)) {
        dfs({adjx, adjy});
      }
    }
  }
};

int main() {
  vector<vector<int>> mat{{1, 2, 3, 4, 5},
                          {6, 7, 8, 9, 10},
                          {11, 12, 13, 14, 15},
                          {16, 17, 18, 19, 20}};
  Grid *g1 = new Grid(4, 5, mat);

  g1->dfs({0, 0});

  return 0;
}