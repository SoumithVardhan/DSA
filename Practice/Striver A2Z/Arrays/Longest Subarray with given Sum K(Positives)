#include <iostream>
#include <vector>

using namespace std;

/*
 * BRUTE FORCE APPROACH - Check All Subarrays
 * 
 * ALGORITHM:
 * 1. Try all possible starting indices (i)
 * 2. For each start, try all possible ending indices (j)
 * 3. Calculate sum of subarray [i...j]
 * 4. If sum equals k, update max length
 * 
 * TIME COMPLEXITY: O(N²)
 * - Outer loop: O(N) - starting point
 * - Inner loop: O(N) - ending point and sum calculation
 * - Total: O(N²)
 * 
 * SPACE COMPLEXITY: O(1)
 * - Only using variables, no extra data structures
 */

class Solution {
public:
    int longestSubarrayWithSumK(vector<int>& nums, int k) {
        int n = nums.size();
        int maxLength = 0;
        
        for(int i = 0; i < n; i++) {
            int sum = 0;
            
            for(int j = i; j < n; j++) {
                sum += nums[j];
                if(sum == k) {
                    maxLength = max(maxLength, j - i + 1);
                }
                if(sum > k) {
                    break;  // Stop inner loop early
                }
            }
        }
        
        return maxLength;
    }
};

/*
 * OPTIMAL APPROACH - Two Pointer (Sliding Window)
 * 
 * KEY INSIGHT:
 * Since all numbers are POSITIVE, we can use sliding window!
 * - Sum increases when we add elements (expand right)
 * - Sum decreases when we remove elements (shrink left)
 * 
 * ALGORITHM:
 * 1. Use left and right pointers to maintain window
 * 2. If sum < k → expand window (right++)
 * 3. If sum > k → shrink window (left++)
 * 4. If sum == k → update max length
 * 
 * TIME COMPLEXITY: O(N)
 * - Each element added at most once (right pointer)
 * - Each element removed at most once (left pointer)
 * - Total operations: O(2N) = O(N)
 * 
 * SPACE COMPLEXITY: O(1)
 * - Only using two pointers and variables
 * 
 * NOTE: This ONLY works for POSITIVE numbers!
 * For arrays with negatives, use HashMap approach instead.
 */

 // This approach only works for positive numbers, if there are negative numbers we have to use hashmap approach
class Solution {
public:
    int longestSubarrayWithSumK(vector<int>& nums, int k) {
        int n = nums.size();
        int left = 0;      
        int right = 0;    
        int sum = 0;      
        int maxLength = 0;
        while(right < n) {
            sum += nums[right];
            while(left <= right && sum > k) {
                sum -= nums[left];
                left++;
            }
            if(sum == k) {
                maxLength = max(maxLength, right - left + 1);
            }
            right++;
        }        
        return maxLength;
    }
};

// HashMap approach for arrays works with negative numbers as well, but it is not required here as we are only dealing with positive numbers
 int longestSubarrayWithSumK(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> prefixSumMap;
        int maxLength = 0;
        int prefixSum = 0;
        for(int i = 0; i < n; i++){
            prefixSum += nums[i];
            if(prefixSum == k) {
                maxLength = i + 1;  
            }
            if(prefixSumMap.find(prefixSum - k) != prefixSumMap.end()) {
                int length = i - prefixSumMap[prefixSum - k];
                maxLength = max(maxLength, length);
            }
            if(prefixSumMap.find(prefixSum) == prefixSumMap.end()) {
                prefixSumMap[prefixSum] = i;
            }
        }
        return maxLength;
    }