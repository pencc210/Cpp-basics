/*
 * This program calculates the geometric mean of a series of numbers using two methods: 
 * length of sequence first or indifinate length whith termination signaled by -1 input. 
 * The geometric mean of a dataset {a_1, a_2, a_n} is nth root of (a_1 * a_2 * a_n)
*/


#include <iostream>
#include <cmath>
using namespace std;

int main(){

    int n, num;
    int mult = 1, i = 0, power = 0;
    float mean;

    cout<<"Please enter the length of the sequence: ";
    cin>>n;

    // Method A, reading length of sequence first
    cout<<"Please enter your the sequence: "<<endl;

    for (i = 0; i < n; i++){
        cin>>num; 
        mult *= num;
    }
    mean = pow(mult, 1.0/n);                          // Nth root of multiplication 

    cout<<"The geometric mean is: "<<mean<<endl;

    // Reset variables for method B
    mult = 1;       
    i = 0;

    // Method B, continous reading until -1 is entered
    cout<<"Please enter your the sequence: "<<endl;

    while (true) {
    cin >> num;
    if (num == -1) {
        break;  // Exit the loop if the user enters -1
    }
    mult *= num;
    power++;
}

    mean = pow(mult, 1.0/power); 
    cout<<"The geometric mean is: "<<mean<<endl;
}