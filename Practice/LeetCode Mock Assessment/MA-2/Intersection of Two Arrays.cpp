#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());

    vector<int> result;
    int i = 0, j = 0;

    while (i < (int)nums1.size() && j < (int)nums2.size()) {
        if (nums1[i] < nums2[j]) {
            i++;
        } else if (nums1[i] > nums2[j]) {
            j++;
        } else {
            // only add if not duplicate
            if (result.empty() || result.back() != nums1[i]) {
                result.push_back(nums1[i]);
            }
            i++;
            j++;
        }
    }

    return result;
}


int main() {

    vector<int> nums1 = {1, 2, 2, 1};
    vector<int> nums2 = {2, 2};
    vector<int> res = intersection(nums1, nums2);
    for (int x : res) cout << x << " ";
    cout << endl;

    vector<int> nums3 = {4, 9, 5};
    vector<int> nums4 = {9, 4, 9, 8, 4};
    res = intersection(nums3, nums4);
    for (int x : res) cout << x << " ";
    cout << endl;

    return 0;
}