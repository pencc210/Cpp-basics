#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;

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

int main(){

    string str = "abc";
    vector<string> substrings;

    substrings = allSubstrings(str);

    for(string s : substrings){
        cout<<s<<", ";
    }
}