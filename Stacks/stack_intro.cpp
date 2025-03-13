#include <iostream>
#include <stack>
using namespace std;

int main(){

    stack<int> s;

    int arr[] = {1, 4, 5, 7, 2, 3, 4};

    int sizeArr = sizeof(arr) / sizeof(arr[0]);

    for(int i = 0; i < sizeArr; i++){
        s.push(arr[i]);
    }

    while(!s.empty()){
        cout << s.top() << " ,";
        s.pop();
    }

    return 0;
}