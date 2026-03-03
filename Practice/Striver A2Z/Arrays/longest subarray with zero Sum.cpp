#include <iostream>
#include <vector>

using namespace std;

/*
 * BRUTE FORCE APPROACH - Check All Subarrays
 * 
 * TIME COMPLEXITY: O(N²)
 * - Outer loop: O(N) - starting point
 * - Inner loop: O(N) - ending point
 * - Total: O(N²)
 * 
 * SPACE COMPLEXITY: O(1)
 * - Only using variables, no extra data structures
 */


int maxLen(vector<int>& arr) {
    int n = arr.size();
    int maxLength = 0;
    
    // Try all possible starting points
    for(int i = 0; i < n; i++) {
        int sum = 0;
        
        for(int j = i; j < n; j++) {
            sum += arr[j];
            
            if(sum == 0) {
                maxLength = max(maxLength, j - i + 1);
            }
        }
    }
    
    return maxLength;
}


// Approach 2 : Using Hash Map
// TIME COMPLEXITY: O(N)
// SPACE COMPLEXITY: O(N)

/*
 * OPTIMAL APPROACH - Prefix Sum with HashMap
 * 
 * KEY INSIGHT:
 * If prefix_sum[i] == prefix_sum[j], then sum(i+1 to j) = 0
 * 
 * TIME COMPLEXITY: O(N)
 * - Single pass through array: O(N)
 * - HashMap operations (insert/find): O(1) average
 * 
 * SPACE COMPLEXITY: O(N)
 * - HashMap stores at most N prefix sums
 */

class Solution {
public:
    int maxLen(vector<int>& arr) {
        int n = arr.size();
        
        unordered_map<int, int> prefixSumMap;
        
        int maxLength = 0;
        int prefixSum = 0;
        
        for(int i = 0; i < n; i++) {
            // Update running prefix sum
            prefixSum += arr[i];
            
            // ═══════════════════════════════════════════════════
            // CASE 1: Prefix sum is 0
            // ═══════════════════════════════════════════════════
            // This means subarray [0...i] has sum = 0
            if(prefixSum == 0) {
                maxLength = i + 1;  // Length from start to current
            }
            
            // ═══════════════════════════════════════════════════
            // CASE 2: Prefix sum seen before
            // ═══════════════════════════════════════════════════
            // This means subarray (previous_index...i] has sum = 0
            else if(prefixSumMap.find(prefixSum) != prefixSumMap.end()) {
                // Calculate length of zero-sum subarray
                int length = i - prefixSumMap[prefixSum];
                maxLength = max(maxLength, length);
            }
            
            // ═══════════════════════════════════════════════════
            // CASE 3: First time seeing this prefix sum
            // ═══════════════════════════════════════════════════
            // Store it in map (we want FIRST occurrence for max length)
            else {
                prefixSumMap[prefixSum] = i;
            }
        }
        
        return maxLength;
    }
};