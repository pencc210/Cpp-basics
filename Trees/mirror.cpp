/* 
 * Added fx to return the mirror image of a tree
*/

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
void deleteTree(Node* root);
void printLevelOrder(Node* root);

void mirrorTree(Node* root){
    if(root == nullptr){
        return;
    }else{
        mirrorTree(root->left);
        mirrorTree(root->right);
        Node* temp = root->left;
        root->left = root->right;
        root->right = temp; 
    }
}

int main(){

    Node* root = nullptr;

    vector<int> v = {5, 3, 7, 2, 4, 6, 8};

    for(const int& num : v){
        root = insertNode(num, root);
    }

    printLevelOrder(root);
    cout << endl; 

    mirrorTree(root);

    printLevelOrder(root);
    cout << endl; 

    deleteTree(root);

    return 0;
}

Node* insertNode(int num, Node* root){
    if(root == nullptr){
        return new Node(num);
    }else{
        if(num < root->data){
            root->left = insertNode(num, root->left);  // Recursively insert into left subtree
        }else{
            root->right = insertNode(num, root->right); // Recursively insert into right subtree
        }
    }
    return root;
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