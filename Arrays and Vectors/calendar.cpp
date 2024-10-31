/*
 * This program generates a yearly calendar for a given year and starting day.
 * It includes functions to:
 *   - Print a monthly calendar grid for any number of days starting on any day of the week
 *   - Check if a given year is a leap year
 *   - Print a complete yearly calendar with each month formatted in a grid layout
 * 
 * Usage:
 *   Run the program to generate a calendar for a specific year, starting from
 *   a specified day of the week (1 for Monday, 7 for Sunday).
 * 
 * Example:
 *   int main() {
 *       printYearCalendar(2016, 5);  // Prints the calendar for 2016 starting on Thursday
 *       return 0;
 *   }
 */

#include <iostream>
using namespace std;

//Prints a grided calendar of a month with a specific number of days (numOfDays) and
//starring day (startingDay)
int printMonthCalendar(int numOfDays, int startingDay); 

//Returns true if year is a leap year
bool checkLeapYear(int year);              

//Prints a calendar of every month in the year using startingDay as the 
//first day of January
void printYearCalendar(int year, int startingDay);      


int main(){
    printYearCalendar(2016, 5);
    return 0;
}

bool checkLeapYear(int year){
    return((year%4 == 0)&&(year%100 != 0)) || (year%400 == 0);
}

int printMonthCalendar(int numOfDays, int startingDay){

    //Print day header
    string dayName[] = {"Mon","Tue","Wed","Thr","Fri","Sat","Sun"};

    for(string day : dayName){
        cout<<day<<'\t';
    }
    cout<<'\n';

    int daysToWeek = 0;

    //Print days grid
    for (int i = (- startingDay) + 2; i <= numOfDays; i++){ //Negative if blank spaces, posititve day count
        daysToWeek ++;
        if(i <= 0){
            cout<<" "<<'\t';
        }else{
            cout<<i<<'\t';
        }

        if(daysToWeek%7 == 0){
            cout<<'\n';
            daysToWeek = 0;
        }
    }
    cout<<'\n';
    cout<<'\n';
    return daysToWeek;
}

void printYearCalendar(int year, int startingDay){
    
    int numOfDays;
    string monthName[] = {"January", "Februrary", "March", 
    "April", "May", "June", "July", "August", "September", 
    "October", "November", "December"};

    for(int month = 1; month <= 12; month++){ //Month by month iteartion 
        //Calculate number of days
        if (month == 2) {  // February
            numOfDays = checkLeapYear(year) ? 29 : 28;
        } else if (month == 4 || month == 6 || month == 9 || month == 11) {  
            // April, June, September, November have 30 days
            numOfDays = 30;
        } else {
            // All other months have 31 days
            numOfDays = 31;
        }

        //Print calendar
        cout<<monthName[month-1]<<" "<<year<<endl;  //Header
        startingDay = printMonthCalendar(numOfDays, startingDay);

        startingDay = (startingDay % 7) + 1; //Adjust day for next month
    }
}