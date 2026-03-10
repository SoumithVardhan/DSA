#include <iostream>
#include <vector>
using namespace std;

// TC: O(log n)
// SC: O(1)
// Find first occurrence of x
int firstOccurrence(vector<int>& arr, int n, int x) {
    int low = 0, high = n - 1;
    int first = -1;
    while(low <= high) {
        int mid = (low + high) / 2;
        if(arr[mid] == x) {
            first = mid;
            high = mid - 1;    
        }
        else if(arr[mid] < x) low = mid + 1;
        else high = mid - 1;
    }
    return first;
}

// Find last occurrence of x
int lastOccurrence(vector<int>& arr, int n, int x) {
    int low = 0, high = n - 1;
    int last = -1;
    while(low <= high) {
        int mid = (low + high) / 2;
        if(arr[mid] == x) {
            last = mid;        
            low = mid + 1;     
        }
        else if(arr[mid] < x) low = mid + 1;
        else high = mid - 1;
    }
    return last;
}

int countOccurrences(vector<int>& arr, int n, int x) {
    int first = firstOccurrence(arr, n, x);

    // x not found at all
    if(first == -1) return 0;

    int last = lastOccurrence(arr, n, x);
    return last - first + 1;
}

int main() {
    vector<int> arr = {2, 2, 3, 3, 3, 3, 4};
    int n = 7, x = 3;
    cout << "Occurrences: " << countOccurrences(arr, n, x) << "\n"; // 4

    vector<int> arr2 = {1, 1, 2, 2, 2, 2, 2, 3};
    int n2 = 8, x2 = 2;
    cout << "Occurrences: " << countOccurrences(arr2, n2, x2) << "\n"; // 5

    return 0;
}
