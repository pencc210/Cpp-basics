
#include <iostream>
using namespace std;


class Book {
    public: 

    string title;
    string author;
    int year; 

    void displayInfo(){
        cout<<"Author: "<<author<<", "<<"Title: "<<title<<", "<<"Year: "<<year<<endl;
    }

};


int main(){

    Book b;

    b.author = "Jop";
    b.title = "Leaf";
    b.year = 1997;

    b.displayInfo();

    return 0;
}