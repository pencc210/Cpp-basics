
/* 
 * 4 exercises on dynamic allocation
*/
#include <iostream>
using namespace std;

int main(){

/*     // 1 Simple: integer
    int* ptr = new int; //Dynamic allocation
    *ptr = 4;
    cout << *ptr << endl;
    delete ptr;

    // 2 Simple: array 
    int n = 5;
    int* arr = new int[n];
    for (int i = 0; i < n; i++){ //Set values
        arr[i] = i * 2;
    }
    for (int i = 0; i < n; i++){ //print values
        cout << arr[i] << ", ";
    }
    delete[] arr;

    //3 Matrix Allocation (m x n)
    //Memory allocation
    int m = 4, n = 5;
    int** mat = new int*[m]; //Cols
    for(int i = 0; i < m; i++){
        mat[i] = new int[n]; //Rows 
    }
    //Filling it up
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            mat[i][j] = i + j; 
        }
    }
    //Printing out
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
    //Deallocate
    for (int i = 0; i < m; ++i) {
        delete[] mat[i]; // Free each row
    }
    delete[] mat; */

    // 4 Array resizing

    int size = 5;
    int* arr = new int[size]; //Create arr size 5
    for(int i = 0; i < size; i++){ //Fill in array
        arr[i] = i + 1;
    }
    for(int i = 0; i < size; i++){ //Print out arr
        cout << arr[i] << ", ";
    }
    cout << endl;

    int* arr2 = new int[2*size]; //Create arr size 10

    // Use std::copy to copy the old array into the new one
    // copy(FirstIterator, LastIterator, DestinationIterator);
    copy(arr, arr + size, arr2);

    delete[] arr; //Delete old array
    for(int i = size; i < (2 * size); i++){ //Fill in remaining slots 
        arr2[i] = i + 1;
    }
    for(int i = 0; i < (2 * size); i++){ //Print out resized arr
        cout << arr2[i] << ", ";
    }
    delete[] arr2;

    return 0;
}