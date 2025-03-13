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

int treeHeight(Node* root){
    if (root == nullptr){ //Base case
        return -1;
    }else{
        int leftSubtree = treeHeight(root->left);
        int rightSubtree = treeHeight(root->right);
        return max(rightSubtree, leftSubtree) + 1;
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

    cout << "Tree height" << treeHeight(root) <<endl;
    printLevelOrder(root);
    deleteTree(root);
}