#include <iostream>
#include <fstream>

using namespace std;

class Stack{
    public:

    int size;
    int top; // Stores the index of first element.
    int *array;

    Stack(int stack_size){
        size = stack_size; 
        top = -1;
        array = new int[stack_size];
    };

    bool _is_empty(){
        if (top == -1){
            return true;
        }
        return false;
    }

    bool _is_full(){
        if(top == size-1){
            return true;
        }
        return false;
    }

    void push(int data){
        if(_is_full()){
            throw "Stack is alredy full";
        }
        top++;
        array[top] = data;
    }

    int pop(){
        if(_is_empty()){
            throw "Stack is already empty";
        }

        int pop_value = array[top];
        top--;

        return pop_value;
    }

    void show(){
        for(int i = top; i > -1 ; i--){
            cout << array[i] << endl;
        }
    }

    int peek(){
        return array[top];
    }

    int element_at_position(int index){
        // Since indexing in arrays begin from leftmost end and the 

        int array_index = (top+1)- index;
        if(array_index < 0){
            throw "Invalid element requested";
        }

        return array[array_index];
    }

    int stackTop(){
        return peek();
    }

    int stackBottom(){
        return array[0];
    }
};

int main(){

    Stack *stack = new Stack(100);
    // []
    stack->push(12);
    // [12]  <--- Inserting from here.
    stack->push(14);
    // [12,14] <--- Inserting from here.
    stack->push(6);
    // [12,14,6] <--- Inserting from here.

    stack->show();
    cout << "Popped value is" << stack->pop() << endl;
    stack->show();

    cout << "The topmost element is " << stack->peek() << endl;

    cout << "2nd element from the top is " << stack->element_at_position(2) << endl;

    return 0; 
}