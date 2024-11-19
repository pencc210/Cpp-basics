#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <set>
using namespace std;

// Cleans text (keeps only lowercase letters) and returns word count
int stringCleanAndCount(string &str) {
    set<char> delimiters = {' ', ',', '.'};  // Define the delimiters
    string word;
    int word_count = 0;
    string tempStr;

    for (char c : str) {
        if (delimiters.find(c) != delimiters.end()) {  // Check if character is a delimiter
            if (!word.empty()) {
                word_count++;
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
        word_count++;
        tempStr += word;
    }
    
    str = tempStr;  // Update the original string to cleaned version
    return word_count;
}

// Counts the frequency of each letter in the cleaned string
void countLetterFrequency(const string &str, int freq[]) {
    for (char c : str) {
        freq[c - 'a']++;  // Increment the count of the corresponding letter
    }
}

// Prints the frequency of each letter in alphabetical order
void printLetterFrequency(const int freq[]) {
    for (int i = 0; i < 26; ++i) {
        if (freq[i] > 0) {  // Only print letters that occur
            cout << freq[i] << '\t' << char(i + 'a') << endl;
        }
    }
}

int main() {
    string str;
    cout << "Please enter a line of text: " << endl;
    getline(cin, str);

    // Clean string and count words
    int word_count = stringCleanAndCount(str);

    // Count letter frequency
    int letter_freq[26] = {0};  // Array to store frequencies of 'a' to 'z'
    countLetterFrequency(str, letter_freq);

    // Print results
    cout << word_count <<'\t'<<" words" << endl;
    printLetterFrequency(letter_freq);

    return 0;
}