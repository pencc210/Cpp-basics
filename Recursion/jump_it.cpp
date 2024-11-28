

#include <iostream> 
#include <vector> 
using namespace std;

void lowestCostVec(int arr[], int n, vector<int>& lowestPath){

    if(n == 2){ //Base case: Only 2 elements in the array, add the last to the path
        lowestPath.push_back(arr[1]);
    }if(n >= 3){ //3 or more elements, choose the lowest value one
        if(arr[1] < arr[2]){ 
            lowestPath.push_back(arr[1]);
            lowestCostVec(arr + 1, n - 1, lowestPath);
        }else{
            lowestPath.push_back(arr[2]);
            lowestCostVec(arr + 2, n - 2, lowestPath);
        }
    }
}

int lowestCost(vector<int>& lowestPath){
    int sum = 0;
    for(int x : lowestPath){
        sum += x;
    }
    return sum;
} 

int main(){

    int arr[] = {0, 3, 80, 6, 57, 10};
    int size = sizeof(arr)/sizeof(arr[0]);

    vector<int> lowestPathVec;
    lowestCostVec(arr, size, lowestPathVec);
    int cost = lowestCost(lowestPathVec);

    for(int x : lowestPathVec){
        cout<<x<<endl;
    }

    cout<<"Total cost: "<<cost<<endl;
    return 0; 
}