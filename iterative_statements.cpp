/*
* This program outputs an incremental count from 1 to a number 
* defined by the user (num). It does it by implementing either
* a while or a for loop.
*/


#include <iostream>
using namespace std;


int main(){

    int num, x;

    cout<<"Please enter a number: ";
    cin>>num;

     

    //Using a while loop          

    //x = 1;
    // while (x<=num){          
    //     cout<<x<<endl;
    //     x;
    // }

    //Using for loop

    for(x=1;x<=num;x++){
        cout<<x<<endl;
    }



    return 0;
}