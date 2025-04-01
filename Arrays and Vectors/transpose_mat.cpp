#include <iostream>
#include <vector>
using namespace std;

void printMatix(vector<vector<int>>& mat){
    int rows = mat.size();
    int cols = mat[0].size();
    for(int i = 0; i < rows; i++){
            for( int j = 0; j < cols; j++){
               cout << mat[i][j] << " ";
            }
            cout << endl;
        }
}

void printMatrixHeap(int** mat, int rows, int cols) {
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

void transposeMatrixSq(vector<vector<int>>& mat){ //Square matrix
    int rows = mat.size();
    int cols = mat[0].size();

    for(int i = 0; i < rows; i++){
        for( int j = 0; j < cols; j++){
            if(j > i){ //Upper triangle
                int temp = mat[i][j];
                mat[i][j] = mat[j][i];
                mat[j][i] = temp;
            }
        }
    }
  
}

//Returns nxm matrix for non square ones
vector<vector<int>> transposeMatrixNonSq(vector<vector<int>>& mat){
    int rows = mat[0].size(); //our cols are the new rows.
    int cols = mat.size();

    vector<vector<int>> matTrans(rows, vector<int>(cols));

    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            matTrans[i][j] = mat[j][i];
        }
    }

    return matTrans;
}



int main(){

    vector <vector <int>> matSq = {{1, 2, 3},{4, 5, 6},{7, 8, 9}};

    vector <vector <int>> matNotSq = {{1, 2},{3, 4},{5, 6}};


    transposeMatrixSq(matSq);

    vector<vector<int>> matTrans = transposeMatrixNonSq(matNotSq);
    printMatix(matTrans);

    


    return 0;
}