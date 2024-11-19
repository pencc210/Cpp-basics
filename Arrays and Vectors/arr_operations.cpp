#include <iostream>
#include <sstream>
using namespace std; 

// Reverses the elements in arr
void reverseArray(int arr[], int arrSize);

//Removes odd numbers from the array and updates arrSize variable
void removeOdd(int arr[], int &arrSize);





int main() {
    int size = 4;
    int* arr = new int[size]{1, 2, 3, 4}; // create an array in the heap

    reverseArray(arr, size);
    removeOdd(arr, size);

    for (int i = 0; i < size; i++) {
        cout << arr[i] << endl;
    }

    // Free allocated memory for arr
    delete[] arr;
}

void reverseArray(int arr[], int arrSize) {
    int i = 0;
    int j = arrSize - 1;
    int temp;

    while (i < j) {
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        i++;
        j--;
    }
}

void removeOdd(int arr[], int &arrSize) {
    int newIndex = 0; // This will hold the position for even elements

    for (int i = 0; i < arrSize; i++) {
        if (arr[i] % 2 == 0) { // Check if the element is even
            arr[newIndex] = arr[i]; // Move even element to the current newIndex
            newIndex++; // Increment newIndex to the next position
        }
    }
    
    // Update arrSize to the new logical size (count of even elements)
    arrSize = newIndex;
}
