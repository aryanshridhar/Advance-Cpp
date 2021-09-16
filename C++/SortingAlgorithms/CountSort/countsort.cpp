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

int maximum(vector<int> &input) {
  int maxi = INT32_MIN;
  for (int i = 0; i < input.size(); i++) {
    if (input[i] > maxi) {
      maxi = input[i];
    }
  }

  return maxi;
}

// Store the number of occurrences of each element in a seperate vector
// and then traverse the newly created vector to change back the elements in
// main vector accroding to thier number of occurrences. O(n) Space: O(n) Not
// inplace. Works well for positive integers only. Incas eof negative integers,
// we need to virtually set the first index after minimum value in the auxillary
// vector. (Not space efficient algo).
void countsort(vector<int> &input) {
  int maxi = maximum(input);
  vector<int> output(maxi + 1, 0); // Initializes the vector with size as maxi+1
                                   // and all initial values as 0.

  // Increasing the count of the value at index.
  for (int i = 0; i < input.size(); i++) {
    output[input[i]]++;
  }

  int j = 0;
  int i = 0;

  while (i < output.size()) {
    if (output[i] > 0) {
      input[j] = i;
      output[i]--;
      j++;
    } else {
      i++;
    }
  }
}

void show(vector<int> &input) {
  for (int i = 0; i < input.size(); i++) {
    cout << input[i] << endl;
  }
}

int main() {
  vector<int> unsorted = {5, 77, 2, 3, 2, 1, 99, 5};

  clock_t t_start = clock();

  countsort(unsorted);
  show(unsorted);

  cout << "Time taken " << (double)(clock() - t_start) / CLOCKS_PER_SEC << endl;
  return 0;
}
