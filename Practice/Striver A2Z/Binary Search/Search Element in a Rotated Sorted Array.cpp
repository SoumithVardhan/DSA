#include<iostream>
#include<vector>
using namespace std;

// Standard binary search
int binarySearch(vector<int>& arr, int low, int high, int k) {
    while(low <= high) {
        int mid = (low + high) / 2;
        if(arr[mid] == k)   return mid;
        else if(arr[mid] < k) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

// Find pivot (min element index)
int findPivot(vector<int>& arr) {
    int low = 0, high = arr.size() - 1;
    while(low < high) {
        int mid = (low + high) / 2;
        if(arr[mid] < arr[high]) high = mid;
        else low = mid + 1;
    }
    return low;
}

int search(vector<int>& arr, int k) {
    int n = arr.size();
    int pivot = findPivot(arr);

    // Search in left sorted array
    int left = binarySearch(arr, 0, pivot - 1, k);
    if(left != -1) return left;

    // Search in right sorted array
    int right = binarySearch(arr, pivot, n - 1, k);
    return right;
}

int main() {
    vector<int> arr = {4, 5, 6, 7, 0, 1, 2};

    cout << search(arr, 0) << "\n";  // 4
    cout << search(arr, 3) << "\n";  // -1
    cout << search(arr, 4) << "\n";  // 0
}