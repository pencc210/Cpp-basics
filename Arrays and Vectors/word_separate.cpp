

#include <iostream>
#include <vector>
#include <sstream>
using namespace std;


string* createWordsArray(string sentence, int& outWordsArrSize){
    vector <string> wordsVec;

    //Separate words and place them in a vector
    string word;
    stringstream ss(sentence);
    while(ss >> word){
        wordsVec.push_back(word);
    }
    //New array size will be the size of vector
    outWordsArrSize = wordsVec.size();

    //Copy words in vector to the array
    string* wordsArr = new string[outWordsArrSize];
    for(int i = 0; i < outWordsArrSize; i++){
        wordsArr[i] = wordsVec[i];
    }

    return wordsArr;
}

void printArray(string* ptr, int size){
    cout<<"There are "<<size<<" words and they are: "<<endl;
    for(int i = 0; i < size; i++){
        cout<<ptr[i]<<endl;
    }
}

int main(){

    string sentence;
    cout<<"Please write a sentence: "<<endl;
    getline(cin, sentence);

    int outWordsArrSize = 0;
    string* wordsPtr;

    wordsPtr = createWordsArray(sentence, outWordsArrSize);
    printArray(wordsPtr, outWordsArrSize);

    delete[] wordsPtr;
    return 0;
}