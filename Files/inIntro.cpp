//For reading files
#include <iostream>
#include <fstream>
using namespace std;


//Super useful function to open files
void openInputFile(ifstream& inFile){
    string filename;
    cout << "What is the file name? " << endl;
    cin >> filename;
    inFile.open(filename); //tries to open in for the first time
    while (!inFile) //failed to open
    {
        cout << "FILE FAILED TO OPEN!" << endl; 
        cout << "What is the file name? " << endl;
        cin >> filename;
        inFile.clear(); //clears previous failed flag 
        inFile.open(filename);
    }
    
}

int main(){

    //Open the file
    ifstream inFile;
    openInputFile(inFile);

    //Create a vector to store values of file
    vector<int> v; 
    int value; 

    while(inFile >> value){ //get each value from the file
        v.push_back(value); //add them to vector
    }

    double sum; 
    for(int item : v){
        sum += item;
    }

    cout<<"The average of numbers in the file is: "<<sum / v.size() << endl;


    return 0;
}