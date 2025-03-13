
#include <iostream>
using namespace std;

class Employee{
    public: 
    virtual void work(){
        cout<<"Works"<<endl;
    }
};

class Manager : virtual public Employee{
    public: 
    void eng() {
        cout<<"Engineers"<<endl;
    }
};

class Engineer : virtual public Employee{
    public: 
    void man() {
        cout<<"Manages"<<endl;
    }
};

class TechLead : public Engineer, public Manager{
    public:
    void salary() {
        cout<<"Gets paid the most"<<endl;
    }
};

int main(){

    TechLead t;
    t.work();   // No ambiguity due to virtual inheritance
    t.eng();
    t.man();
    t.salary();

    return 0; 
}