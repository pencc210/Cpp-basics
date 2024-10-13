/*
 *Create a 3x3 matrix (2D array) with the following values:
1  2  3
4  5  6
7  8  9
* Print the matrix in a nicely formatted way (each row on a new line).
* Calculate and print the sum of all the elements in the matrix.
* Calculate and print the sum of the elements in each row of the matrix.
* Find and print the largest element in the matrix.
*/

#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int main(){

    int M [3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
    };

    int rows = sizeof(M)/sizeof(M[0]);
    int cols = sizeof(M[0])/sizeof(M[0][0]);

    int sum = 0;
    int sumRows = 0;

    int largest = 0;                //var for largest element

    int sumArray [rows];            //Array to store the sum of each row 

    for (int i = 0; i < rows; i ++){ //iteretes through rows

        for(int j = 0; j < cols; j++){ //iterates through columns
            int element = M[i][j];
            cout<<element<<" ";        //space after elements in same row
            sum += element;
            sumRows += element;
            if(largest<element){
                largest = element;
            }
        }
        cout<<'\n';                    //new line when changing row

        sumArray[i] = sumRows;
        sumRows = 0;                   // reinitalize sum rows to start form 0 when adding a new row 

    }
    cout<<"Total sum: "<<sum<<endl;

    //Print out sum of rows (elements in sumArray)
    int sizeSumArray = sizeof(sumArray) / sizeof(sumArray[0]);
    
    for(int i = 0; i < sizeSumArray; i ++){
        cout<<"Sum of row "<<i<<" is: "<<sumArray[i]<<endl;
    }

    //Print largest number
    cout<<"The largest number is: "<<largest<<endl; 


}