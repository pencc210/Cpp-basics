/*
 * This program implements various simple recursive functions: printing numbers 
 * inside an interval in ascending order, adding them, calculating the factorial 
 * of a number and calulating the sum of the digits of a number.
*/

#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;

//Print numbers from start to end in ascending order
void printAsc(int start, int end){
    if(start == end){
        cout<<start<<endl;
    }
    else{
        printAsc(start, end-1);
        cout<<end<<endl;
    }
}

//Return the sum from start to end
int recursiveSum(int start, int end){
    if(start == end){
        return start; //Base case 
    }else if(start < end){
        return start + recursiveSum(start + 1, end); //Ascending
    }else{
        return start + recursiveSum(start - 1, end); //Descending
    }

}

//Returns the factorial of num
int recFactorial(int num){
    if(num == 0){
        return 1; //Base case 
    }
    else{
        return num * recFactorial(num - 1); //Case for two numbers 
    }

}

//Returns the sum of the digits of num
int recDigitSum(int num){
    if(num/10 == 0){ //Base case: just one digit
        return num;
    }else{
        return num%10 + recDigitSum(num/10);
    }
}

int main(){
    cout<<recursiveSum(3, 6)<<endl;
    cout<<recFactorial(5)<<endl;
    cout<<recDigitSum(123)<<endl;
}