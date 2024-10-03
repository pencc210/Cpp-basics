
/* 
 * This program receives an arithmetic operation and calculates
 * it using switch cases to identify the operation.
 * It handles addition, subtraction, multiplication and division.
 */

#include <iostream>
using namespace std;

int main(){

    float num1, num2, result;
    char op;                        //op = numeric operator
    bool valid;

    cout<<"Please enter a numerical operation: ";
    cin>>num1>>op>>num2; 

    valid = true;

    //Switch case to handle different arithmetic operations
    switch(op){

        case '+':                   //Adition
            result = num1+num2;
        break;

        case '-':                   //Substraction
            result = num1-num2;
        break;

        case '*':                   //Multiplication
            result = num1*num2;
        break;

        case '/':                   //Division
            if (num2!=0){           //Check for division by 0
                result = num1/num2;
            }
            else{                   //valid is false if devision by 0
                valid = false;     
            }
            
        break;

        default:
            valid = false;
        break;
    }

    // Display result if operation is valid 
    if (valid==true){
        cout<<num1<<" "<<op<<" "<<num2<<" = "<<result<<endl;
    }
    else{
        cout<<"Invalid operation"<<endl;
    }
    

    return 0;
}
