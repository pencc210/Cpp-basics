#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
using namespace std;

//Gets all combinations of k size in arr and returns them in a vector
void combine(vector<int>& arr, int k, int startIndex, vector<int>& current, vector<vector<int>>& result){
    if (current.size() == k){
        result.push_back(current);  
        return;
    }else{
        for(int i = startIndex; i < arr.size(); i++){
            current.push_back(arr[i]);
            combine(arr, k, i + 1, current, result);
            current.pop_back();
            
        }
    }
}

vector<int> medians(vector<int> values, int k){

    //Get all combinations of length k
    vector<vector<int>> combinations;
    vector<int> current;

    combine(values, k, 0, current, combinations);

    int min = combinations[0][0];
    int max = combinations[0][0];
    int median;

    for(const auto& comb : combinations){

        vector<int> sortedComb = comb;
        sort(sortedComb.begin(), sortedComb.end()); //Sort each combination

        if(k % 2 != 0){ //Odd size so we take meadian a middle element
            median = sortedComb[k / 2]; 
        }else{ //Even we take lower middle element
            median = sortedComb[k / 2 - 1];
        }

        if(median < min){
            min = median;
        }if(median > max){
            max = median;
        }
    }


    return {min, max};

}

int main(){

    vector<int> arr = {1, 2, 3};
    int k = 2;

    vector<int>medianVec;

    medianVec = medians(arr, k);

    cout<<"Min median: " << medianVec[0] << ", max median: " << medianVec[1] << endl;

    return 0;
}