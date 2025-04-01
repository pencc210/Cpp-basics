/*
 * A robot can only move right or down starting at top left corner of grid and needs to get to bottom right. 
 * We want to know how many unique paths it can take. 
*/

#include <iostream>
#include <vector>
using namespace std;

int waysToGo(int m, int n){
    //dp[i][j] = number of ways to reach cell i, j
    if(m == 1 || n == 1){
        return 1;
    }
    //Initialize grid with 1's, if you have just one square there is only one path
    vector <vector<int>> dp(m, vector<int>(n,1)); // grid
    for(int i = 1; i < n; i++){
        for(int j = 1; j < m; j++){
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1]; //Save unique paths in each cell of grid. Its path 
            // from up cell + path from left cell
        }
    }

    //Max paths in bottom right grid box
    return dp[n - 1][m - 1];
}


int main(){

    cout << waysToGo(3, 7); 
    

    return 0;
}