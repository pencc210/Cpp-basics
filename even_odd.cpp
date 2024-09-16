/* This program receives a number from the user and outputs whether it is odd or even*/

#include <iostream> 
using namespace std;

int main(){

    int num;
    string parity;

    cout<<"Please enter a number: "<<endl;
    cin>>num;

    if (num%2==0){
        parity = "even";
    }
    else{
        parity = "odd";
    }

    cout<<"Your number is: "<<parity<<endl;


    return 0;
}