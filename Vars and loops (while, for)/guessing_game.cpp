/*
 * This program randomly selects a number between 1 and 100 (inclusive) and asks the user to guess it.
 * The user has up to 5 attempts to guess the number correctly. After each guess, the program provides feedback:
 *   - If the guess is too low, it informs the user that the number is higher.
 *   - If the guess is too high, it informs the user that the number is lower.
 *   - If the guess is correct, it congratulates the user and displays the number of attempts used.
 * The program also adjusts the guessing range dynamically based on the user's input.
 * If the user fails to guess the number within 5 tries, the program reveals the correct number.
 * */

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int randomNumberGenerator();
bool guessCompare(int guess, int randomNumber, int guessesLeft, int& minRange, int &maxRange);
void lastGuess(int guess, int randomNumber, int guessesLeft);

int main(){

    int guessesLeft = 5;
    int guess;
    int minRange = 1;
    int maxRange = 100;
    srand(time(0));
    int randomNumber = randomNumberGenerator();

    //cout<<randomNumber<<endl;

    cout<<"I've thought of a number between 1 and 100! Try to guess it."<<endl;

    while (guessesLeft > 0){                                                     // Loop for each guess
        cout<<"Range: ["<<minRange<<","<<maxRange<<"], Number of guesses left: "<<guessesLeft<<endl;
        cout<<"Your guess: ";
        cin>>guess;

        if (guessesLeft > 1){                                                    // Comparison for the first 4 guesses
            bool correct = guessCompare(guess, randomNumber, guessesLeft, minRange, maxRange);
            if (correct == 1) {                                                  //If the guess is correct the program stops
                break;
            }
        }

        if (guessesLeft == 1){                                                  // Comparison for last guess
            lastGuess(guess, randomNumber, guessesLeft);
        }

        guessesLeft --;
    }

    return 0; 
}


int randomNumberGenerator(){    //Random number generator fx from 1 - 100 (inclusive)
    int randomNumber = (rand() % 100) + 1;
    return randomNumber;
}

bool guessCompare(int guess, int randomNumber, int guessesLeft, int& minRange, int &maxRange){

    bool correct = 0;
    if(guess < randomNumber){
        cout<<"Wrong! My number is bigger."<<endl;
        minRange = guess + 1;
    }else if(guess > randomNumber){
        cout<<"Wrong! My number is smaller."<<endl;
        maxRange = guess - 1;
    }else{
        cout<<"Congrats! You guessed the number in "<<guessesLeft<<" guesses."<<endl;
        return true;
    }

    return false;

}

void lastGuess(int guess, int randomNumber, int guessesLeft){

    if(guess == randomNumber){
        cout<<"Congrats! You guessed the number in "<<guessesLeft<<" guesses."<<endl;
    }else{
        cout<<"Out of guesses! My number is: "<<randomNumber<<endl;
    }
    
}

