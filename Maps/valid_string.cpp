/*
 * Hackerrank: This program determines a string to be valid if its characters appear the same number
 * of times with only one character deletion possible. If the string is valid it prints
 * out YES and if it's not it prints out NO. 
 */

#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;

int main(){

    string s = "aabbc";
    
    
    
    //Letter frequency map
    unordered_map<char, int> letterFreq;
    //Fill in map
    for (char letter : s){
        letterFreq[letter]++;
    }

    //Map the frequencies
    unordered_map<int, int> freqCount;
    for (const auto& [letter, freq] : letterFreq) {
        freqCount[freq]++;
    }

    //Analyze frequency counts
    if (freqCount.size() == 1) {
        // All characters have the same frequency
        cout << "YES" << endl;
        return 0;
    }if(freqCount.size() == 2){ //We have 2 frequencies of letters
        auto it = freqCount.begin(); //pointer to start of freqCount map
        int freq1 = it->first, count1 = it->second; ++it;
        int freq2 = it->first, count2 = it->second;

         // Ensure freq1 is the smaller frequency
        if (freq1 > freq2) {
            swap(freq1, freq2);
            swap(count1, count2);
        }

        // Case 1: One frequency is 1 and appears exactly once
        if (freq1 == 1 && count1 == 1) {
            cout << "YES" << endl;
            return 0;
        }

        // Case 2: The difference between the two frequencies is 1,
        // and the higher frequency appears exactly once
        if (freq2 - freq1 == 1 && count2 == 1) {
            cout << "YES" << endl;
            return 0;
        }
    }


    // Otherwise, it's not valid
    cout << "NO" << endl;
    return 0;
}