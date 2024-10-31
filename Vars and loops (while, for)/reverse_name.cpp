


#include <iostream>
#include <vector>
using namespace std;

int main(){

    string name;

    cout<<"Please enter your name: ";
    getline(cin,name);

    for(int i = name.length() - 1; i >= 0; i--){
        cout<<name[i];
    }
    cout<<'\n';

    return 0;
}