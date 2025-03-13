//Rudimentary way of declaring a linked list 

#include <iostream>
using namespace std;

class Node {
    public: 
    int Value; //Value
    Node* next; //Pointer to next node

};

void printLinkedList(Node* current){
    while(current != nullptr){
        cout << current->Value << ", "; //Print current value
        current = current->next;        //Set current to next node
    }
}


int main(){

    //Initialize nodes in heap
    Node* head = new Node();
    Node* second = new Node();
    Node* third = new Node();

    //Fill in their values and pointers
    head->Value = 1;
    head->next = second; //Next is the second pointer

    second->Value = 2;
    second->next = third;

    third->Value = 3;
    third->next = nullptr; //End of list

    printLinkedList(head);


    return 0;
}