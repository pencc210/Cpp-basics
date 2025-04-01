#include <iostream>
using namespace std;

void reverseArray(int arr[], int size){ //Loop approach
    
    for(int i = 0, j = size - 1 ; i <= (size / 2); i++, j--){ // swap elements symmetrically until the middle is reached
        swap(arr[i], arr[j]);
    }
}


void reverseArrayPtr(int arr[], int size){ //Pointer approach

    int *ptr1 = arr;
    int *ptr2 = arr + (size - 1);

    while (ptr1 < ptr2){
        int temp = *ptr1;
        *ptr1 = *ptr2;
        *ptr2 = temp;

        ptr1 ++;
        ptr2 --;
    }
}


int main(){

    int arr[5] = {1, 2, 3, 4, 5};
    int size = 5;

    //reverseArray(arr, size);
    reverseArrayPtr(arr, size);

    for(int x : arr){
        cout << x << " ";
    }

    return 0;
}