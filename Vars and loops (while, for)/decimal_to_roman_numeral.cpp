/*
 * This program takes in a decimal number and converts it into a simplified roman numeral.
 * Simplified roman numerals have the following values: 
 * M = 1000, D = 500, C = 100, L = 50, X = 10, V = 5, I = 1
 * M can appear any number of times, D, L and V can only appear 1 time and C, X and I can only appear 4
 * times. The letters should follow a monotonically non-increasing order.  
*/


#include <iostream>
using namespace std;

int main(){

    int decimal, num;
    int i;
    string numeral;

    cout<<"Enter decimal number:"<<endl;
    cin>>decimal;

    num = decimal; 

    // M
    while(decimal >= 1000){             //Multiple iterations for an indefinate number of M's
        numeral += "M";
        decimal -= 1000;
    }

    //D
    if(decimal >= 500){                 //Single run ensures no more than one D
        numeral += "D";
        decimal -= 500;
    }

    //C
    while(decimal >= 100 && i++ < 4){   //Loop ensures no more than 4 C's in numeral
        numeral += "C";
        decimal -= 100;
        i += 1;
    }

    //L
    if(decimal >= 50){                  //Single run
        numeral += "L";
        decimal -= 50;
    }

    //X
    while(decimal >= 10 && i++ < 4){   //Loop for no more than 4 X's in numeral
        numeral += "X";
        decimal -= 10;
        i += 1;
    }

    //V
    if(decimal >= 5){                   //Single run
        numeral += "V";
        decimal -= 5;
    }

    //I
    while(decimal >= 1 && i++ < 4){    //Loop for no more than 4 I's in numeral
        numeral += "I";
        decimal -= 1;
        i += 1;
    }

    cout<<num<<" is "<<numeral<<endl;
}