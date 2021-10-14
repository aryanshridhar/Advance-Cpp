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
void insert(Tree *node, int val) {
  // Loop until we reach at that point to be inserted.
  Tree *root = node;
  Tree *prev = node; // Maintains the pointer to previous node (at the node to
                     // be inserted).
  while (root != NULL) {
    prev = root;
    if (root->data == val) {
      return;
    }

    if (val > root->data) {
      root = root->right;
    } else {
      root = root->left;
    }
  }

  Tree *to_insert = new Tree(val);

  if (val > prev->data) {
    // Insertion at right end.
    prev->right = to_insert;
  } else {
    prev->left = to_insert;
  }
}

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

// 0(n) -> visiting all nodes only once.
void inorder(Tree *node) {
  // Left -> Root -> Right

  if (node == NULL) {
    return;
  }

  inorder(node->left);
  cout << node->data << endl;
  inorder(node->right);
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

  insert(root, 300);
  cout << search(root, 300) << endl;
  cout << "Inorder traversal is " << endl;
  inorder(root);

  return 0;
}