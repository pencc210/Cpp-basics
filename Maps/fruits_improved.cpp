#include <iostream>
#include <map>

using namespace std;



int main(){

    map <string, int> fruits;
    string fruit;

    while(true){

        cout << "Please enter fruit (type 'done' when finished): " << endl;
        cin >> fruit;

        if(fruit == "done"){
            break;
        }else{
            fruits[fruit]++;
        }

    }

    //Print fruit map
    for(const auto&[type, quantity] : fruits){
        cout << type << " : " << quantity << endl;
    }

    return 0;
}