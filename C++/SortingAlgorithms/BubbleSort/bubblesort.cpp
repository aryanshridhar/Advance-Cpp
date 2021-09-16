#include <iostream>
#include <fstream>
#include <vector>
#include <time.h>

using namespace std;


vector<int> generate_random(int nums){
    vector<int> unsorted(nums,0);
    srand(time(0));
    generate(unsorted.begin(), unsorted.end(), rand);

    return unsorted;
}

// Basic algorithm includes shifting the lagest element to the right of the array in each pass.
// As a single element is always sorted, we decrement the loop variable by 'i' in each step.
// 0(n^2)
// To improve this we can do a single pass and check if the array is already sorted.
// stable
// Can be made adaptive with help of above point.
void bubble_sort(vector<int> &input){
    for(int i=0;i<input.size()-1;i++){
        for(int j=0;j<input.size()-1-i;j++){
            if(input[j] > input[j+1]){
                // Swapping in-place.
                int temp = input[j];
                input[j] = input[j+1];
                input[j+1] = temp;
            }
        }
    }
}

void show(vector<int> &input){
    for(int i=0;i<input.size();i++){
        cout << input[i] << endl;
    }
}

int main(){
    vector<int> unsorted = generate_random(10000);
    
    clock_t t_start = clock();

    bubble_sort(unsorted);
    show(unsorted);

    cout << "Time taken " << (double)(clock() - t_start)/CLOCKS_PER_SEC << endl;   
    return 0;
}
