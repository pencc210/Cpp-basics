
/*
 * This program takes in a paragraph and counts the different types of words present. 
 */

#include <iostream>
#include <cctype>
#include <map>
#include <sstream> // For stringstream
#include <cctype>  // For isalpha (detection of alphanumeric chars), tolower (upper case to lower)

using namespace std;

//Converts upper case to lower case and eliminates special characters from each word.
//returns a clean string.
string cleanWord(string word); 


int main(){
    string paragraph;
    cout<<"Please enter a paragraph: ";
    getline(cin, paragraph);

    stringstream ss(paragraph); // Extract words
    string word;
    string cleaned;
    map <string, int> wordCount;

    while(ss >> word){  // for every word in the paragaph
        cleaned = cleanWord(word); // clean the word

        /* if(wordCount.find(cleaned) != wordCount.end()){  //Word is in map
            wordCount[cleaned] += 1;                     //Add 1 to count
        }else{                                           //Word is not in map
            wordCount[cleaned] = 1;                      //Add new word to map
        } */

       wordCount[cleaned]++; // same as function the commened code above (adds 1 if present, add new element if not)
    }

    for(const auto& [word, quantity] : wordCount){
        cout<<word<<": "<<quantity<<endl;
    }
}

string cleanWord(string word){
    string cleaned;
    for(char chr : word){
        if(isalpha(chr)){
            cleaned += tolower(chr);
        }
    }
    return cleaned;
}




