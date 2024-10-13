/*
 * Various exercises realted to vector basics
*/


#include <iostream>
#include <vector>
using namespace std;

// Exercise 1: Create a vector of 5 integers. Assign values from 1 to 5 to it and print the values.

/* int main(){

    vector<int>vec(5);

    for (int i = 0; i < 5; i++){
        vec[i] = i + 1;
        cout<<vec[i]<<endl;
    }


} */

//Exercise 2: Create a 3x3 2D vector (a matrix). 
//Assign the values 1 to 9 in the matrix, and print each value in matrix form.

/* int main(){

    vector<vector<int> >mat(3);

    int num = 1; 

    for(int i = 0; i < 3; i ++){ //Loop for columns
        mat[i].resize(3);

        for(int j = 0; j < 3; j ++){ //loop for rows
            mat[i][j] = num;
            cout<<mat[i][j]<<" ";
            num ++;
        }
        cout<<'\n';
    }

} */

//Exercise 3: Modify your previous code to calculate the sum of all the elements in the 3x3 matrix.

int main(){

    vector<vector<int> >mat(3);

    int num = 1; 

    //Creating matrix
    for(int i = 0; i < 3; i ++){            //Loop for rows
        mat[i].resize(3);

        for(int j = 0; j < 3; j ++){        //Loop for cols
            mat[i][j] = num;
            num ++;
        }
    }

    //Adding up elements

    int sum = 0; 

    for(int i = 0; i < 3; i ++){            
        for(int j = 0; j < 3; j ++){        
            sum += mat[i][j];
        }
    }
    cout<<"Sum: "<<sum<<endl; 


}