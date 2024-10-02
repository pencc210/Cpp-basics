/* 
 * This program prints an hourglass of made up of asterisks. The height of each half is n lines.
 */

#include <iostream>
using namespace std;


int main(){

    int n;
    int spaces, stars;
    int counter, space_counter, star_counter;

    cout<<"Please input a possitive integer: ";
    cin>>n;

    stars = (2 * n) - 1;
    spaces = 0;

    counter = 0;

    while (counter<n){                     // Top half

        for(space_counter = 0; space_counter<spaces; space_counter += 1)
            cout<<" ";

        for(star_counter = 0; star_counter<stars; star_counter += 1)
            cout<<"*";
        cout<<endl;

        stars -= 2;
        spaces += 1;
        counter += 1;

    }

    while (counter>0){                     // Bottom half
        
        stars += 2;
        spaces -= 1;
        counter -= 1;   

        for(space_counter = 0; space_counter<spaces; space_counter += 1)
            cout<<" ";

        for(star_counter = 0; star_counter<stars; star_counter += 1)
            cout<<"*";
        cout<<endl;

    }
}