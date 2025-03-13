#include <iostream>
#include <stack>
using namespace std;


int main(){

    string str;
    stack<char> s;

    cout << "Enter a string to reverse: " << endl;
    getline(cin, str);

    for(char letter : str){
        s.push(letter);
    }

    while(!s.empty()){
        cout<<s.top();
        s.pop();
    }
    cout << endl;

    return 0;
}