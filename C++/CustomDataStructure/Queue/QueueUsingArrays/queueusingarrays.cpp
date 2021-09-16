#include <fstream>
#include <iostream>

using namespace std;

class Queue {
public:
  int *array;
  int enqueue_index = -1;

  Queue(int size) { array = new int[size]; }

  void enqueue(int data) {
    enqueue_index++;
    array[enqueue_index] = data;
  }

  int dequeue() {
    int data = array[0];
    int i = INT16_MIN;

    // Here, we need to run a algorithm of O(n) to shift all the elements after
    // removing the first index. A better 2 pointer solution is implemented in
    // queuesoptimizedusingarrays.cpp.
    for (i = 1; i < enqueue_index + 1; i++) {
      array[i - 1] = array[i];
    }
    enqueue_index--;
    return data;
  }
};

int main() {
  Queue *queue = new Queue(100);
  queue->enqueue(45);
  queue->enqueue(55);
  queue->enqueue(65);
  queue->enqueue(75);

  queue->dequeue();
  queue->dequeue();

  return 0;
}