#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;

// Generates all substrings of a string
vector<string> allSubstrings(string str);

//Returns true if str1 and str2 are anagrams
bool anagrams(string str1, string str2);

//Returns number of anagramatic pairs in the words list
int anagramaticPairs(vector <string> words);



int main(){

    string str1 = "abba";
    vector<string> substrings;

    //Generate all substrings of str1
    substrings = allSubstrings(str1);
    for(string s : substrings){
        cout<<s<<", ";
    }

    //Check if str1 and str2 are anagrams
    string str2 = "opp";
    cout<<(anagrams(str1, str2) ? "They are anagrams" : "They are not anagrams")<<endl;

    //Count the anagramatic full word pairs in the list words
    vector <string> words = {"abba", "baba", "opp", "ppo", "prop", "sup"};
    cout<<anagramaticPairs(words)<<endl;

    //Count anagramatic pairs of substrings of str1
    cout<<anagramaticPairs(substrings)<<endl;


    
}

//Function to generate all substrings of a string
vector<string> allSubstrings(string str){
    vector<string> substrings;
    string subs;

    for (int i = 0; i < str.length(); i++){
        for(int j = str.length() - i; j >= 1; j--){
            subs = str.substr(i, j);
            substrings.push_back(subs);
        }
    }

    return substrings;
}

//Function to check if two strings are anagrams
bool anagrams(string str1, string str2){

    // If lengths are different, they cannot be anagrams
    if (str1.length() != str2.length()) {
        return false;
    }

    //Make a map for the letters in stirng 1
    map< char, int> lettersStr1;
    for (char l: str1){
        lettersStr1[l] ++;
    }

    //Make a map for the letters in stirng 2
    map< char, int> lettersStr2;
    for (char l: str2){
        lettersStr2[l] ++;
    }

    //Anagrams if maps are the same
    return(lettersStr1 == lettersStr2);
}

//Function to count anagramatic pairs (two words that are anagrams of each other) in a list of words
int anagramaticPairs(vector <string> words){

    unordered_map <string, int> anagramGroups;
    int count = 0;

    for (string word : words){

        //Make a canonical (sorted) form for each word to have a comparison template
        string canonical = word;
        sort(canonical.begin(), canonical.end());

        anagramGroups[canonical]++;
    }

    for (auto& x : anagramGroups){
        int n = x.second;
        if( n > 1){
            // For n items in a group, the number of unique pairs is n * (n - 1) / 2
            // from combinations n choose 2
            count += (n * (n - 1)) / 2;
        }
    }

    return count;
}