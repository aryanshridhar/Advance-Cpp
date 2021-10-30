// Grid are basically 2d matrix.
// Kept them to be a "Custom data structure" since there are a lot
// of algorithms to learn from matrices as well.

#include <iostream>
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

  void displaymatrix() {
    for (int i = 0; i < R; i++) {
      for (int j = 0; j < C; j++) {
        cout << matrix[i][j] << " ";
      }
      cout << endl;
    }
  }
};

int main() {
  vector<vector<int>> mat{{1, 2, 3, 4, 5},
                          {6, 7, 8, 9, 10},
                          {11, 12, 13, 14, 15},
                          {16, 17, 18, 19, 20}};
  Grid *g1 = new Grid(4, 5, mat);

  g1->displaymatrix();

  return 0;
}