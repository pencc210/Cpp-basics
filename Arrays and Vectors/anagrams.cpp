#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <set>
using namespace std;

// Cleans text (keeps only lowercase letters) 
void stringClean(string &str);
//Checks if str1 and str2 are anagrams
bool anagramCheck(string str1, string str2);

int main() {
    string str1;
    string str2;
    cout << "Please enter a first line of text: " << endl;
    getline(cin, str1);
    cout << "Please enter a second line of text: " << endl;
    getline(cin, str2);

    // Clean strings 
    stringClean(str1);
    stringClean(str2);

    if(anagramCheck(str1, str2)){
        cout<<"They are anagrams"<<endl;
    }else{
        cout<<"They are NOT anagrams"<<endl;
    }

    return 0;
}


// Cleans text (keeps only lowercase letters) and returns word count
void stringClean(string &str) {
    set<char> delimiters = {' ', ',', '.'};  // Define the delimiters
    string word;
    string tempStr;

    for (char c : str) {
        if (delimiters.find(c) != delimiters.end()) {  // Check if character is a delimiter
            if (!word.empty()) {
                tempStr += word;
                word.clear();  // Clear word for next one
            }
        } else {
            if (97 <= c && c <= 122) { // Lowercase
                word += c;  // Add character to the current word
            } else if (65 <= c && c <= 90) { // Uppercase
                word += (c + 32);  // Make lowercase and add to current word            
            }
        }
    }

    // Handle the last word (if any)
    if (!word.empty()) {
        tempStr += word;
    }
    
    str = tempStr;  // Update the original string to cleaned version
}

//Checks if str1 and str2 are anagrams
bool anagramCheck(string str1, string str2){
    sort(str1.begin(),str1.end());
    sort(str2.begin(),str2.end());

    return (str1 == str2);
}