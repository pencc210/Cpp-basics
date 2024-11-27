/*
 * This program implements two recursion functions: one adds up the squares of all
 * elements in an array, the other one returns true if the elements in an array
 * are sorted in ascending order. 
 */

#include <iostream> 
using namespace std;

//Returns the sum of all elements squared
int sumOfSquares(int arr[], int arrSize){
    if(arrSize == 1){
        return arr[0] * arr[0];
    }else{
        int sqr = arr[arrSize - 1] * arr[arrSize - 1];
        return sqr + sumOfSquares(arr, arrSize - 1);
    }

}

bool isSorted(int arr[], int arrSize){
    if(arrSize == 1){
        return true;
    }else{
        if(arr[0] > arr[1]){ //Not ascending 
            return false;
        }else{
            return isSorted(arr + 1, arrSize - 1); //Moves on to second element of array as start and compares with third
        }
    }
}

int main(){

    //Function sumOfSquares
    int arr[] = {2, -1, 3, 10};
    int size = 4;
    cout<<sumOfSquares(arr, size)<<endl;

    //Function isSorted
    int arr2[] = {1, 2, 3, 10};
    cout<<isSorted(arr2,size)<<endl;


    return 0; 
}