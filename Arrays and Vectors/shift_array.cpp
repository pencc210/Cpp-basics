#include <iostream>
using namespace std;

void rotateArray(int arr[], int size, int k){

    k = k % size; 

    reverse(arr, arr + size);
    reverse(arr, arr + k);
    reverse(arr + k, arr + size);
}

int main(){

    int arr[5] = {1, 2, 3, 4, 5};
    int size = 5, k = 2;

    rotateArray(arr, size, k);

    for(const int& x : arr){
        cout << x << " ";
    }
    return 0;
}