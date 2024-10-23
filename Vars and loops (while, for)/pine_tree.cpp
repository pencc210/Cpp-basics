/*
 * This program prints a number of stacked triangles of symbols defined by the user
 * resembling a pine tree shape. 
*/

#include <iostream>
using namespace std;

void printShiftedTriangle(int n, int m, char symbol); //Prints n line triangle of symbol separated m spaces from the left
void printPineTree(int n, char symbol); //Prints n triangles of symbol in encreasing sizes following the shape of a pine tree


int main(){

    printShiftedTriangle(3, 4, '+');
    printPineTree(3, '#');

    return 0;
}

void printShiftedTriangle(int n, int m, char symbol){

    int spaces = m + n - 1; 
    int numSymbols = 1;

    for (int i = 1; i <= n; i++){ //for lines

        for(int j = 1; j <= spaces; j++){ // spaces
            cout<<' ';
        }
        for(int k = 1; k <= numSymbols; k++){ // symbols
            cout<<symbol;
        }
        cout<<'\n';

        spaces --;
        numSymbols += 2;
    }
}

void printPineTree(int n, char symbol){
    int spaces = n - 1;
    int lines = 2;

    for(int i = 1; i <= n; i++){
        printShiftedTriangle(lines, spaces, symbol);
        spaces --;
        lines ++;
    }
}
