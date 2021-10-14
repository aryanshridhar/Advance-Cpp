#include <fstream>
#include <iostream>
#include <queue>

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
void levelorder(Tree *node) {
  // Visit all elements level vice.

  if (node == NULL) {
    return;
  }

  queue<Tree *> q; // Store the tree nodes of traversed elements.
  q.push(node);    // Store the initial root.

  // Enqueue the left and right tree nodes after visting a node.
  while (!q.empty()) {
    Tree *node = q.front();
    cout << node->data << endl;
    q.pop();
    if (node->left != NULL) {
      q.push(node->left);
    }
    if (node->right != NULL) {
      q.push(node->right);
    }
  }
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

  levelorder(root);

  return 0;
}