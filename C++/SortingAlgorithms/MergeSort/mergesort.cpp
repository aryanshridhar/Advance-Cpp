#include <fstream>
#include <iostream>
#include <time.h>
#include <vector>

using namespace std;

void show(vector<int> &input);
vector<int> generate_random(int nums) {
  vector<int> unsorted(nums, 0);
  srand(time(0));
  generate(unsorted.begin(), unsorted.end(), rand);

  return unsorted;
}

void merge(vector<int> &input, int low, int mid, int high) {
  vector<int> output;
  int left = low;
  int right = mid + 1;

  // Left,mid and high are indexed based.
  while (left <= mid && right <= high) {
    if (input[left] < input[right]) {
      output.push_back(input[left]);
      left++;
    } else {
      output.push_back(input[right]);
      right++;
    }
  }

  // Copying the remaining elements.
  while (left <= mid) {
    output.push_back(input[left]);
    left++;
  }

  while (right <= high) {
    output.push_back(input[right]);
    right++;
  }

  for (int i = low; i <= high; i++) {
    input[i] = output[i - low];
  }
}

// Works on divide and conquer algorithm, which in this case, works by dividing
// the array into its subvectors from top to bottom and then merging them again
// one by one from bottom to top. 0(nlogn)

void merge_sort(vector<int> &input, int low, int high) {
  if (low >= high) {
    return;
  }
  int mid = (high + low) / 2;
  merge_sort(input, low, mid);      // Merge sort the left part of array.
  merge_sort(input, mid + 1, high); // Merge sort the right part of array.
  merge(input, low, mid, high);
}

void show(vector<int> &input) {
  for (int i = 0; i < input.size(); i++) {
    cout << input[i] << endl;
  }
}

int main() {
  vector<int> unsorted = generate_random(10000);

  clock_t t_start = clock();

  merge_sort(unsorted, 0, unsorted.size() - 1);
  show(unsorted);

  cout << "Time taken " << (double)(clock() - t_start) / CLOCKS_PER_SEC << endl;
  return 0;
}
