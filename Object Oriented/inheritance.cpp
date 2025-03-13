
#include <iostream>
using namespace std;

class Vehicle {
    public:

    void move(){
        cout<<"It moves"<<endl;
    }
};

class Car : public Vehicle {

    public:
    void honk(){
        cout<<"It honks"<<endl;
    }
};


int main(){

    Car c;
    c.move();
    c.honk();

    return 0;
}