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

void show(vector<int> &input) {
  for (int i = 0; i < input.size(); i++) {
    cout << input[i] << endl;
  }
}

int get_pivot_index(vector<int> &input, int low, int high) {
  int left = low + 1; // 3
  int right = high;   // 6
  int pivot_value = input[low];

  do {
    while (input[left] <= pivot_value && left < right + 1) {
      left++;
    }
    while (input[right] > pivot_value && right > low - 1) {
      right--;
    }

    // If right is greater than left and the above indices are found.
    if (right > left) {
      // Swap the values of left and irght index.
      int temp = input[left];
      input[left] = input[right];
      input[right] = temp;
    }
  } while (left < right);

  // If the right index crossed the left index Swap the pivot with right value.
  int temp_ = input[low];
  input[low] = input[right];
  input[right] = temp_;

  // The pivot is now placed at it's sorted index (right index)
  return right;
}

// Quite an complex algorithm with basics being that each value is placed at
// its corresponding index.
// 0(n^2)
// Best case - O(nlogn)
// When we partition from middle everytime.
// Not stable algorithm
// Not adaptive.
void quick_sort(vector<int> &input, int low, int high) {
  // To run this recursion till the newly generated subvectors are not empty.
  if (low < high) {
    int pivot_index = get_pivot_index(input, low, high);
    quick_sort(input, pivot_index + 1, high);
    quick_sort(input, low, pivot_index - 1);
  }
}

int main() {
  vector<int> unsorted = generate_random(10000);

  clock_t t_start = clock();

  quick_sort(unsorted, 0, unsorted.size() - 1);
  show(unsorted);

  cout << "Time taken " << (double)(clock() - t_start) / CLOCKS_PER_SEC << endl;
  return 0;
}
