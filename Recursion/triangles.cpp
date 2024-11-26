/*
 * This does three recursive implementations: prints a triangle,
 * a triangle and its vertical reflection, and prints a ruler.
*/

#include <iostream> 
using namespace std;

//Prints an n line triangle with n asterix per line
void printTriangle(int n){
    if(n == 1){ //Base case: one line
        cout<<"*"<<endl;
    }else{  //Hypothetical case: 2 lines
        printTriangle(n - 1); //Prints first line
        for(int i = 1; i <= n; i++){ //Prints the second line
            cout<<"*";
        }
        cout<<endl;
    }
}

//Prints an n line triangle with n asterix per line firts base
//to tip and then tip to base
void printOppositeTriangle(int n){
    if(n == 1){ 
        cout<<"*"<<endl;
        cout<<"*"<<endl;
    }else{
        for(int i = 1; i <= n; i++){ //Prints two asterix
            cout<<"*";
        }
        cout<<endl;
        printOppositeTriangle(n - 1); //Prints one asterix twice
        for(int i = 1; i <= n; i++){ //Prints two asterix
            cout<<"*";
        }
        cout<<endl;
    }
}

void printRuler(int n){
    if(n == 1){
        cout<<"-"<<endl;
    }else{
        printRuler(n - 1); //Print one
        for(int i = 1; i <= n; i++){ //Print two
            cout<<"-";
        }
        cout<<endl;
        printRuler(n - 1); //Print one
    }
}


int main(){

    //printTriangle(4);

    //printOppositeTriangle(4);

    printRuler(4);

    return 0;
}
