/*
 * This program prints all the devisors in a number (num). It runs with time complexity
 * complexity O(sqrt(n))
 */
#include <iostream>
#include <cmath>
using namespace std;

void printDevisors(int num); //Prints all of num's devisors. Time complexity O(sqrt(n))

int main(){

    int num;

    cout<<"Please enter a possitive integer >=2: ";
    cin>>num;

    printDevisors(num);

}

void printDevisors(int num){
    for (int i = 1; i <= sqrt(num); i++){
        if (100 % i == 0){
            cout << i << " ";
        }
    }
    for (int i = sqrt(num); i >= 1; --i) {
        if (num % i == 0 && i != num / i) { 
            cout << num / i << " ";
        }
    }
    cout<<'\n';
}