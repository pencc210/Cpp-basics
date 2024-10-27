/*
 * This program takes in a fruit list from the user and prints out how many fruits
 * of each type there are
 */
#include <iostream>
#include <cctype>
#include <map>

using namespace std;

map <string, int> addFruit(map <string, int> &fruits, string fruitType){

    auto itr = fruits.find(fruitType);

    if(itr != fruits.end()){
        itr-> second += 1;
    }else{
        fruits [fruitType] = 1;
    }
    return fruits;
}


int main(){

    string fruitType;
    map <string, int> fruits;

    while(true){
        cout<<"Please enter a fruit (type 'done' when finished): ";
        cin>>fruitType;

        if(fruitType == "done"){
            break;
        }else{
            addFruit(fruits, fruitType);  
        }
        
    }

    // Print fruit map
    for(const auto& [fruit, quantity] : fruits){ 
    cout<<fruit<<": "<<quantity<<endl;
    }

    return 0;
}