#include <iostream>
#include <stack>
#include <queue>
using namespace std;

bool isBalanced(string s){

    int size = s.length();
    stack<char> stk;
    
    if(size % 2 != 0){ //Odd means unmached
        return false;  
    }

    for(char c : s){

        if (c == '(' || c == '{' || c == '[') {
            stk.push(c);
        }else{
            if(stk.empty()) return false;

            //Else: stack not empty, compare symbols
            if((c == ')' && stk.top() != '(') ||
               (c == '}' && stk.top() != '{') ||
               (c == ']' && stk.top() != '[')) {
                return false;
            }

            //If chars coincide pop and move on to next one
            stk.pop();
        }
    }
    //If it did not return false on any char and the stack is empty we return true
    return stk.empty();
    
}


int main(){

    string s = "{[()]}";
    cout << (isBalanced(s) ? "Is balanced" : "Is not balanced") << endl;

}