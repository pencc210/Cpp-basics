/* This program receives an integer form the user and prints its absolute value*/

#include <iostream>
using namespace std;

int main(){

    int num, absolute; 

    cout<<"Please write an integer: "<<endl;
    cin>>num;
    absolute = num;

    if(num<0)
        absolute = num*(-1);

    cout<<"The absolute value of: "<<num<<" is: "<<absolute<<endl;

    return 0;
}