//For out files (creating and writing on files)

#include <iostream>
#include <fstream>
using namespace std;

int main(){

    ofstream outFile; //We can also declare these two lines in one using the constructor
    outFile.open("outFile.txt"); // for ofstream types: ofstream outfile("outfile.txt")

    outFile<<"Heyo"<<endl; //writes in the file


    outFile.close();
    return 0; 
}