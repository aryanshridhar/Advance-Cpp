#include <fstream>
#include <iostream>

using namespace std;

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

// 0(logn) -> visiting all nodes only once.
bool search(Tree *node, int val) {
  if (node == NULL) {
    return false;
  }
  if (node->data == val) {
    return true;
  }

  if (val > node->data) {
    return search(node->right, val);
  } else {
    return search(node->left, val);
  }

  return false;
}

int main() {
  Tree *root = new Tree(10);
  Tree *t1 = new Tree(8);
  Tree *t2 = new Tree(11);
  Tree *t3 = new Tree(5);
  Tree *t4 = new Tree(55);
  Tree *t5 = new Tree(4);
  Tree *t6 = new Tree(143);
  Tree *t7 = new Tree(60);
  Tree *t12 = new Tree(9);

  root->left = t1;
  t1->left = t5;
  t5->right = t3;
  t1->right = t12;

  root->right = t4;
  t4->left = t2;
  t4->right = t6;
  t6->left = t7;

  // clang-format off
    /* Tree representation. (N == null)

          10
        /    \
       8      55
      / \     / \ 
     4   9   11   143
    / \         /  \ 
    N  5       60   N

    */
  // clang-format on

  cout << search(root, 5) << endl;

  return 0;
}