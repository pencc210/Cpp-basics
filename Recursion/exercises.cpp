
#include <iostream> 
using namespace std;

//Returns true if all elements of the array are even 
bool areAllEven(int arr[], int n){
    if(n == 1){ //Base case: an array of one element
        return (arr[0] % 2 == 0); //True if even
    }else{
        bool res = areAllEven(arr, n - 1);
        if(res == 1){ //If all element in a smaller array n - 1 are even
            return(arr[0] % 2 == 0); //Check last element
        }else{
            return false;
        }
    }
}

//Prints numbers in ascending order
void printAsc(int start, int end){
    if(start == end){ //Base case: a group of just one number
        cout<<start<<endl;
    }else{
        printAsc(start, end - 1); //In a group of 2 print first one
        cout<<end<<endl;          //and last one
    }
}

//Prints numbers in ascending and descending order
void printAscAndDesc(int start, int end){
    if(start == end){ //Base case: just one number
        cout<<start<<endl; 
    }else{ //Recursion with 2 nums 
        cout<<start<<endl; //Prints first
        printAscAndDesc(start + 1, end); //Prints second
        cout<<start<<endl; //Prints first again 
    }
}

int main(){

    int arr[] = {0, 2, 4, 6};
    //cout<<areAllEven(arr, 4)<<endl;

    //printAsc(1,4);

    printAscAndDesc(1,4);

    return 0;
}