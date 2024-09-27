/*
 * In this program the user can indicate the rounding of a number in one of three methods: 
 * ceiling round (1.2 --> 2), floor round (1.3 --> 1) and nearest integer round 
 * (ceiling round if decimals are >= 0.5, floor round otherwise). 
*/

#include <iostream>
using namespace std; 

int main(){

    const int FLOOR_ROUND = 1;
    const int CEILING_ROUND = 2;
    const int ROUND = 3;

    float num, decimals;
    int roundingMethod, roundNumber, numInt;

    cout<<"Please enter a Real number: "<<endl;
    cin>>num;

    cout<<"Choose your rounding method: "<<endl;
    cout<<"1.Floor round"<<endl;
    cout<<"2.Celing round"<<endl;
    cout<<"3.Round to the nearest whole number"<<endl;
    cin>>roundingMethod;

    numInt = num;                               //implicit casting to gets rid of decimals and returns an integer
    decimals = num - numInt;                    //isolate decimal value

    switch(roundingMethod){

        case FLOOR_ROUND:
            roundNumber = numInt;                      //reused var. numInt = int value of num
        break;
        case CEILING_ROUND:
            roundNumber = (num + 1)/1;                // adds 1 and gets rid of decimals to return next high int
        break;

        case ROUND:
            if (decimals >= 0.5){
                roundNumber = (num + 1)/1;
            } else{
                roundNumber = numInt;
            }
        break;
    }

    cout<<roundNumber<<endl;
}