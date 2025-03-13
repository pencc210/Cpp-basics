#include <iostream>
#include <stack>
#include <queue>
using namespace std;


void addArrToQueue(queue<int>& q, int arr[], int size){
    
    for(int i = 0; i < size; i++){
        q.push(arr[i]);
    }
}

void printQueue(queue<int> q){
    if(q.empty()){
        cout << "Queue is empty" <<endl;
    }
    while(!q.empty()){
        cout << q.front() << " ,";
        q.pop();
    }
    cout << endl;
}

//Reverse q using stack
void reverseQueue(queue<int>& q){
    stack<int> s;
    while(!q.empty()){
        s.push(q.front());
        q.pop();
    }
    while(!s.empty()){
        q.push(s.top());
        s.pop();
    }
}

int main(){
    queue<int> q;

    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    addArrToQueue(q, arr, size);
    printQueue(q);
    reverseQueue(q);
    printQueue(q);

    return 0;
}