#include <iostream>
#include <vector>
using namespace std;

int* getPosNums1(int* arr, int arrSize, int& outPosArrSize){

    //Calculate size of new array
    outPosArrSize = 0;
    for(int i = 0; i < arrSize; i++){
        if (arr[i] > 0){
            outPosArrSize ++;
        }
    }

    //Create new dynamic array with right size
    int *posArray = new int[outPosArrSize]; 
    //Fill in array
    int j = 0;
    for(int i = 0; i < arrSize; i++){
        if (arr[i] > 0){
            posArray[j] = arr[i];
            j++;
        }
    }
    return posArray;
}

int* getPosNums2(int* arr, int arrSize, int* outPosArrSizePtr){
    //Calculate size of new array
    *outPosArrSizePtr = 0;
    for(int i = 0; i < arrSize; i++){
        if (arr[i] > 0){
            (*outPosArrSizePtr) ++;
        }
    }

    //Create new dynamic array with right size
    int *posArray = new int[*outPosArrSizePtr]; 
    //Fill in array
    int j = 0;
    for(int i = 0; i < arrSize; i++){
        if (arr[i] > 0){
            posArray[j] = arr[i];
            j++;
        }
    }
    return posArray;
}

void getPosNums3(int* arr, int arrSize, int*& outPosArr, int& outPosArrSize){ //int*& is the address of the pointer 

   //Calculate size of new array
    outPosArrSize = 0;
    for(int i = 0; i < arrSize; i++){
        if (arr[i] > 0){
            outPosArrSize ++;
        }
    }

    outPosArr = new int[outPosArrSize];

    //Fill in array
    int j = 0;
    for(int i = 0; i < arrSize; i++){
        if (arr[i] > 0){
            outPosArr[j] = arr[i];
            j++;
        }
    }
}

void getPosNums4(int* arr, int arrSize, int** outPosArrPtr, int* outPosArrSizePtr) {
    // Calculate size of new array
    *outPosArrSizePtr = 0;
    for (int i = 0; i < arrSize; i++) {
        if (arr[i] > 0) {
            (*outPosArrSizePtr)++;
        }
    }

    // Allocate the array in the heap
    int* posArray = new int[*outPosArrSizePtr];
    int j = 0;
    for (int i = 0; i < arrSize; i++) {
        if (arr[i] > 0) {
            posArray[j++] = arr[i];
        }
    }

    // Assign the array to the pointer in main
    *outPosArrPtr = posArray;
}

void printArray(int arr[], int size){
    for(int i = 0; i < size; i++){
        cout<<arr[i]<<'\t';
    }
    cout<<endl;
}

int main(){

    int size = 6;
    int arr[6] = {3, -1, -3, 0, 6, 4};

    cout<<"Original array: "<<endl;
    for(int i = 0; i < size; i++){
        cout<<arr[i]<<'\t';
    }
    cout<<endl;

    int positiveSize = 0; 
    int *ptrPositiveSize = &positiveSize; //Pointer to the size of positive array

    //Method 1
    cout<<"Method 1: "<<endl;
    int *ptrPosArr = getPosNums1(arr, size, positiveSize);
    printArray(ptrPosArr, positiveSize);

    //Method 2
    cout<<"Method 2: "<<endl;
    int *ptr2PosArr = getPosNums2(arr, size, ptrPositiveSize);
    printArray(ptr2PosArr, positiveSize);
 
    //Method 3
    int *ptr3PosArr = nullptr; //Ptr to hold address of new array

    cout<<"Method 3: "<<endl;
    getPosNums3(arr, size, ptr3PosArr, positiveSize);
    printArray(ptr3PosArr, positiveSize);
    
    //Method 4
    int* ptr4PosArray = nullptr;
    cout<<"Method 4: "<<endl;
    getPosNums4(arr, size, &ptr4PosArray, ptrPositiveSize);
    printArray(ptr4PosArray, positiveSize);


    //Delete arr in heap
    delete[] ptrPosArr; 
    delete[] ptr2PosArr;
    delete[] ptr3PosArr; 
    delete[] ptr4PosArray;
    cout<<endl;
    return 0;
}