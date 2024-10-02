
/* 
 * This program reads a positive integer n and prints the first 
 * n even numbers. It uses two methods: a while loop and a for loop. 
*/


#include <iostream>

using namespace std;

int main(){

    int n, even_counter, num;

    cout<<"Please enter a positive integer: ";
    cin>>n;

    even_counter = 0;
    num = 0;

    while(even_counter<n){                                     // First method
        num += 2;                                              // Adds 2 in every iteration so num is always even
        cout<<num<<endl;                                       // Prints num and adds 1 to even counter
        even_counter += 1;
    }

    num = 0;

    for(even_counter = 0; even_counter<n; even_counter += 1){  // Second method
        num += 2;
        cout<<num<<endl;
    }

}