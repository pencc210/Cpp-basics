/* This program converts a 24 hour time into its 12-hour format*/

#include <iostream>
using namespace std;

int main(){

    int hour24, min24;
    int hour12, min12;
    char temp;
    string miday;

    cout<<"Please enter a time in 24-hour format: ";
    cin>>hour24>>temp>>min24;

    min12 = min24; 

    if(hour24>=0 && hour24<12){
        miday = "am";
        if(hour24==0){
            hour12 = 12;
        }
        else{
            hour12 = hour24;
        }
    }

    if(hour24>=12 && hour24<24){
        miday = "pm";
        if(hour24==12){
            hour12 = hour24;
        }
        else{
            hour12 = hour24-12;
        }
    }


    cout<<"\n"<< "The time in 12-hour format is: "<<hour12<<temp<<min12<<" "<<miday<<endl;


    return 0; 
}