#include<iostream>
#include<vector>
using namespace std;

// Himanshu Sir Approach
int findMin(vector<int>& arr) {
    int low = 0, high = arr.size() - 1;

    while(low < high) {
        int mid = (low + high) / 2;

        if(arr[mid] < arr[high])
            high = mid;        
        else
            low = mid + 1;     
    }

    // If you return index then it indicates the no of rotations.
    return arr[low];
}

int main() {
    vector<int> arr = {4, 5, 6, 7, 0, 1, 2, 3};
    cout << findMin(arr) << "\n"; // 0

    vector<int> arr2 = {3, 4, 5, 1, 2};
    cout << findMin(arr2) << "\n"; // 1
}