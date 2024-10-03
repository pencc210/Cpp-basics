/*
 * This program converts a decimal into binary without using srting or cout manipulations.
 * It uses a while loop to iterate through powers of 2 and print out the binary result form left to right. 
 */

#include <iostream>
using namespace std;

int main() {
    int decimal, temp, highestBit;

    cout << "Enter decimal number: ";
    cin >> decimal;

    cout << "The binary representation of " << decimal << " is ";

    // Special case for 0
    if (decimal == 0) {
        cout << "0" << endl;
        return 0;
    }


    temp = decimal;
    highestBit = 1;  // This will store the highest bit position

    // Calculates the highest power of 2 that fits in the number
    while (temp > 1) {
        temp /= 2;
        highestBit *= 2;
    }

    // Prints the binary representation starting from the highest bit
    while (highestBit > 0) {
        // Print 1 if the current bit is set, else print 0
        if (decimal >= highestBit) {
            cout << "1";
            decimal -= highestBit;
        } else {
            cout << "0";
        }

        highestBit /= 2;  // Move to the next lower bit
    }

    cout << endl;
    return 0;
}
