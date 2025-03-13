/* 
 * Added fx to find lowest common ancestor
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

Node* lowestCommonAncestor(Node* root, Node* p, Node* q){
    if(root == nullptr){
        return nullptr;
    }
    if((p->data < root->data) && (q->data < root->data)){ //if both nodes are smaller than root search left subtree
        return lowestCommonAncestor(root->left, p, q);
    }
    if((p->data > root->data) && (q->data > root->data)){ //if both nodes are bigger than root search right subtree
        return lowestCommonAncestor(root->right, p, q);
    }
    return root; //if p and q are on different sides LCA is the root
}

int main(){

    Node* root = nullptr;

    vector<int> v = {6, 2, 8, 0, 4, 7, 9, 3, 5};

    for(const int& num : v){
        root = insertNode(num, root);
    }

    printLevelOrder(root);
    cout << endl; 

    Node* p = root->left;
    Node* q = root->right;
    cout << "Lowest common ancestor of 2 and 8 is: " << lowestCommonAncestor(root, p, q)->data << endl;

    p = root->left; // node 2
    q = root->left->right; //node 4
    cout << "Lowest common ancestor of 2 and 4 is: " << lowestCommonAncestor(root, p, q)->data << endl;

    p = root->left->right->left; // node 3
    q = root->left->right->right; //node 5
    cout << "Lowest common ancestor of 3 and 5 is: " << lowestCommonAncestor(root, p, q)->data << endl;




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