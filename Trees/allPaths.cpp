/* 
 * Added fx to print all paths of a tree from the root to its leaf nodes
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

void insertLevelOrder(Node*& root, vector<int> values);
void deleteTree(Node* root);
void printLevelOrder(Node* root);

void printAllPaths(Node* root, vector <int>& path){
    if(root == nullptr) return;

    path.push_back(root->data);

    if(root->right == nullptr && root->left == nullptr){ //When it reaches a leaf it prints path
        for(const int& num : path){
            cout << num << " -> ";
        }
        cout << endl;
    }
        
    printAllPaths(root->left, path);
    printAllPaths(root->right, path);
    path.pop_back(); //errase last element before returning
    
}

int main(){
    Node* root = nullptr;
    vector<int> v = {1, 2, 3, 4, 5};  

    insertLevelOrder(root, v);  

    printLevelOrder(root);
    cout << endl; 

    vector<int> path;
    printAllPaths(root, path);

    deleteTree(root);
    return 0;
}

void insertLevelOrder(Node*& root, vector<int> values) {
    if (values.empty()) return;

    root = new Node(values[0]);
    queue<Node*> q;
    q.push(root);

    int i = 1;
    while (i < values.size()) {
        Node* current = q.front();
        q.pop();

        if (i < values.size()) {
            current->left = new Node(values[i++]);
            q.push(current->left);
        }

        if (i < values.size()) {
            current->right = new Node(values[i++]);
            q.push(current->right);
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