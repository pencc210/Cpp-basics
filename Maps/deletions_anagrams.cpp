/*
 * Calculates the number of deletions (deleted letters) necesary to make two strings anagrams.
 * Uses an unordered map of string 1, substracts string 2 from it and the deletions will be the 
 * absolute value of the resulting frequency of chars in the map.
 */

#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <cstdlib>
using namespace std;

int main(){
    unordered_map <char, int> strDif;

    string string1;
    string string2;

    string1 = "cde";
    string2 = "dcf";
    
    for(char letter : string1){ //Create dict for string 1
        strDif[letter]++;
    }
    for(char letter : string2){ //Substract letters in string 2 from string 1
        strDif[letter]--;
    }
    
    //Calculate the deletions necessary
    int deletions = 0;
    for(const auto& [letter, freq] : strDif){
        deletions += abs(freq);
    }

    //Print result
    for(const auto& [letter, freq] : strDif){
        cout<<letter<<" "<<freq<<endl;
    }
    cout<<"Deletions: "<<deletions<<endl;

}

