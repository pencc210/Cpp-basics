
#include <iostream>
using namespace std;

class Laptop {
    string brand;
    double price;

    public: 
    Laptop (string b, double p) : brand(b), price(p){} //Constructor

    ~Laptop() {
        cout << "Laptop object deleted. Brand: " << brand << endl;
    }

    void displayInfo() {
        cout << "Laptop: " << brand << ", Price: $" << price << endl;
    }

};

int main(){

    Laptop L("Mac", 20000);
    L.displayInfo();

    return 0; 
}