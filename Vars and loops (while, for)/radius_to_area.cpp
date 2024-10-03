/* This program takes the radius of a circle and calculates the area*/

#include <iostream>
using namespace std;

const double PI = 3.14;
int main(){

    float radius;
    float area;

    cout<<"Please wrhite the radius of a circle:"<<endl;
    cin>>radius;

    area = PI*radius*radius;


    cout<<"The area is "<<area<<endl;

    return 0;

}
