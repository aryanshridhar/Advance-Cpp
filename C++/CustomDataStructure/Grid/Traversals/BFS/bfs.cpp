#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// Creates a 2d matrix.
class Grid {
public:
  int R; // number of rows
  int C; // number of columns
  vector<vector<int>> matrix;

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

  // Starts the bfs traversal from the coordinate passed and moves in 4
  // directions.
  void bfs(pair<int, int> coordinate) {
    vector<vector<int>> visi(R, vector<int>(C, 0));
    // Defines the change in direction of rows and column (directional vectors).
    vector<int> dRow{-1, 0, 1, 0};
    vector<int> dCol{0, 1, 0, -1};

    queue<pair<int, int>> q;

    q.push(coordinate);
    visi[coordinate.first][coordinate.second] = 1;
    cout << matrix[coordinate.first][coordinate.second] << " ";

    while (!q.empty()) {
      pair<int, int> next_coordinate = q.front();
      q.pop();

      // NOT ADVISABLE METHOD (LENGTHY AND REPETITIVE).

      //   // Traverse for all the sides.
      //   pair<int,int> left =
      //   {next_coordinate.first,next_coordinate.second-1}; pair<int,int> right
      //   = {next_coordinate.first,next_coordinate.second+1}; pair<int,int>
      //   down = {next_coordinate.first+1,next_coordinate.second};
      //   pair<int,int> up = {next_coordinate.first-1,next_coordinate.second};

      // // Left
      //   if(is_Valid(left.first,left.second,visi)){
      //       cout << matrix[left.first][left.second] << " ";
      //       visi[left.first][left.second] = 1;
      //       q.push(left);
      //   }
      //   // Right
      //   if(is_Valid(right.first,right.second,visi)){
      //       cout << matrix[right.first][right.second] << " ";
      //       visi[right.first][right.second] = 1;
      //       q.push(right);
      //   }
      //   // Down
      //   if(is_Valid(down.first,down.second,visi)){
      //       cout << matrix[down.first][down.second] << " ";
      //       visi[down.first][down.second] = 1;
      //       q.push(down);
      //   }
      //   // Up
      //   if(is_Valid(up.first,up.second,visi)){
      //       cout << matrix[up.first][up.second] << " ";
      //       visi[up.first][up.second] = 1;
      //       q.push(up);
      //   }

      // BETTER SOLUTION
      int x = next_coordinate.first;
      int y = next_coordinate.second;

      // Go to the adjacent cells
      for (int i = 0; i < 4; i++) {

        int adjx = x + dRow[i];
        int adjy = y + dCol[i];

        if (is_Valid(adjx, adjy, visi)) {
          q.push({adjx, adjy});
          cout << matrix[adjx][adjy] << " ";
          visi[adjx][adjy] = 1;
        }
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

  g1->bfs({0, 0});

  return 0;
}