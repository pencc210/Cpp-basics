/*This program recieves a number of different coins (quarters, dimes, 
nickels and pennies) and outputs the sum in dollars and cents*/

#include <iostream>
using namespace std;

int main(){
    
    int quarters, dimes, nickels, pennies;
    int sum;
    int dollars, cents;

    cout<<"Please enter number of coins: "<<'\n'<<"# of quarters: ";
    cin>>quarters;

    cout<<"# of dimes: ";
    cin>>dimes;

    cout<<"# of nickels: ";
    cin>>nickels;

    cout<<"# of pennies: ";
    cin>>pennies;

    sum = (quarters*25)+(dimes*10)+(nickels*5)+(pennies); 
    dollars = sum/100;                                                      
    cents = sum%100;                                                  

    cout<<"The total is "<<dollars<<" dollars and "<<cents<<" cents"<<endl;
    cout<<sum;

    return 0;
}

