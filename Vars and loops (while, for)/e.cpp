/*
 * This program calculates an approximation of the number e using n terms. O(n) time complexity.
 */

#include <iostream>
using namespace std;



double eApprox(int n); // Returns n term approximation of e


int main(){

    //double fact = factorial(3);
    //cout<<fact; 

    cout.precision(30);
    for (int n = 1; n <= 15; n++) {
        cout<<"n = "<<n<<'\t'<<eApprox(n)<<endl;
    }

    return 0;
}

double eApprox(int n){
    double e = 1.0;
    double factorial = 1.0; 

    if(n == 0){
        e = 0;
    }
    if(n > 1){
        for (int i = 1; i < n; i++){
            factorial *= i;
            e += 1.0 / factorial;
        }
    }
    return e; 
}

