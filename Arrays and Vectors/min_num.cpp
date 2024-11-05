
#include <iostream>
#include <sstream>
using namespace std; 

//Returns smallest int in array
int minInArray(int arr[], int arrSize); 

//Returns vector of indexes in arr where num is
vector <int> indexOfNum(int arr[], int arrSize, int num); 





int main(){

int arrSize = 20; 
int nums[arrSize];
string numsInput;

cout<<"Please enter 20 integers separated by a space: "<<endl;
getline(cin,numsInput);                 //Gets full input line
stringstream ss(numsInput);             // Turns it into a stream

int num;
int i = 0;
while (ss >> num && i < arrSize){       //Gets each element from stream and inserts in arr
    nums[i]=num;
    i ++;
}

int minVal = minInArray(nums, arrSize); //Calculates min value
vector <int> indices = indexOfNum(nums, arrSize, minVal); //Vector for indexes where minVal is

cout<<"The minimum value is "<<minVal<<", and is located in the following indices ";
for(int x : indices){
    cout<<x<<' ';
}
cout<<endl;

delete[] nums;
return 0; 
}


int minInArray(int arr[], int arrSize){ 
    sort(arr, arr + arrSize);
    return arr[0];
}


vector <int> indexOfNum(int arr[], int arrSize, int num){
    vector <int> indexOfNum;

    for(int i = 0; i < arrSize; i++){
        if(arr[i] == num){
            indexOfNum.push_back(i);
        }
    }

    return indexOfNum;
}