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
// sorted. Next we shift the right pointer to the next index and then add next
// element to array and then sort it again. O(n^2) stable adaptive.
void insertion_sort(vector<int> &input) {
  for (int i = 1; i < input.size(); i++) {
    if (input[i] < input[i - 1]) {
      int j = i - 1;
      while (j > -1) {
        if (input[j] > input[j + 1]) {
          int temp = input[j];
          input[j] = input[j + 1];
          input[j + 1] = temp;
        }
        j--;
      }
    }
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

  insertion_sort(unsorted);
  show(unsorted);

  cout << "Time taken " << (double)(clock() - t_start) / CLOCKS_PER_SEC << endl;
  return 0;
}
