#include <iostream>
using namespace std;

class Node {
    public:
    
    int data;
    Node* left;
    Node* right;

    
    Node (int num) : data(num), left(nullptr), right(nullptr) {}
};

Node* insertNode(int num, Node* root){

    if(root == nullptr){
        return new Node(num); //Base case: tree is empty we create node and return pointer
    }else{
        if(num < root->data){
            root->left = insertNode(num, root->left); //num if smaller than root we insert it in left, fx returns pointer to new node
        }
        else{
            root->right = insertNode(num, root->right);
        }
    }
    return root;
};

void printInOrder(Node* root){ //left, root, right
    if(root != nullptr){
        printInOrder(root->left);
        cout << root->data << ", ";
        printInOrder(root->right);
    }
}

bool checkInTree(int num, Node* root){
    if(root != nullptr){
        if(root->data == num){
            return true;
        }else{
            if(num < root->data){
                return checkInTree(num, root->left);
            }else{
                return checkInTree(num, root->right);
            }
        }
    }
    return false;
}

void deleteTree(Node* root){
    if(root != nullptr){
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
    }
}

int main(){

    Node* root = nullptr;

    vector<int> v = {5, 3, 6, 4, 2};

    for(const int& num : v){
        root = insertNode(num, root);
    }

    printInOrder(root);

    int number = 5;
    cout << "Number "<< number << " " << (checkInTree(number, root) ? "is in tree" : "is not in tree") << endl;

    deleteTree(root);
}