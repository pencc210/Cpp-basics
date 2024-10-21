
#include <iostream>
using namespace std;


int fib(int n); // Retuns the nth fibonacci value 

int main(){
    int num; 

    cout<<"Please enter a possitve integer: ";
    cin>> num; 

    int element = fib(num);
    cout<<element<<endl;

}

int fib(int n){

    int f1 = 1;
    int f2 = 1;
    int fn = 1;

    if (n == 1){
        return fn;
    }else if (n == 2){
        return fn;
    }else{
        for (int i = 3; i <= n; i++){
            fn = f1 + f2;
            f1 = f2;
            f2 = fn;
        }

    }
    return fn;

}