#include <iostream>
#include <queue>
using namespace std;

class Node {
    public: 

    int data;
    Node* left;
    Node* right;

    Node(int data) : data(data), left(nullptr), right(nullptr) {}
};

Node* insertNode(int num, Node* root){

    if(root == nullptr){
        return new Node(num);
    }else{
        if(num < root->data){
            root->left = insertNode(num, root->left);
        }else{
            root->right = insertNode(num, root->right);
        }
    }
    return root;
}

void printInOrder(Node* root){
    if(root != nullptr){
        printInOrder(root->left);
        cout << root->data << ", ";
        printInOrder(root->right);
    }
}

void printPreOrder(Node* root){ // root, left, right
    if(root != nullptr){
        cout << root->data << ", ";
        printPreOrder(root->left);
        printPreOrder(root->right);
    }   
}

void printPostOrder(Node* root){ // left, right, root
    if(root != nullptr){
        printPostOrder(root->left);
        printPostOrder(root->right);
        cout << root->data << ", ";
    }
}

void printLevelOrder(Node* root){
    if (root == nullptr) return; // Handle empty tree

    queue <Node*> q;
    q.push(root);

    while(!q.empty()){

        Node* node = q.front(); //Current node is root
        q.pop(); //Remove form queue
        cout << node->data << ", "; //Print out root data
 
        if(node->left != nullptr){
            q.push(node->left); //If root has left node add data to queue
        }
        if(node->right != nullptr){
            q.push(node->right); //Same for right node
        }

    }
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

    vector<int> v = {5, 3, 7, 2, 4, 6, 8};

    for(const int& num : v){
        root = insertNode(num, root);
    }

    cout << "Print in order:" << '\t';
    printInOrder(root);
    cout << endl;

    cout << "Print pre order:" << '\t';
    printPreOrder(root);
    cout << endl;

    cout << "Print post order:" << '\t';
    printPostOrder(root);
    cout << endl;


    cout << "Print level order:" << '\t';
    printLevelOrder(root);
    cout << endl;

    deleteTree(root);

    return 0;
}