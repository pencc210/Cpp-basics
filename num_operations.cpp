/* This program reads from the user two positive integers, and prints the result of
when we add, subtract multiply, divide, div and mod them*/

#include <iostream>

using namespace std;

int main(){

    int num1, num2, sum, subs, mult, intDiv, module; 
    float floatDiv;

    cout<<"Please enter two possitive integers separeted by a space: "<<endl; 
    cin>>num1>>num2;

    sum = num1 + num2;
    subs = num1 - num2;
    mult = num1 * num2;
    floatDiv = float(num1) / float(num2);
    intDiv = num1 / num2;
    module = num1 % num2;

    cout<<num1<<" + "<<num2<<" = "<<sum<<endl;
    cout<<num1<<" - "<<num2<<" = "<<subs<<endl;
    cout<<num1<<" * "<<num2<<" = "<<mult<<endl;
    cout<<num1<<" / "<<num2<<" = "<<floatDiv<<endl;
    cout<<num1<<" div "<<num2<<" = "<<intDiv<<endl;
    cout<<num1<<" mod "<<num2<<" = "<<module<<endl;

    return 0;

}
