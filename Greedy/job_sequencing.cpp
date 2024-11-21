/*
 * Given a list of jobs, each of wich takes 1 time unit to complete
 * and has a specific deadline, this program selects the job order
 * that maximizes profit. 
 */

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

//Create the job object
struct Job {
    char id;
    int deadline;
    int profit;
};

//Comparator to order according to max profit or closets deadline if
//profist are equal
bool compareByProfit(const Job& a, const Job& b){
    if (a.profit == b.profit) {
        return a.deadline < b.deadline; // Sort by deadline if profits are equal
    }
    return a.profit > b.profit;
}

//Function to select maximum number of jobs
map<int, Job> jobSelector(vector<Job>& jobs){

    //Map with time slots and chosen jobs
    map<int, Job> selectedJobs;

    //sort jobs vector from most to least profit
    sort(jobs.begin(), jobs.end(), compareByProfit);

    for(auto& job : jobs){
        for(int i = job.deadline; i >= 1; i--){ //Schedule job as close as possible to its deadline
            if(selectedJobs.find(i) == selectedJobs.end()){ //Time slot is free
                selectedJobs[i]=job;    //Add job
                break;
            }
        }
    }
    return selectedJobs;
}


int main(){

    vector<Job> jobs{
        {'A', 2, 100}, {'B', 1, 19}, {'C', 2, 27}, {'D', 1, 25}, 
        {'E', 3, 15}
    };

    map<int, Job> selectedJobs;
    selectedJobs = jobSelector(jobs);

    cout<<"The optimal job order is: "<<endl;
    for(const auto& item : selectedJobs){
        cout<<"Job: "<<item.second.id<<endl;
    }


    return 0;
}
