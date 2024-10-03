/*This program receives the number of days, hours, and minutes Bill (B) and Jim (J) have worked 
and calculates the total time worked by both of them */

#include <iostream>
using namespace std;

int main(){

    int minB, minJ, hoursB, hoursJ, daysB, daysJ; 
    int minSum, hourSum, extraMin, extraHours, extraDays, minTotal, hoursTotal, daysTotal; 

    cout<<"Please enter the number of days John has worked: ";
    cin>>daysJ;
    cout<<"Please enter the number of hours John has worked: ";
    cin>>hoursJ;
    cout<<"Please enter the number of minutes John has worked: ";
    cin>>minJ;


    cout<<"\n"<<"Please enter the number of days Bill has worked: ";
    cin>>daysB;
    cout<<"Please enter the number of hours Bill has worked: ";
    cin>>hoursB;
    cout<<"Please enter the number of minutes Bill has worked: "<<endl;
    cin>>minB;

    minSum = minB + minJ;
    extraHours = minSum/60;
    minTotal = minSum%60;

    hourSum = hoursB + hoursJ + extraHours;
    extraDays = hourSum/24;
    hoursTotal = hourSum%24;

    daysTotal = daysB + daysJ + extraDays;

    cout<<"The total time both of them worked together is: "<<daysTotal<<" days, "<<hoursTotal<<" hours and "<<minTotal<<" minutes."<<endl;

    return 0; 
}
