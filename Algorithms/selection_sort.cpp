
#include <iostream>
using namespace std;

int findMinInd(int arr[], int low, int high){

    //Set first element as min to compare with others
    int minNum = arr[low];
    int minInd = low;
    for(int i = low + 1; i <= high; i++){
        if(minNum > arr[i]){
            minNum = arr[i];
            minInd = i; 
        }
    }
    return minInd;
}

void SelectionSort(int arr[], int size){
    int i, minInd;

    for (i = 0; i < size; i++){ 
        minInd = findMinInd(arr, i, size - 1);
        swap(arr[i], arr[minInd]);
    }
}

void printArray(int arr[], int size){
    for (int i = 0; i < size; i++){ 
        cout<<arr[i]<<", ";
    }
}

int main(){

    int arr[] = {1,2,5,3,9,4,7,2};
    int size = 8;

    SelectionSort(arr, size);
    printArray(arr, size);

    return 0;
}