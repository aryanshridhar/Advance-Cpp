#include <fstream>
#include <iostream>

using namespace std;

class Node {
    public:

    int data;
    Node *prev_data;
    Node *next_data;

    Node(int value){
        data = value;
    }
};
