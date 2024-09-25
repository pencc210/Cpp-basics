/*
 * This program solves a quadratic equation (ax² + bx + c = 0) and determines
 * if it has infinite, none, one, or two real solutions based on the input coefficients.
*/


#include <iostream>
#include <cmath>
using namespace std;


int main(){

    int a, b, c, type;
    float x1, x2, discrim;
    string solution;

    cout<<"Please enter the value of a: ";
    cin>>a;
    cout<<"Please enter the value of b: ";
    cin>>b;
    cout<<"Please enter the value of c: ";
    cin>>c;
    
    type = 0;
    discrim = (b*b - 4*a*c);                            //discriminant for equation classification

    if(a == 0 && b == 0){
        type = 1;
        if(c == 0){
            solution = "Infinite number of solutions";
        }
        if(c != 0){
            solution = "No solution";
        }
    }
    if (a != 0){
        if(discrim<0){
            type = 1;
            solution = "No real solution";
        }
        if(discrim==0){
            type = 2;                       //One solution case
            x1 = (-b+sqrt(discrim))/(2*a);
        }
        if(discrim>0){
            type = 3;                       //Two solutions case
            solution = "Two solutions";
            x1 = (-b+sqrt(discrim))/(2*a);
            x2 = (-b-sqrt(discrim))/(2*a);
        }
    }

    // Print result according to type of equation 

    if(type == 1){
        cout<<solution<<endl;
    }
    if(type == 2){
        cout<<"This equation has a singe real solution: x="<<x1<<endl;
    }
    if(type == 3){
        cout<<"This equation has a two real solutions: x1="<<x1<<" and x2="<<x2<<endl;
    }

}

