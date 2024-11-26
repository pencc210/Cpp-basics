/*
 * This program takes an array of size n form the user and outputs 
 * the missing numbers in the range form 0 to n + 1.
 */

#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

//Function to create a missing numbers array and return it as an int pointer
int* findMissing(int arr[], int n, int& resArrSize){

    vector<int> missingNumVec;
    //Try to find number in range in the array
    int range = n + 1;
    for(int i = 0; i <= range; i++){
        auto it = find(arr, arr + n, i);
        if(it == arr + n){ //Number not found in array
            missingNumVec.push_back(i);
        }

    }

    resArrSize = missingNumVec.size();

    int* resArrPtr = new int[resArrSize]; //Create dynamic array for missing numbers
    for(int i = 0; i < resArrSize; i++){ //Copy values form vector to array
        resArrPtr[i] = missingNumVec[i];
    }

    return resArrPtr;
} 

//Function to print an array passed as a pointer
void printArray(int* ptr, int size){
    
    for(int i = 0; i < size; i++){
        cout<<ptr[i]<<" ";
    }
}

int main(){

    int n;
    cout<<"Please enter the array size: "<<endl;
    cin>>n;

    int arr[n];
    cout<<"Please enter the numbers in the array: "<<endl;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    int resArrSize = 0; //Size for missing numbers array

    int* resArrPtr = findMissing(arr, n, resArrSize); //Generate missing numbers array
    //Print original array
    cout<<"For the array: "<<endl;
    printArray(arr,n);
    cout<<endl;
    //Print missing numbers array
    cout<<"The missing numbers are: "<<endl;
    printArray(resArrPtr, resArrSize);
    cout<<endl;

    delete[] resArrPtr;
    return 0;
}