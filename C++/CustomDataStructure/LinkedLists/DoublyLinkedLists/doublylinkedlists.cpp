#include <fstream>
#include <iostream>

using namespace std;

class Node {
public:
  int data;
  Node *prev_data;
  Node *next_data;

  Node(int value) {
    data = value;
    next_data = NULL;
    prev_data = NULL;
  }
};

void show(Node *ptr) {
  Node *head = ptr;
  while (head != NULL) {
    cout << head->data << endl;
    head = head->next_data;
  }
}

Node *insert(Node *ptr, int index, int data) {
  Node *head = ptr;
  Node *new_node = new Node(data);
  int traverse_index = 0;

  if (index == 0) {
    new_node->next_data = ptr;
    new_node->prev_data = NULL;

    ptr->prev_data = new_node;
    return new_node;
  }

  while (traverse_index != index) {
    ptr = ptr->next_data;
    traverse_index++;
  }

  Node *previous_node = ptr->prev_data;
  Node *next_node = ptr->next_data;

  previous_node->next_data = new_node;

  new_node->prev_data = previous_node;
  new_node->next_data = ptr;

  return head;
}

Node *delete_by_index(Node *ptr, int index) {
  int traverse_index = 0;
  Node *head = ptr;

  if (index == 0) {
    ptr = ptr->next_data;
    free(ptr);

    return ptr;
  }

  while (traverse_index != index) {
    ptr = ptr->next_data;
    traverse_index++;
  }

  Node *prev_node = ptr->prev_data;
  Node *next_node = ptr->next_data;

  next_node->prev_data = prev_node;
  prev_node->next_data = next_node;

  free(ptr);
  return head;
}

Node *delete_by_value(Node *ptr, int value) {
  Node *head = ptr;
  int _index = 0;

  while (ptr->data != value) {
    _index++;
    ptr = ptr->next_data;
  }

  return delete_by_index(head, _index);
}

// Print the Reverse the doubly linked list.
void reverse_linked_list(Node *ptr) {
  Node *head = ptr;
  while (head->next_data != NULL) {
    head = head->next_data;
  }

  // Start the reverse loop.
  while (head != NULL) {
    cout << head->data << endl;
    head = head->prev_data;
  }
}

int main() {

  Node *n1 = new Node(45);
  Node *n2 = new Node(55);
  Node *n3 = new Node(65);
  Node *n4 = new Node(75);
  Node *n5 = new Node(85);

  n1->prev_data = NULL;
  n1->next_data = n2;

  n2->prev_data = n1;
  n2->next_data = n3;

  n3->prev_data = n2;
  n3->next_data = n4;

  n4->prev_data = n3;
  n4->next_data = n5;

  n5->prev_data = n4;
  n5->next_data = NULL;

  cout << "Right after initializing " << endl;
  show(n1);

  Node *inserted_node = insert(n1, 2, 77);

  cout << "After inserting value at index 2" << endl;
  show(inserted_node);

  Node *deleted_node = delete_by_index(inserted_node, 2);
  cout << "After deleting value at 2" << endl;
  show(deleted_node);

  cout << "After deleting value 75" << endl;
  Node *del_node_1 = delete_by_value(inserted_node, 75);
  show(del_node_1);

  cout << "Printing the reversed linked list" << endl;
  reverse_linked_list(del_node_1);

  return 0;
}