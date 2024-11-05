/*
 * This program takes in a string from the user and indicates whether it is a 
 * palindrome or not. 
 */

#include <iostream>
#include <sstream>
#include <vector>
using namespace std; 

//Returns true if str is a palindrome
bool isPalindrome(string str);

int main(){

    string word;

    cout<<"Please enter a word: ";
    cin>>word;

    if(isPalindrome(word)){
        cout<<word<<" is a palindrome";
    }else{
        cout<<word<<" is NOT a palindrome";
    }
    cout<<endl;
    return 0;
}

bool isPalindrome(string str) {
    int left = 0;
    int right = str.length() - 1;

    while (left < right) {
        if (str[left] != str[right]) {
            return false; // If characters don't match, it's not a palindrome
        }
        left++;
        right--;
    }
    return true; // All characters matched symmetrically
}