

#include <iostream>
#include <vector>
#include <algorithm>  // For reverse function

using namespace std;

int main() {
    vector<int> arr;
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);
    arr.push_back(4);
    arr.push_back(5);

    int k = 3;

    // Reverse the first k elements
    reverse(arr.begin(), arr.begin() + k);

    // Print the array after reversal
    for (int i : arr) {
        cout << i << " ";
    }

    return 0;
}
