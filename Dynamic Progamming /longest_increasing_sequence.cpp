#include <iostream>
#include <vector>
using namespace std;

int longestIncreasingSequence(vector <int> nums){
    // dp[i] : longest increasing sequence ending at number i
    int size = nums.size();

    vector <int> dp(size, 1); //Initialized with 1 on each index beacause each number is a sequence of 1
    int maxLength = 1;

    for(int i = 0; i < nums.size(); i++){ 
        for(int j = 0; j < i; j++){
            if(nums[j] < nums[i]){
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        maxLength = max(dp[i], maxLength);
    }

    //Return max sequence length
    return maxLength;
}

int main(){
    vector <int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    cout << longestIncreasingSequence(nums) << endl;

    return 0;
}