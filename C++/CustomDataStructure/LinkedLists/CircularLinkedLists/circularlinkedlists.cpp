#include <fstream>
#include <iostream>

using namespace std;

class Node {
public:
  int data;
  Node *pointer;

  Node(int value) { data = value; }
};

void show(Node *pointer) {
  Node *head = pointer;

  do {
    cout << head->data << endl;
    head = head->pointer;
  } while (head != pointer);
}

Node *insert(Node *pointer, int value, int index) {
  Node *new_node = new Node(value);
  Node *head = pointer;

  if (index == 0) {
    head = head->pointer;
    while (head->pointer != pointer) {
      head = head->pointer;
    };

    new_node->pointer = head->pointer;
    head->pointer = new_node;

    return new_node;
  }

  int i = 0;
  while (i != index - 1) {
    head = head->pointer;
    i++;
  }

  // At this point, head pointer is pointing towards the previous element of
  // index.
  new_node->pointer = head->pointer;
  head->pointer = new_node;

  return NULL;
}

Node *delete_by_index(Node *pointer, int index) {
  Node *head = pointer;

  if (index == 0) {
    Node *q = head;
    head = head->pointer;
    free(q);
  }

  int i = 0;

  while (i != index - 1) {
    head = head->pointer;
    i++;
  }

  Node *temp_pointer = head->pointer;
  head->pointer = temp_pointer->pointer;
  free(temp_pointer);
}

Node *delete_by_value(Node *pointer, int value) {
  Node *head = pointer;
  int index = 0;

  while (head->data != value) {
    index++;
    head = head->pointer;
  };

  return delete_by_index(pointer, index);
}

int main() {
  Node *n1 = new Node(14);
  Node *n2 = new Node(66);
  Node *n3 = new Node(33);
  Node *n4 = new Node(2);

  n1->pointer = n2;
  n2->pointer = n3;
  n3->pointer = n4;
  n4->pointer = n1;

  Node *new_node = insert(n1, 43, 0);
  show(new_node);

  cout << "Deleting by index" << endl;
  delete_by_index(new_node, 2);
  show(new_node);

  cout << "Deleting by value" << endl;
  delete_by_value(new_node, 14);
  show(new_node);

  return 0;
}