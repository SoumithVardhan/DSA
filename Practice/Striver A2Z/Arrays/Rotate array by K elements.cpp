#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void reverseArray(vector<int>& nums, int start, int end) {
        while (start < end) {
            swap(nums[start], nums[end]);
            start++;
            end--;
        }
    }
    vector<int> rotateArray(vector<int>& nums, int k, string direction) {
        int n = nums.size();
        if (n == 0 || k == 0) return nums;
        k = k % n;

        if (direction == "right") {
            
            reverseArray(nums, 0, n - 1);

            reverseArray(nums, 0, k - 1);

            reverseArray(nums, k, n - 1);
        } 
        else if (direction == "left") {

            reverseArray(nums, 0, k - 1);

            reverseArray(nums, k, n - 1);

            reverseArray(nums, 0, n - 1);
        }

        return nums;
    }
};

int main() {
    Solution sol;

    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    int k = 2;
    string dir = "right";

    vector<int> result = sol.rotateArray(nums, k, dir);

    for (int num : result) {
        cout << num << " ";
    }

    return 0;
}
