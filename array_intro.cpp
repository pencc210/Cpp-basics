/*Create an array of 5 integers with the values {12, 7, 25, 3, 18}.
 * Print all the elements of the array using a for loop.
 * Calculate and print the sum of all the elements in the array.
 * Find and print the largest element in the array.
 * Use a pointer to traverse the array and print the elements using pointer arithmetic.
*/


#include <iostream>
using namespace std;

// Function to print array using a pointer 

void printArray(int *ptr, int size){
    for (int i = 0; i < size; i ++){
        cout<<ptr[i]<<endl;
    }
}


int main(){
    int A[] = {12, 7, 25, 3, 18};
    int sum = 0;

    //Loop to rint all elements and add them 
    for (int i = 0; i < 5; i ++){
        cout<<A[i]<<endl;
        sum += A[i];
    }
    cout<<"Sum: "<<sum<<endl;

    //Finding largest element
    int sizeA = sizeof(A)/sizeof(A[0]);             // Size
    sort(A, A + sizeA);                             // Assending sort
    cout<<"Largest element: "<<A[sizeA - 1]<<endl;   // Prints last element of array 

    //Pointer
    printArray(A , sizeA);

}


