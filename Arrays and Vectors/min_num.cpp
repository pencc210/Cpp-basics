/*
 * This program takes in a list of numbers for the user, orginzes them into an 
 * array and outputs the smallest number and the indices in which it appears. 
 */

#include <iostream>
#include <sstream>
using namespace std; 

//Returns an array of the input string
void inputToArray(string input, int arr[], int arrSize);

//Returns smallest int in array
int minInArray(int arr[], int arrSize); 

//Returns vector of indexes in arr where num appears
vector <int> indexOfNum(int arr[], int arrSize, int num); 


int main(){

int arrSize = 20; 
int nums[arrSize];
string numsInput;

cout<<"Please enter 20 integers separated by a space: "<<endl;
getline(cin,numsInput);                 //Gets full input line

inputToArray(numsInput, nums, arrSize); // Transfer user input to nums array
int minVal = minInArray(nums, arrSize); //Calculates min value
vector <int> indices = indexOfNum(nums, arrSize, minVal); //Vector for indexes where minVal is

cout<<"The minimum value is "<<minVal<<", and is located in the following indices ";
for(int x : indices){
    cout<<x<<' ';
}
cout<<endl;
return 0; 
}

void inputToArray(string input, int arr[], int arrSize){
    stringstream ss(input);

    int num;
    int i = 0;
    while (ss >> num && i < arrSize){       //Gets each element from stream and inserts in arr
       arr[i] =num;
        i ++;
    }
}

int minInArray(int arr[], int arrSize){
    int minNum = arr[0];
    for (int i = 1; i < arrSize; i++){
        if(minNum > arr[i]){
            minNum = arr[i];
        }
    }
    return minNum;
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