/*This program receives a sum in dollars and cents and outputs the number 
coins (quarters, dimes, nickels and pennies) */

#include <iostream>
using namespace std;

int main(){
    
    int dollars, cents, sum, quarters, dimes, nickels, pennies;

    cout<<"Please enter your amount in the format of dollars and cents separated by a space:"<<endl;
    cin>>dollars>>cents;

    sum = dollars*100+cents;

    quarters = sum/25;
    sum = sum%25;

    dimes = sum/10;
    sum = sum%10;

    nickels = sum/5;
    sum = sum%5;

    pennies = sum;

    cout<<dollars<<" and "<<cents<<" cents are: "<<endl; 
    cout<<quarters<<" quarters, "<<dimes<<" dimes, "<<nickels<<" nickels and "<<pennies<<" pennies"<<endl;


}