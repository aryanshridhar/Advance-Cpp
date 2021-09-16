#include <iostream>
#include <fstream>
#include <vector>
#include <time.h>

using namespace std;

void show(vector<int> &input);
vector<int> generate_random(int nums){
    vector<int> unsorted(nums,0);
    srand(time(0));
    generate(unsorted.begin(), unsorted.end(), rand);

    return unsorted;
}

// Really simple algorithm which mainly works when given elements from 1 to natural number n.
// The algorithm includes positioning each element to it's index as it should have been in a sorted order.
// Or when 1 to n are sorted, element = index+1. We apply this basic algorithm to poistion each element to
// its index.
// O(n)
// Can be modified for other cases as well (0..n, m..n and such).
// In place algo.
void cyclic_sort(vector<int> &input){
    int i = 0;
    while(i < input.size()){
        if(input[i] != i+1){
            // Swap the element with the element at desired index.
            int temp = input[i];
            input[i] = input[temp-1];
            input[temp-1] = temp;
        } else {
            i++;
        }
    }
}

void show(vector<int> &input){
    for(int i=0;i<input.size();i++){
        cout << input[i] << endl;
    }
}

int main(){
    vector<int> unsorted = {7,6,4,5,1,3,2};

    clock_t t_start = clock();

    cyclic_sort(unsorted);
    show(unsorted);

    cout << "Time taken " << (double)(clock() - t_start)/CLOCKS_PER_SEC << endl;   
    return 0;
}
