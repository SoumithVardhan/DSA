#include<iostream>
#include<vector>
using namespace std;

// Himanshu Sir Approach
// TC: O(log n)
// SC: O(1)
int findRotations(vector<int>& arr) {
    int low = 0, high = arr.size() - 1;

    while(low < high) {
        int mid = (low + high) / 2;

        if(arr[mid] < arr[high])
            high = mid;        // min is at mid or left of mid
        else
            low = mid + 1;     // min is strictly on right of mid
    }

    // You can return low or high, both are same at this point
    return low;  // index of minimum element = rotation count
}

int main() {
    vector<int> arr = {4, 5, 6, 7, 0, 1, 2, 3};
    cout << findRotations(arr) << "\n"; // 4

    vector<int> arr2 = {3, 4, 5, 1, 2};
    cout << findRotations(arr2) << "\n"; // 3

    vector<int> arr3 = {1, 2, 3, 4, 5};
    cout << findRotations(arr3) << "\n"; // 0
}