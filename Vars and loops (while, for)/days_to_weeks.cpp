
/* This program takes a number of days form a user and outputs the equivalent
number of weeks + extra days*/

#include <iostream>
using namespace std;

int main(){

    int days;
    int x_days;
    int weeks;

    cout<<"Please enter the number of days: "<<endl;
    cin>>days;

    weeks = days/7;
    x_days = days%7;

    cout<<weeks<<" weeks and "<<x_days<<" days."<<endl;

    return 0;

}
