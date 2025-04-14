
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
using namespace std;

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

int main(){

    vector<int> arr = {1, 2, 3};
    int k = 2;

    vector<vector<int>> result;
    vector<int> current;

    combine(arr, k, 0, current, result);

    for (auto& comb : result) {
        cout << "{ ";
        for (int x : comb) cout << x << " ";
        cout << "}" << endl;
    }

    return 0;
}


