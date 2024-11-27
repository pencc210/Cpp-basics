/*
 * This program implements two recursive methods to output the smallest element in 
 * an array. Method 1 takes in the whole array and method 2 considers a subarray
 * with low and high index boudaries. 
 */

#include <iostream> 
using namespace std;

//Returns the minimum element in arr
int minInArray1(int arr[], int arrSize){
    if(arrSize == 1){ //Base case: array of one element
        return arr[0]; 
    }else{
        //Compare the first element with the minimum of the rest
        int restMin = minInArray1(arr + 1, arrSize - 1);
        if (arr[0] < restMin){
            return arr[0];
        }else{
            return restMin;
        }
    }
}

//Retuns the min element in the subarray from low (index) to high (index)
int minInArray2(int arr[], int low, int high){
    if(high == low){ //Base case: array of one element
        return arr[low]; 
    }else{
        //Compare the first element with the minimum of the rest
        int restMin = minInArray2(arr, low + 1, high);
        if (arr[low] < restMin){
            return arr[low];
        }else{
            return restMin;
        }
    }
}

int main(){

    //Function minInArray1
    int arr[] = {2, -1, 3, -10};
    int size = 4;
    cout<<minInArray2(arr, 0, 3)<<endl;

    return 0;
}