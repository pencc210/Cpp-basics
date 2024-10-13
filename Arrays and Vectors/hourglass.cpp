/*
* Various execises realted to the hourglass shape on 2D vectors
*/

//Create a 3x3 matrix and print the elements that form an hourglass shape.

#include <iostream>
#include <vector>
using namespace std;



vector<vector<int> > makeSquareMatrix(int n){     //Makes an nxn matrix of ascending numbers

    int num = 1;

    vector<vector<int> >mat(n);

    for(int i = 0; i < n; i ++){            //Loop for rows
        mat[i].resize(n);

        for(int j = 0; j < n; j ++){        //Loop for cols
            mat[i][j] = num;
            num ++;
        }
    }

    return mat;
}

pair<int, int> sizeMatrix(vector<vector<int> > &mat){
    int rows = mat.size(); 
    int cols = mat[0].size();

    return make_pair(rows, cols);           //retuns both values

}


void printMatrix(vector<vector<int> > &mat, int &rows, int &cols){    //Print out matrix
    for(int i = 0; i < rows; i ++){                //Loop for rows
        for(int j = 0; j < cols; j ++){            //Loop for cols
            cout<<mat[i][j]<<" ";
        }
        cout<<'\n';
    }
}

void printHourGlass3x3(vector<vector<int> > &mat){ //Print hourglass for a 3x3 matrix
    
    cout<<mat[0][0]<<" "<<mat[0][1]<<" "<<mat[0][2]<<endl;
    cout<<"  "<<mat[1][1]<<endl;
    cout<<mat[2][0]<<" "<<mat[2][1]<<" "<<mat[2][2]<<endl;


}

void printHourGlass(vector<vector<int> > &mat,int &rows, int &cols){ //Print hourglass for a nxn matrix

    
    for(int i = 0; i < (cols - 2); i ++){
        for(int j = 0; j < (rows - 2); j ++){ 
            cout<<mat[i][j]<<" "<<mat[i][j + 1]<<" "<<mat[i][j + 2]<<endl;
            cout<<"  "<<mat[i + 1][j + 1]<<endl;
            cout<<mat[i + 2][j]<<" "<<mat[i + 2][j + 1]<<" "<<mat[i + 2][j + 2]<<endl;

    }
    }


}

vector<int> sumHourGlass(vector<vector<int> > &mat,int &rows, int &cols){ // Calculates the sum of each hourglass

    int sum = 0; 

    vector<int> sumPerGlass; // vector to store all individual hour glass sums 




    for(int i = 0; i < (cols - 2); i ++){
        for(int j = 0; j < (rows - 2); j ++){ 
            sum += mat[i][j]+ mat[i][j + 1] + mat[i][j + 2] + mat[i + 1][j + 1] + mat[i + 2][j] + mat[i + 2][j + 1] + mat[i + 2][j + 2];

            sumPerGlass.push_back(sum);
            sum = 0;
            }


    }

    return sumPerGlass; 


}



int main(){


    vector<vector<int> > mat = makeSquareMatrix(6);      // build nxn matrix


    pair<int, int> dimensions = sizeMatrix(mat);   // get its size for the print fx 
    int rows = dimensions.first;
    int cols = dimensions.second;


    printMatrix(mat, rows, cols);                  // print matrix

    //printHourGlass(mat, rows, cols);   

    vector<int> sumPerGlass = sumHourGlass(mat, rows, cols);

    int totalSum = 0; 
    int maxSum = 0; 

    for(int i = 0; i < sumPerGlass.size(); i ++){
        cout<<sumPerGlass[i]<<endl;
        totalSum += sumPerGlass[i];

        if (maxSum < sumPerGlass[i]){
            maxSum = sumPerGlass[i];
        }
    }

    cout<<"Total sum: "<<totalSum<<endl;
    cout<<"Max sum: "<<maxSum<<endl;


    return 0;
}