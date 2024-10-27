/*
 * This program creates a data set of names and their ages, it asks a name form the user 
 * and searches the database to retrieve their age. 
 */

#include <iostream>
#include <map>
using namespace std;

void checkAge(map<string,int> &names, string &name){ //Searches names for the name of someone and prints out their age 
    auto itr = names.find(name);                     // if they are in the data set, otherwise it prints "Name not found"
    if(itr == names.end()){
        cout<<"Name not found"<<endl;
    }else{
        cout<<name<<" is "<<itr->second<<endl;
    }


}

int main(){

    string name;

    map<string, int> names ={
        {"Alice", 28},
        {"Bob", 30}
    };
    
    names["Charlie"] = 22;
    names["Diana"] = 27;
    names["Eve"] = 35;

    cout<<"Write a name: ";
    cin>> name;

    checkAge(names, name);


 /*    for (auto itr = names.begin(); itr != names.end(); itr++){
        cout<<(*itr).first<<" : "<<(*itr).second<<endl;
    }  */



}