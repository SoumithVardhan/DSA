#include <iostream>
#include <vector>
using namespace std;

// This approach only works for non-negative numbers in the array. 
// For negative numbers, we need to use a different approach (like using a hash map to store cumulative sums).
int subarraySum(vector<int>& nums, int k) {
    int left = 0, sum = 0, count = 0;

    for (int right = 0; right < nums.size(); right++) {
        sum += nums[right];           

        // shrink from left if sum exceeds k
        while (sum > k && left <= right) {
            sum -= nums[left];
            left++;
        }

        if (sum == k) count++;
    }
    return count;
}


class Solution {
public:
    // Approach 1: Brute force approach
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                int sum = 0;
                for (int x = i; x <= j; x++) {
                    sum += nums[x];
                }
                if (sum == k) count++;
            }
        }
        return count;
    }

    // Approach 2: Better approach 
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;

        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = i; j < n; j++) {
                sum += nums[j];        
                if (sum == k) count++;
            }
        }
        return count;
    }

    // Approach 3: Optimal approach using hash map to store cumulative sums
    int subarraySum(vector<int>& nums, int k) {
        // map stores {prefixSum : frequency}
        unordered_map<int, int> prefixCount;
        prefixCount[0] = 1;  // base case: empty subarray

        int sum = 0, count = 0;

        for (int num : nums) {
            sum += num;

            // Check if (sum - k) exists in map
            // If yes, those many subarrays end here with sum = k
            if (prefixCount.find(sum - k) != prefixCount.end()) {
                count += prefixCount[sum - k];
            }

            // Store current prefix sum in map
            prefixCount[sum]++;
        }

        return count;
    }
};