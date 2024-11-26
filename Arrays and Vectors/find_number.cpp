#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

// Function to dynamically grow an array
int* resizeArray(int* oldArray, int oldSize, int newSize) {
    int* newArray = new int[newSize];
    for (int i = 0; i < oldSize; ++i) {
        newArray[i] = oldArray[i];
    }
    delete[] oldArray; // Free the old array
    return newArray;
}

// Function to read the input sequence and return the results dynamically
int* readInputSequence(int*& inputArray, int& arraySize) {
    int capacity = 10;
    inputArray = new int[capacity]; // Dynamically allocate initial array
    arraySize = 0;

    int num;
    while (true) {
        cin >> num;
        if (num == -1) break;

        // Resize the array if necessary
        if (arraySize == capacity) {
            capacity *= 2;
            inputArray = resizeArray(inputArray, arraySize, capacity);
        }

        inputArray[arraySize++] = num; // Add the number to the array
    }

    return inputArray; // Return the dynamically allocated array
}

// Function to find matching line numbers
int* findMatchingLines(int* inputArray, int arraySize, int search, int& resultSize) {
    int* lineNumbers = new int[10]; // Start with a small array for results
    int capacity = 10;
    resultSize = 0;

    for (int i = 0; i < arraySize; i++) {
        if (inputArray[i] == search) {
            if (resultSize == capacity) {
                capacity *= 2;
                lineNumbers = resizeArray(lineNumbers, resultSize, capacity);
            }
            lineNumbers[resultSize++] = i + 1; // Store 1-based line numbers
        }
    }

    return lineNumbers; // Return the results dynamically
}

// Function to print the results
void printResults(int search, int* lineNumbers, int resultSize) {
    if (resultSize == 0) {
        cout << "Number not foundd" << endl;
    } else {
        cout << search << " shows in lines ";
        for (int i = 0; i < resultSize; ++i) {
            cout << lineNumbers[i];
            if (i < resultSize - 1) {
                cout << ", ";
            } else {
                cout << "." << endl;
            }
        }
    }
}


//Finds searched number indices without using vectors
void main1() {
    int* inputArray = nullptr; // Dynamically allocated input array
    int arraySize = 0;

    //Read the input sequence
    readInputSequence(inputArray, arraySize);

    //Ask for the number to search
    int search;
    cout << "Please enter a number you want to search: ";
    cin >> search;

    //Find matching line numbers
    int resultSize = 0;
    int* lineNumbers = findMatchingLines(inputArray, arraySize, search, resultSize);

    //Print the results
    printResults(search, lineNumbers, resultSize);

    //Clean up dynamically allocated memory
    delete[] inputArray;
    delete[] lineNumbers;
}


//Takes input from user until it is -1 and returns input vector
vector<int> inputVector(){
    vector<int> vec;
    int num;
    while (true){
        cin>>num;
        if (num != -1){
           vec.push_back(num); 
        }else{
            break;
        }
    }
    return vec;
}

vector<int> findIndices(vector<int> numVec, int search){
    vector<int> foundIndex;
    for(int i = 0; i < numVec.size(); i ++){
        if(numVec[i] == search){
            foundIndex.push_back(i + 1);
        }
    }
    return foundIndex;
}

void printIndices(vector<int> foundIndex, int search){
    if(!foundIndex.empty()){
        cout<<search<<" shows in lines ";
        for(int i = 0; i < foundIndex.size(); i++){
            cout<<foundIndex[i];
            if(i < foundIndex.size() - 1){
                cout<<", ";
            }else if(i == foundIndex.size() - 1){
                cout<<"."<<endl;
            }
        }
    }else{
        cout<<"Number not found."<<endl;
    }
}

//Finds the searched number positions using vectors
void main2(){

    //Generate input vector
    vector<int> numVec = inputVector();

    int search;
    cout<<"Please enter a number you want to search: "<<endl;
    cin>>search;

    //Save the indexes of numVec in which the searched number appears
    vector<int> foundIndex = findIndices(numVec, search);
    //Print out indexes in which the searched number is if it is found
    printIndices(foundIndex,search);
    
}

int main(){
    cout<<"Please enter a sequence of possitive integers each in a separete line"<<endl;
    cout<<"End your input by typing -1"<<endl;

    main1();
    //main2();

}