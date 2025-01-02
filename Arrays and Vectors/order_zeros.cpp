#include <iostream>
using namespace std;

//Moves all the 0's in a n array to the end conserving the
//relative order of all elements
void sortZeros(int arr[], int size){
    int index = 0; // Index to place non-zero elements
    
    for (int i = 0; i < size; i++) {
        if (arr[i] != 0) {
            swap(arr[i], arr[index]);
            index++;
        }
    }
}

int main(){

    int size = 5; 
    int arr[] = {0, 2, 0, 1, 0};

    sortZeros(arr, size);

    for(int i = 0; i < size; i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}