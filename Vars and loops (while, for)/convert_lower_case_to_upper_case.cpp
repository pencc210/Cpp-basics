/* This program converts lower case letters to upper case ones 
using the ASCII table*/

#include <iostream>
using namespace std;

int main(){

    char low_letter, up_letter;

    cout<<"Please enter a lower case letter: "<<endl;
    cin>>low_letter;

    up_letter = (int)low_letter - 32; //the numerical ASCII of lower case minus 32 is the correponding ASCII of uppercase

    cout<<"The uppercase of "<<low_letter<<" is: "<<up_letter<<endl;


    return 0;


}