//Reading file and more operations
#include <iostream>
#include <fstream>
using namespace std;


//Super useful function to open files
void openInputFile(ifstream& inFile){
    string filename;
    cout << "What is the file name? " << endl;
    cin >> filename;
    inFile.open(filename); //tries to open in for the first time
    while (!inFile) //failed to open
    {
        cout << "FILE FAILED TO OPEN!" << endl; 
        cout << "What is the file name? " << endl;
        cin >> filename;
        inFile.clear(); //clears previous failed flag 
        inFile.open(filename);
    }
    
}

struct Student {
    int id;
    double testScore;
    string name;

};

int main(){

    ifstream File;
    openInputFile(File);

    //Vector to store values in file 
    vector<Student> v; 
    
    Student student;

    while(File >> student.id){ //The first thing in file is the student id
        File >> student.testScore;   //Second thing is the name
        File.ignore(9999, '\t'); //We ignore the 9999th character or the tab, whichever comes first
        getline(File, student.name); //Thrid thing is name and we get the whole remaining line to get both first and last names
        v.push_back(student);
    }

    cout<<"The studensts who scored more than 90 are: "<<endl;
    for(Student s : v){
        if (s.testScore > 90){
            cout<<s.name<<endl;
        }
    }


    return 0;
}