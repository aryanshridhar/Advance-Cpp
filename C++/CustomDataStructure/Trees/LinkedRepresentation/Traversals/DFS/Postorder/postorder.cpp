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

// 0(n) -> visiting all nodes only once.
void postorder(Tree *node) {
  // Left -> Right -> Root

  if (node == NULL) {
    return;
  }

  postorder(node->left);
  postorder(node->right);
  cout << node->data << endl;
}

int main() {
  Tree *root = new Tree(10);
  Tree *t1 = new Tree(5);
  Tree *t2 = new Tree(7);
  Tree *t3 = new Tree(9);
  Tree *t4 = new Tree(55);
  Tree *t5 = new Tree(6);
  Tree *t6 = new Tree(83);
  Tree *t7 = new Tree(99);

  root->left = t1;
  t1->left = t2;
  t2->right = t3;
  root->right = t4;
  t4->left = t5;
  t4->right = t6;
  t6->left = t7;

  // clang-format off
    /* Tree representation. (N == null)

          10
        /    \
       5      55
      / \     / \ 
     7   N   6   83
    / \         /  \ 
    N  9       99   N

    */
  // clang-format on

  postorder(root);

  return 0;
}