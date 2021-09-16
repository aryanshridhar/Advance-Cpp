#include <fstream>
#include <iostream>

using namespace std;

class Queue {
public:
  int *array;
  int size;
  int enqueue_index = -1;
  int dequeue_index = -1;

  Queue(int _size) {
    size = _size;
    array = new int[size];
  }

  void enqueue(int data) {
    if (!is_full()) {
      enqueue_index = (enqueue_index + 1) % size;
      array[enqueue_index] = data;

    } else {
      throw "The queue is already full.";
    }
  }

  int dequeue() {
    if (!is_empty()) {
      dequeue_index = (dequeue_index + 1) % size;
      int val_to_remove = array[dequeue_index];
      return val_to_remove;
    } else {
      throw "The queue is already empty";
    }
  }

  void show() {
    if (is_empty()) {
      cout << "The queue is currently empty" << endl;
    } else {
      int i = dequeue_index;

      cout << array[(i + 1) % size] << endl;
      i = (i + 1) % size + 1;

      while (i != enqueue_index + 1) {
        cout << array[i] << endl;
        i = (i + 1) % size;
      }
    }
  }

  bool is_full() {
    if ((enqueue_index + 1) % size == dequeue_index) {
      return true;
    }
    return false;
  }

  bool is_empty() {
    if (enqueue_index % size == dequeue_index) {
      return true;
    }
    return false;
  }
};

int main() {

  Queue *q1 = new Queue(6);

  q1->enqueue(14);
  q1->enqueue(24);
  q1->enqueue(34);
  q1->enqueue(44);
  q1->enqueue(54);

  q1->dequeue();
  q1->dequeue();
  q1->dequeue();
  q1->dequeue();
  q1->dequeue();

  q1->enqueue(64);

  q1->dequeue();

  q1->enqueue(24);

  q1->enqueue(34);
  q1->enqueue(44);
  q1->enqueue(54);

  q1->show();

  return 0;
}
