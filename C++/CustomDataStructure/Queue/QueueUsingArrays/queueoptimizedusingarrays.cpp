#include <fstream>
#include <iostream>

using namespace std;

// 2 pointer approach.
// Space inefficient algorithm
class Queue {
public:
  int *array;
  int size;
  int enqueue_index = -1;
  // We simply shift the dequeue index, proxying that our array starts from the
  // dequeue index.
  int dequeue_index = 0;

  Queue(int _size) {
    size = _size;
    array = new int[size];
  }

  void enqueue(int data) {
    if (!is_full()) {
      enqueue_index++;
      array[enqueue_index] = data;
    }
  }

  int dequeue() {
    if (!is_empty()) {
      int data = array[dequeue_index];
      dequeue_index++;

      return data;
    }
    return -1;
  }

  void show() {
    for (int i = dequeue_index; i < enqueue_index + 1; i++) {
      cout << array[i] << endl;
    }
  }

  bool is_full() {
    if (enqueue_index == size - 1) {
      return true;
    }
    return false;
  }

  bool is_empty() {
    if (enqueue_index < dequeue_index) {
      return true;
    }
    return false;
  }
};

int main() {
  Queue *queue = new Queue(100);
  queue->enqueue(45);
  queue->enqueue(55);
  queue->enqueue(65);
  queue->enqueue(75);
  queue->enqueue(85);

  cout << "Initially the queue is" << endl;
  queue->show();

  queue->dequeue();
  queue->dequeue();

  cout << "After deququeing 2 times, the queue is" << endl;

  queue->show();

  return 0;
}