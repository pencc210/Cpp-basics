/*
 * This program finds the first non repeating letter in a string and prints it out
 * It first generates a letter frequency map for the string and then traverses
 * the string to find the first letter with a frequency of 1
 */

#include <iostream>
#include <unordered_map>

using namespace std;


// Finds frist non repeating character in string
char firstNonRepeatingChar(const string& s){
    unordered_map <char, int> letters;
    //Fill in letter frequency map for string str
    for(char l : s){
        letters[l]++;
    }

    for(char l : s){
        if(letters[l] == 1){
            return l;
        }
    }
    return '_';
}

int main(){
    string str;

    cout << "Please enter a string; " << endl;
    cin >> str;
    cout << "The first non repeating character is " << firstNonRepeatingChar(str) << endl;

    return 0;
}