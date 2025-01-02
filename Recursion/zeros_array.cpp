#include <iostream>
using namespace std;

void maxZeroLength(int arr[], int size, int startIndx, int& count){
    if(size <= 1){
        if(arr[0] == 0){
            count++;
            return;
        }
    }else{
        if(arr[0] == 0){
            count++;
        }if(arr[1] == 0){
            count++;
        }
        maxZeroLength(arr + 1, size - 1, );
    }  
}

int main(){

    int size = 6; 
    int arr[] = {0, 0, 1, 0, 0, 0};

    int count = 0;

    maxZeroLength(arr, size, 0, count);

    cout<<count;

    return 0;
}