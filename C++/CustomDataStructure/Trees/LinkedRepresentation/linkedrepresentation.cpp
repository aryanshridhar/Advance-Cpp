#include <fstream>
#include <iostream>

using namespace std;

// Kind of a doubly linked list.
class Tree {
public:
  int data;
  Tree *left;
  Tree *right;

  Tree(int val) {
    data = val;
    left = NULL;
    right = NULL;
  }
};

int main() {

  Tree *root = new Tree(1);

  return 0;
}