#include <iostream>
using namespace std;

pair <int, int> minMaxArray(int arr[], int size){
    int min = arr[0], max = arr[0];

    for (int i = 1; i < size; i++){
        if(arr[i] < min){
            min = arr[i];
        }if(arr[i] > max){
            max = arr[i];
        }
    }
    return {min, max};
}

int main(){

    int arr[5] = {7, 3, 9, 1, 6};
    int size = 5;

    pair<int, int> result = minMaxArray(arr, size);
    cout << "Min: " << result.first << ", Max: " << result.second << endl;

    return 0;
}