/*
 * Program: Odds Keep, Evens Flip
 * Description: Reorders an integer array by keeping odd numbers in original order
 *              and reversing the order of even numbers.
 *
 * Functions:
 *   - oddsKeepEvensFlip: Reorders the array in-place.
 *   - printArray: Prints the array elements.
 *
 * Usage: User enters array size and elements, and the program displays the
 *        original and reordered arrays.
 */

#include <iostream>
#include <vector>
#include <string>
using namespace std;

//Prints the array
void printArray(int arr[], int size);
//Rearanges arr to have odd numbers first and then even numbers in reverse order
void oddsKeepEvensFlip(int arr[], int arrSize);

int main(){

    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    int arr[size]; 

    cout << "Enter " << size << " elements of the array: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    cout<<"Original array: "<<endl;
    printArray(arr, size);
    oddsKeepEvensFlip(arr, size);
    cout<<"Reordered array: "<<endl;
    printArray(arr, size);

    return 0;
}

void oddsKeepEvensFlip(int arr[], int arrSize){
   
    //Holders for odd and ever subsets of arr
    vector <int> odds;
    vector <int> evens;
    for (int i = 0; i < arrSize; i ++){
        if (arr[i]%2 == 0){
            evens.push_back(arr[i]);
        }else{
            odds.push_back(arr[i]);
        }

    }

    int oddsSize = odds.size();

    for (int i = 0; i < oddsSize; i ++){ //Inserts odds to original array
        arr[i]=odds[i];
    }
    int j = 0;
    for (int i = arrSize - 1; i >= oddsSize; i --){ //Inserts evens in reverse order
        arr[i]=evens[j];
        j++;
    }
}

void printArray(int arr[], int size){
    for(int i = 0; i < size; i++){
        cout<<arr[i]<<'\t';
    }
    cout<<endl;
}