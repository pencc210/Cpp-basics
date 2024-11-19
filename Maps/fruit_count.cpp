/*
 * This program takes in a fruit list from the user and prints out how many fruits
 * of each type there are
 */
#include <iostream>
#include <cctype>
#include <map>

using namespace std;

//Adds a fruit of a specific type to the map fruits and returns it
map <string, int> addFruit(map <string, int> &fruits, string fruitType);


int main(){

    string fruitType;
    map <string, int> fruits;

    while(true){
        cout<<"Please enter a fruit (type 'done' when finished): ";
        cin>>fruitType;

        if(fruitType == "done"){         // End condition
            break;
        }else{                           // Otherwise add fruit to list
            addFruit(fruits, fruitType);  
        }
        
    }

    // Print fruit map
    for(const auto& [fruit, quantity] : fruits){ 
    cout<<fruit<<": "<<quantity<<endl;
    }

    return 0;
}

map <string, int> addFruit(map <string, int> &fruits, string fruitType){

    auto itr = fruits.find(fruitType);

    if(itr != fruits.end()){     //Fruit is in list
        itr-> second += 1;      // Add one to quanity
    }else{                      // Fruit not in list
        fruits [fruitType] = 1; // Add new fruit
    }

    //Above can also be substituded by fruits[fruitType] ++;
    return fruits;
}
