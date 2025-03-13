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

Node* insertNode(int num, Node* root);
void printInOrder(Node* root);
void deleteTree(Node* root);
void printLevelOrder(Node* root);

//Counts the number of leaf nodes
int numOfLeafNodes(Node* root){
    if(root == nullptr){
        return 0;
    }else{
        if(root->right == nullptr && root->left == nullptr){
            return 1;
        }
        int leftSubtree = numOfLeafNodes(root->left);
        int rightSubtree = numOfLeafNodes(root->right);
        return leftSubtree + rightSubtree;
    }
}

/* Simplified syntax
int numOfLeafNodes(Node* root) {
    if (!root) return 0; // Base case
    if (!root->left && !root->right) return 1; // Leaf node
    return numOfLeafNodes(root->left) + numOfLeafNodes(root->right);
}

*/


int main(){

    Node* root = nullptr;

    vector<int> v = {5, 3, 7, 2, 4, 6, 8};

    for(const int& num : v){
        root = insertNode(num, root);
    }

    printLevelOrder(root);
    cout << "Number of leafs: " << numOfLeafNodes(root) <<endl;    
    
    deleteTree(root);
    return 0;
}

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


void printInOrder(Node* root){ //left, root, right
    if(root != nullptr){
        printInOrder(root->left);
        cout << root->data << ", ";
        printInOrder(root->right);
    }
}

void deleteTree(Node* root){
    if(root != nullptr){
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
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