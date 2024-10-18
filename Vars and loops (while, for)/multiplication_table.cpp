/*
 * This program prints and nxn multiplication table
 */

#include <iostream>
using namespace std;

void multiplicationTable(int n){

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cout<<i*j<<"    ";

    }
    cout<<'\n';

    }

}

int main(){
    int n;

    cout<<"Please enter a possitive integer: "<<endl;
    cin>>n;

    multiplicationTable(n);

    return 0;
}