#include <iostream>
#include <vector>
using namespace std;

bool isSymmetricMatrix(vector<vector<int>>& mat){
    int rows = mat.size();
    int cols = mat[0].size();

    for(int i = 0; i < rows; i++){
        for(int j = i + 1; j < cols; j++){ //Check upper triangle only
            if(mat[i][j] != mat[j][i]){
                return false;
            }
        }
    }
    return true;
}

int main(){


    vector<vector<int>> mat = {{1, 2, 3},{2, 4, 5},{3, 5, 6}};

    cout<< (isSymmetricMatrix(mat) ? "Symmtrical" : "Not symmetrical") <<endl;

    return 0;
}