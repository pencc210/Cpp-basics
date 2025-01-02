#include <iostream>
using namespace std;

class Person{
    //Private atributes (first and last name)
    string first;
    string last; 

    public:
    Person(string first, string last): first(first), last(last) {} //Constructor

    /* //Setter fx
    void setFirstName(string first){ this->first = first; } //one way to write it
    void setLasttName(string lastName){ last = lastName; } //another way */

    string getFullName(){ return first + " " + last; } //Getter: returns full name string

    void printFullName(){ cout<<first<<" "<<last<<endl; } //Prints the name

};

int main(){

    Person p("Jack", "Bill"); //Create object

    p.printFullName();



/*     p.setFirstName("Lara");
    p.setLasttName("Croft");

    p.printFullName(); */

    return 0;
}