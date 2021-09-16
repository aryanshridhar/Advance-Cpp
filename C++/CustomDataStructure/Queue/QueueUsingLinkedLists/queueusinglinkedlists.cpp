#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

class Node {
public:
  int data;
  Node *pointer = NULL;

  Node(int value) { data = value; }
};

Node *enqueue_index = NULL;
Node *dequeue_index = NULL;

void show(Node *ptr) {
  while (ptr != NULL) {
    cout << ptr->data << endl;
    ptr = ptr->pointer;
  }
}

void enqueue(int val) {
  Node *new_node = new Node(val);
  // Checking ig the linked list is empty.
  if (enqueue_index == NULL) {
    // Initially, when only one element is preseent, the enqueue and dequeue
    // index will be pointing to the same element.
    enqueue_index = new_node;
    dequeue_index = new_node;
  } else {
    enqueue_index->pointer = new_node;
    enqueue_index = new_node;
  }
}

void dequeue() {
  if (enqueue_index == NULL) {
    throw "The queue is already empty.";
    return;
  }

  Node *to_remove = dequeue_index;
  if (to_remove->pointer == NULL) {
    dequeue_index = NULL;
    enqueue_index = NULL;
  } else {
    dequeue_index = dequeue_index->pointer;
  }
  free(to_remove);
}

int main() {
  Node *n1 = new Node(9);
  Node *n2 = new Node(19);
  Node *n3 = new Node(2);
  Node *n4 = new Node(3);

  // linking all the pointers to each other.
  n1->pointer = n2;
  n2->pointer = n3;
  n3->pointer = n4;
  n4->pointer = NULL;

  dequeue_index = n1;
  enqueue_index = n4;

  enqueue(56);
  enqueue(66);

  dequeue();
  dequeue();
  dequeue();
  dequeue();
  dequeue();
  dequeue();

  enqueue(7);
  enqueue(6);

  show(dequeue_index);

  return 0;
}