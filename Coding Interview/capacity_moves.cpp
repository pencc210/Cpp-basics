/*
 * Problem: Minimum Moves to Cluster Capacities

    Description:
    Given a list of integers representing capacity values, divide them 
    into clusters of equal size. Each cluster must contain identical 
    capacity values. The goal is to determine the minimum number of 
    elements that need to be changed in order to form these clusters.

    Key Constraints:
    - Each cluster must have exactly 'clusterSize' elements.
    - A cluster is valid if all its elements are the same.
    - We can only decrease capacities not encrease
    - Each capacity decrease is one change regardless of the decreased value 
    (7 -> 2 == 3 -> 2)

    Approach:
    1. Use a frequency map to count how many times each capacity appears.
    2. Select repeated capacities as preferred "target" values for clusters,
       to minimize changes.
    3. If not enough repeated values exist, select the smallest available 
       unique values from the sorted list.
    4. Count how many existing values already match target values (up to 
       clusterSize times per target).
    5. The rest must be changed. Return the number of required changes.

    Time Complexity:
    - Sorting: O(n log n)
    - Map building: O(n)
    - Target selection and comparison: O(n)
*/

#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
using namespace std;

int getMinimumMoves(vector<int> capacity, int clusterSize){

    int clusterNumber = capacity.size() / clusterSize; //Calculate number of groups 

    //Calulate target capacities for each cluster
    sort(capacity.begin(), capacity.end());
    //Take the min capacities as our targets (that why we sort) unless there are repeated capacities (priority so we do
    //not change more numbers than needed). i.e. 12345567 , targets: 5,1,2,3

    set<int> targets;

    //Make frequency map to check for repeated capacities
    map <int, int> capacityFreq;
    for(const auto& c : capacity){
        capacityFreq[c]++;
    }
    //Add repeated capacities to target capacity vector
    for(const auto&[cap, freq] : capacityFreq){
        if(freq > 1){
            targets.insert(cap);     
        }
    }

    //Ensure that all target capacities are different by using a set and insert in ascending order
    int i = 0;
    while(targets.size() < clusterNumber && i < capacity.size()){ //targets for every cluster
        targets.insert(capacity[i]);
        i++;
    }

    //Edge: If they are all the same 5, 5, 5, 5 then target must be outise of capacity scope i.e. 4
    if(targets.size() < clusterNumber){
        targets.insert(capacity[0] - 1);
    }
    
    //Knowing cluster targets we now calculate how many changes there will be by finding
    //target vallues in capacity map. We take the min value between cluster size and 
    // number of times a target appears because if a target excedes the cluster size it 
    // means that its a part of a different cluster with a different target and so it should change

    int noChange = 0; //capacities that we do not need to change
    int changes = 0;

    for(const auto& target : targets){
        noChange += min(clusterSize, capacityFreq[target]);
    }

    changes = capacity.size() - noChange;
    return changes;
}


int main(){

    vector <int> v = {1, 2, 2, 3, 4, 5, 5, 5};
    int k = 2; //Cluster size

    cout << getMinimumMoves(v, k) << endl;


    return 0;
}