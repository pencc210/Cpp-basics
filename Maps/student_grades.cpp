#include <iostream>
#include <map>
#include <vector>
using namespace std;

// Recieves a vector with names and grades, returns a vector of names and their average grade
map <string, int> calculateAverage(map <string, vector<int> > &students);


int main(){

    map <string, vector<int> > students;
    map <string, int> studentAverages;

    students["Alice"] = {85, 90, 78};
    students["Bob"] = {88, 72, 91};
    students["Charlie"] = {79, 95, 82};
    students["Diana"] = {};

    studentAverages = calculateAverage(students);

    for (auto itr= studentAverages.begin(); itr != studentAverages.end(); itr++){
        string name = itr->first;
        double average = itr->second;

        if(average == -1){
            cout<<itr->first<<": No grades available"<<endl;
        }else{
            cout<<itr->first<<": "<<itr->second<<endl;
        }
    }

}


map <string, int> calculateAverage(map <string, vector<int> > &students){ 
    
    map <string, int> studentsAverage;


    for(const auto& [name, grades] : students){
        int sum = 0; 
        double average = 0; 

        if(grades.empty()){ //grades vector is empty
            studentsAverage[name] = -1;
        }else{ //Grades vector has values so calculate average
            for(int grade : grades){ //Add up the grades of one student
                sum += grade;
            }
            average = sum/grades.size();
            studentsAverage[name] = average; // Fills in average dictionary
        }
    }

    return studentsAverage;

}