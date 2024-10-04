/*
 * This program	that asks the user to input a positive integer n, and prints all of	the	numbers	
 * from	1 to n that	have more even digits than odd digits.
 */

#include <iostream>
using namespace std;

int main(){

    int n;

    cout<<"Please enter a quatity 'n' of numbers to print: ";
    cin>>n;

    for (int i = 1; i < n; i++){            // Counter loop that designates numbers from 1 to n unto num
        int num = i;
        int even_count = 0, odd_count = 0;  // Declares even and odd digit counters and reinitializes the vars for each numer (num)
        
        // Examine each digit of the current number
        while (0 < num){
            int digit = num % 10;
            
            if (digit % 2 == 0){            // If digit is even encrease even count, otherwise encrease odd count
                even_count ++;
                
            }else{
                odd_count ++;
            }
            num /= 10;                  // Move to the next digit
        }

        if(odd_count < even_count){
            cout<<i<<endl;
        }
    }
}