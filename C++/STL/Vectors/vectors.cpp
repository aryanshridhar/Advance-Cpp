#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <typeinfo>
#include <string>

using namespace std;

void printarray(vector<int> v1 , string value);
void isempty(vector <int> v1);

int main(){

    vector<int> array = {12,2,34,1,44};

    // Iterators

    auto start = array.begin(); // first element in array - 12 OR cbegin
    auto realend = array.rbegin(); // last element  - 44
    auto end = array.end(); // theoretical last element - 0 OR cend

    cout << *start << endl; 
    cout << *realend << endl; 
    cout << *end << endl; 

    printarray(array , "Elements are :-");

    // Methods

    int size = array.size(); // length of array
    long long int max_len = array.max_size(); // maximum element array can hold
    int space = array.capacity(); // storage size in terms of element

    cout << "Length of :- " << size << endl;
    cout << "Max length that array can hold :- " << max_len << endl;
    cout << "Space currently occupying :-"  << space << endl;

    array.resize(3); // will contain only first 3 elements now (Just reduces the size of array , beyond elements are still present)

    printarray(array , "Elements are :-");
    
    bool isfull = array.empty(); // 0 if array is empty , else 1
    cout << isfull << endl;

    array.shrink_to_fit(); // destroys all the beyond elemets , retaining only 3 elements

    // Modifiers

    array.assign(6,10); // replace all values with 10 with new length as 6

    array.push_back(21); // addds new element to array
    array.push_back(26);

    array.pop_back(); // removes element from back

    array.insert(array.begin()+2,{99,11}); // inserts 99 and 11 at index 2,3 respectively (have to specify pointer location at value)

    printarray(array , "Elements are :-");

    array.erase(array.begin() + 2,array.begin() + 5);

    printarray(array , "Elements after erasing :");

    array.clear(); // destroys all element

    printarray(array , "Elements are :");
    isempty(array);  

    return 0;
}

void printarray(vector<int> v1 , string value){

    for(int i=0;i<v1.size();i++){
        cout << value << v1[i] << endl;
    }
}

void isempty(vector <int> v1){
    if(v1.empty() == 1){
        cout << "Array is empty" << endl;
    }
    else{
        cout << "Array is not empty" << endl;
    }
}
