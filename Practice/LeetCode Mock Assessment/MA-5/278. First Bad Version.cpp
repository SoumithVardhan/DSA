#include<iostream>
using namespace std;

// Mock the API — set bad version here
int BAD_VERSION = 4;
bool isBadVersion(int version) {
    return version >= BAD_VERSION;
}

class Solution {
public:
    int firstBadVersion(int n) {
        int start = 1, end = n;

        while(start < end) {
            int mid = start + (end - start) / 2;

            if(isBadVersion(mid))
                end = mid;        // mid could be first bad, go left
            else
                start = mid + 1;  // mid is good, go right
        }

        return end; // start == end == first bad version
    }
};

int main() {
    Solution obj;

    // Test 1: n=5, bad=4
    BAD_VERSION = 4;
    cout << obj.firstBadVersion(5) << "\n";  // 4

    // Test 2: n=1, bad=1
    BAD_VERSION = 1;
    cout << obj.firstBadVersion(1) << "\n";  // 1

    // Test 3: n=10, bad=7
    BAD_VERSION = 7;
    cout << obj.firstBadVersion(10) << "\n"; // 7

    return 0;
}