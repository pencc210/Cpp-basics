/*
 * This program calculates the best combination of items stolen to maximize the stolen
 * value. The items must fit inside a knapsack and can be devided into fractions. 
 */

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;


//Create item object

struct Item{
    char id;
    int weight;
    int value;
    double ratio;
};

//Caluclate value / weight ratio for each item
void valueWeightRatio(vector<Item>& items){
    int ratio;
    for(auto& item : items){
        ratio = static_cast<double>(item.value) / item.weight; //Double ratio instead of int operation for precision in fractions
        item.ratio = ratio;
    }
}

//Comparator to sort by value / weight ratio
bool compareByRatio(const Item& a, const Item& b){
    return a.ratio > b.ratio;
}

// Function to select specific items
vector <Item> itemSelection(vector<Item>& items, int &capacity){

    sort(items.begin(), items.end(), compareByRatio); //Sort from most to least valueable per weight
    vector <Item> selectedItems; //Vector for chosen items

    for (auto item : items){ //pass by value to alter fractional item weight
        //If the item fits in the bag it is added and 
        //the capacity updated
        if(item.weight <= capacity){ 
            selectedItems.push_back(item);
            capacity -= item.weight;
        }else{ //The whole item does not fit in the bag, add a fraction and end the loop (it will be the last item)
            item.weight = capacity; //alters fractional item weight
            selectedItems.push_back(item);
            capacity = 0;
        }
    }

    return selectedItems;

}

//Prints the items and faction of last item that will fit in the knapsack
void printItemVector(vector <Item>& items){
    cout<<"The knapsack will fit: "<<endl;

    for(int i = 0; i < items.size(); i++){
        const auto& item = items[i];

        if(i < items.size() - 1){ //First whole items
            cout<<item.id<<endl;
        }else{                    //Last item 
            cout<<"And "<<item.weight<<" of item "<<item.id<<endl;

        }
    }

}

//Caculates the total value of the stolen items 
int totalValue(vector <Item> &selectedItems){
    int value = 0;
    for(const auto& item : selectedItems){
        value += item.weight * item.ratio;
    }
    return value;
}


int main(){

    vector<Item> items {
        {'A', 10, 60}, {'B', 20, 100}, {'C', 30, 120}
    };
    int knapsackCapacity = 50; 

    vector<Item> selectedItems;
    //Caculate each weight ratio
    valueWeightRatio(items); 
    //Select the items to steal
    selectedItems = itemSelection(items, knapsackCapacity); 
    //Print out selected items and last fractional item
    printItemVector(selectedItems);  

    //Total stolen value calculation and print 
    int stolenValue;
    stolenValue = totalValue(selectedItems);
    cout<<"The total stolen value is: "<<stolenValue<<endl;
    
    return 0;
}