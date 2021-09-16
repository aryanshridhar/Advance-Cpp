#include <fstream>
#include <iostream>
#include <time.h>
#include <vector>

using namespace std;

vector<int> generate_random(int nums) {
  vector<int> unsorted(nums, 0);
  srand(time(0));
  generate(unsorted.begin(), unsorted.end(), rand);

  return unsorted;
}

// Basic algorithm includes by starting with the first element which is always
// sorted. Next it searches for the least element in the unsorted part and
// places it to the starting of the array again. Really basic algo having time
// complexity as O(n^2) Not stable Not adaptive.
void selection_sort(vector<int> &input) {
  for (int i = 0; i < input.size() - 1; i++) {
    int unsorted_min = INT32_MAX;
    for (int j = i; j < input.size(); j++) {
      if (input[j] < unsorted_min) {
        unsorted_min = input[j];
      }
    }
    input[i] = unsorted_min;
  }
}

void show(vector<int> &input) {
  for (int i = 0; i < input.size(); i++) {
    cout << input[i] << endl;
  }
}

int main() {
  vector<int> unsorted = generate_random(10000);

  clock_t t_start = clock();

  selection_sort(unsorted);
  show(unsorted);

  cout << "Time taken " << (double)(clock() - t_start) / CLOCKS_PER_SEC << endl;
  return 0;
}
