#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

class Node{
    public:
    int data;
    Node *pointer = NULL;

    Node(int value){
        data = value;
    }
};

void show(Node *ptr){
    while(ptr != NULL){
        cout << ptr->data << endl;
        ptr = ptr->pointer;
    }
}

Node* insert(Node *ptr, int data, int index){
    Node *new_node = new Node(data);
    if(index == 0){
        new_node->pointer = ptr;
        ptr = new_node;
        return ptr;
    } else {
        Node *head = ptr;
        int i = 0;
        while(i < index-1){
            head = head->pointer; 
            i++;
        }

        new_node->pointer = head->pointer;
        head->pointer = new_node;

        return NULL;
    }

}

Node* delete_by_index(Node *ptr, int index){
    Node *head = ptr;
    int i = 0;

    if(index == 0){
        head = head->pointer;
        free(ptr);
        return head;
    }

    while(i != index-1){
        head = head -> pointer;
        i++;
    }

    Node *temp = head -> pointer;
    head->pointer = temp->pointer;
    free(temp);
    return ptr;

}

Node* delete_by_value(Node *ptr, int value){
    Node *head = ptr;
    int index = 0;
    int temp_var = INT_MIN;

    // Finding the value.
    while(temp_var != value){
        index++;
        head = head->pointer;
        temp_var = head -> data;
    }

    return delete_by_index(ptr, index);
}

// Miscellaneous
Node *reverse(Node *ptr){

    // Its highly likely that I will have hard time remembering this next time, hence will
    // be explaining this well.

    // prev_node points to the initial pointer.
    Node *prev_node = ptr;
    // head pointer points to next element.
    Node *head = ptr->pointer;

    // Till the head points to the last element starting from 2nd element (as written above)/
    while (head != NULL){

        // Handles the initial case, ie - modify the first node to point to NULL.
        if(prev_node == ptr){
            prev_node->pointer = NULL;
        }
        // next_pointer always stores the value of next node. 
        // (We have to store this as the head pointer will change later).
        // This is important to traverse the linked list.
        Node *next_pointer = head->pointer;
        // Change the head pointer to previous node.
        head->pointer = prev_node;
        // Change to prev_node to current head node.
        prev_node = head;
        // Finally, as mentioned above, change the head value to next value aka next_pointer.
        head = next_pointer;
    }

    // Return the last node.
    // We can't return head, as at the end, head will be pointing to a NULL node.
    Node* new_node = prev_node;
    return prev_node;
}


int main(){
    Node *n1 = new Node(9);
    Node *n2 = new Node(19);
    Node *n3 = new Node(2);
    Node *n4 = new Node(3);

    // linking all the pointers to each other.
    n1->pointer = n2;
    n2->pointer = n3;
    n3->pointer = n4;
    n4->pointer = NULL;

    cout << "Initially the array is - " << endl;
    show(n1);

    cout << "After inserting" << endl;
    insert(n1,10, 4);
    show(n1);

    cout << "Deleting by index" << endl;
    Node *new_node = delete_by_index(n1,4);
    show(new_node);


    cout << "Deleting by value" << endl;
    Node *new_node1 = delete_by_value(n1,19);

    cout << "Until this point, the linked list is - " << endl;
    show(new_node1);

    cout << "Reversing the linked list" << endl;
    Node *reversed_node = reverse(new_node1);

    show(reversed_node);

    cout << "Again reversing the linked list" << endl;
    Node *reversed_node_again = reverse(reversed_node);

    show(reversed_node_again);
}