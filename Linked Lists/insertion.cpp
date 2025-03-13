#include <iostream>
using namespace std;

class Node {
    public: 
    int value; //Value
    Node* next; //Pointer to next node

};

void printLinkedList(Node* current){
    while(current != nullptr){
        cout << current->value << ", "; //Print current value
        current = current->next;        //Set current to next node
    }
}

void frontInsetion(Node** head, int val){
    Node* newNode = new Node; // Create new node
    newNode->value = val;     // Asign value

    newNode->next = *head;    // My new node is the new head so its next should be pointing at prev head address

    *head = newNode;          // Modify head to point to my new node
}

void endInsertion(Node** head, int val){

    //Create node
    Node* newNode = new Node;
    newNode->value = val;
    newNode->next = nullptr; //Its the last so its next is null

    //If list is empty new node will be head
    if(*head == nullptr){
        *head = newNode;
        return;
    }

    //Find last node
    Node* last = *head;

    while(last->next != nullptr){
        last = last->next;
    }

    //Insert new node after last node
    last->next = newNode;

}

void customInsert(Node** previous, int val){ //At any position after a previous node
    //Check if prev is not null
    if(previous == nullptr){
        cout << "Previous cannot be null" << endl;
        return;
    }
    //Create new node
    Node* newNode = new Node;
    newNode->value = val;

    //Connect new node
    newNode->next = (*previous)->next;
    (*previous)->next = newNode;
}

int main(){

    //Initialize nodes in heap
    Node* head = new Node();
    Node* second = new Node();
    Node* third = new Node();

    //Fill in their values and pointers
    head->value = 1;
    head->next = second; //Next is the second pointer

    second->value = 2;
    second->next = third;

    third->value = 3;
    third->next = nullptr; //End of list

    frontInsetion(&head, 2);
    endInsertion(&head, 10);
    customInsert(&third, 123);
    printLinkedList(head);

    Node* current = head;

    while(current != nullptr){ //Dealocate all nodes
        Node* temp = current;
        current = current->next;
        delete temp;
    }

    return 0;
}