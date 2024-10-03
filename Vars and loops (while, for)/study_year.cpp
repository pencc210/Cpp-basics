/* 
 * This program takes a student's graduation date and the current year and calculates 
 * their current status (not in college yet, freshman - 1st, sophomore - 2nd, junior - 3rd, 
 * senior - 4th or graduated).
 * Special case: if the current year equals graduation year status is graduated.
*/


#include <iostream> 
using namespace std;

int main(){

    int currYear, gradYear, difference;
    string studyStatus, name;

    cout<<"Please enter your name: ";
    cin>>name;

    cout<<"Please enter your graduation year: ";
    cin>>gradYear;

    cout<<"Please enter current year ";
    cin>>currYear;

    if(currYear>=gradYear){
        studyStatus = "Graduated";
    }
    else{

        difference = gradYear - currYear;

        if(difference>4){
            studyStatus="not in college yet";
        }

        if (difference==4){
            studyStatus="a Freshman";
        }
        if (difference==3){
            studyStatus="a Sophomore";
        }
        if (difference==2){
            studyStatus="a Junior";
        }
        if (difference==1){
            studyStatus="a Senior";
        }
    }

    cout<<name<<", you are "<<studyStatus<<endl;
    cout<<difference;


}