#include <iostream>
using namespace std;

class Node {
public:
    int value;       // Data for the node
    Node* next;     // Pointer to the next node
    
    Node(int val) : value(val), next(nullptr) {}  // Constructor to initialize node
};

class LinkedList {
public:
    Node* head;  // Pointer to the first node
    
    LinkedList() : head(nullptr) {}  // Constructor to initialize the list with an empty head
    
    void printList() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->value << " ";
            temp = temp->next;
        }
        cout << endl;
        delete temp;
    }

    void insertFront(int val){
        //New node, asign value
        Node* newNode = new Node(val);

        //Set new next to head address
        newNode->next = head;

        //Set new node as head
        head = newNode;
    }

    void deleteFront(){

        if (head == nullptr){
            cout << "List is empty" << endl;
            return;
        }

        Node* temp = head;
        head = head->next;
        delete temp;
    }

    void deleteList(){ //Delete the whole list after use

        while(head != nullptr){
            Node* temp = head;
            head = head->next;
            delete temp;
        }

    }

    void searchInList(int val){
        Node* temp = head;
        int count = 0;
        while(temp != nullptr){
            if(temp->value == val){
                count ++;
            }
            temp = temp->next;
        }

        if(count == 0){
            cout << val << " is not in list" << endl;
            return;
        }else{
            cout << val << " appears " << count << " times in list" << endl;
        }

    }
};


int main(){

    LinkedList list;
    list.insertFront(10);
    list.insertFront(12);
    list.insertFront(2);

    list.printList();

    list.deleteFront();

    list.printList();

    list.searchInList(10);
    list.searchInList(19);

    list.deleteList();

    return 0;
}