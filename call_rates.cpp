/* This program to compute the cost of a long-distance call based on start day and time.
 * 
 * Rates:
 * - Weekdays (Mo-Fr): 
 *   - 8:00 A.M. - 6:00 P.M.: $0.40/min
 *   - Outside this range: $0.25/min
 * - Weekends (Sa-Su): 
 *   - All times: $0.15/min
 *
 * Caveats: It does not consider rate changes if the call extends into a different rate period.
 * It could be refined by not asking for the time if the call started during the weekend 
*/

#include <iostream>
using namespace std;

int main(){

    int min, hour, callLength;
    float charge;
    bool weekday;
    string day;
    char devider; 


    cout<<"Please enter the call start day with its first two characters (Mo, Tu, etc.): ";
    cin>>day;
    cout<<"Please enter the call start time in 24h notation: ";
    cin>>hour>>devider>>min;
    cout<<"Please enter the length of call in minutes: ";
    cin>>callLength;

    if (day == "Sa" || day == "Su"){            // defines whether its a weekday or the weekend
        weekday = 0;
    }else{
        weekday = 1; 
    }

    if (weekday){

        if((8<=hour && hour<18) || (hour == 18 && min == 0)){
            charge = callLength * 0.4;
        }else{
            charge = callLength * 0.25;
        }
    }else{
        charge = callLength * 0.15;
    }

    cout<<"The total call cost was: "<<charge<<endl;

}