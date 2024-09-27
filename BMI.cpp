
/*
 * This program takes in the user's height and weight in inches and pounds, converts is to cm and kg, 
 * calculates the person's BMI and classifies then in a weight status category (Underweight, 
 * Normal, Overweight or Obese)
*/

#include <iostream>
using namespace std;

int main(){

    int hInches, wPounds;
    float hMeters, wKg, bmi;
    string weightStatus;
    
    cout<<"Please enter weight (in pounds): ";
    cin>>wPounds;
    cout<<"Please enter height (in inches): ";
    cin>>hInches;

    hMeters = hInches * 0.0254;
    wKg = wPounds * 0.453592;

    bmi = wKg / (hMeters * hMeters);

    if (bmi <= 18.5){
        weightStatus = "Underweight";
    }if (18.5 < bmi && bmi <= 25){
        weightStatus = "Normal";
    }if (25 < bmi && bmi <= 30){
        weightStatus = "Overweight";
    }if (30 < bmi){
        weightStatus = "Obese";
    }

    cout<<"The weight status is: "<<weightStatus<<endl; 
    cout<<bmi;



}