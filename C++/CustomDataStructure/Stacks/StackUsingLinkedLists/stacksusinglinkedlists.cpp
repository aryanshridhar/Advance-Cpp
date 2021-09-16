#include <fstream>
#include <iostream>

using namespace std;

class Node {
public:
  int data;
  Node *pointer;

  Node(int value) {
    data = value;
    pointer = NULL;
  }
};

Node *top = NULL;

bool _is_empty() {
  if (top == NULL) {
    return true;
  }
  return false;
}

void push(int data) {
  Node *new_node = new Node(data);
  new_node->pointer = top;

  top = new_node;
}

int pop() {
  if (_is_empty()) {
    throw "The stack is already empty.";
  }
  Node *head = top;
  int data = head->data;
  top = head->pointer;
  free(head);

  return data;
}

void show() {
  Node *head = top;
  while (head != NULL) {
    cout << head->data << endl;
    head = head->pointer;
  }
}

int peek() { return top->data; }

int stackTop() { return peek(); }

int stackBottom() {
  Node *head = top;

  while (head != NULL) {
    head = head->pointer;
  }

  return head->data;
}

int element_at_position(int position) {
  int index = position - 1;
  if (index < 0) {
    throw "Invalid position passed";
  }

  Node *head = top;
  int list_index = 0;

  while (list_index != index) {
    head = head->pointer;
    list_index++;
  }

  return head->data;
}

int main() {

  // ------> [data|pointer] -> [data|pointer] -> [data|pointer] ->
  // [data|pointer] -> NULL All operations are from the left most end so that
  // they are completed in O(1) time and no need to traverse the linked list to
  // reach the end node.

  top = new Node(46);
  show();

  push(56);
  push(66);
  push(76);
  push(86);

  cout << "After pushing multiple values" << endl;
  show();

  int _popped = pop();
  cout << "After popping multiple values" << endl;
  show();

  cout << "Element at position 2 is - " << element_at_position(2) << endl;
  return 0;
}