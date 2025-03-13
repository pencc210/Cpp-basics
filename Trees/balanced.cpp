/* 
 * Added fx to know if our BST is balanced
*/

#include <iostream>
#include <queue>
#include <cmath>
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

int treeHeight(Node* root){
    if (root == nullptr){ //Base case
        return 0;
    }else{
        int leftSubtree = treeHeight(root->left);
        if(leftSubtree == -1){ return -1; } //Passes forward the -1 returned in prev cycle that detected height difference > 1

        int rightSubtree = treeHeight(root->right);
        if(rightSubtree == -1){ return -1; }

        if(abs(leftSubtree - rightSubtree) > 1){
            return -1;
        }else{
            return max(rightSubtree, leftSubtree) + 1;
        }
        
    }
}
bool isBalanced(Node* root){
    return treeHeight(root) != -1;
}


int main(){

    Node* root = nullptr;

    vector<int> v = {5, 3, 7, 2, 4, 6, 8}; //Unbalanced input {5, 4, 3, 2, 1}

    for(const int& num : v){
        root = insertNode(num, root);
    }

    printLevelOrder(root);

    cout << "The tree is "  << (isBalanced(root) ? "balanced" : "not balanced") << endl;
    
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