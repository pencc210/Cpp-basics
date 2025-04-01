#include <iostream>
#include <vector>
#include <map>
using namespace std;

int how_many_ways(int m, const vector<int>& coins) {
    vector<int> dp(m + 1, 0);  // DP table initialized to 0
    dp[0] = 1;  // Base case

    for (int coin : coins) {
        for (int i = coin; i <= m; i++) {
            dp[i] += dp[i - coin];
        }
    }

    return dp[m];
}

int main(){

    return 0;
}