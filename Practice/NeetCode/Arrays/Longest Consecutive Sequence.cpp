#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

// Approach 1 : HashSet with Smart Iteration
/*
 * LONGEST CONSECUTIVE SEQUENCE - O(n) Solution
 * 
 * PROBLEM:
 * Given an unsorted array of integers, find the length of the longest 
 * consecutive elements sequence.
 * 
 * Example: [100, 4, 200, 1, 3, 2]
 * Longest consecutive sequence: [1, 2, 3, 4]
 * Answer: 4
 * 
 * CONSTRAINT: Must run in O(n) time
 * 
 * ════════════════════════════════════════════════════════════════════
 * 
 * APPROACH: HashSet with Smart Iteration
 * 
 * KEY INSIGHT:
 * - Don't count from every number
 * - Only count from the START of each sequence
 * - How to identify start? If (num-1) doesn't exist in set
 * 
 * INTUITION:
 * For sequence [1, 2, 3, 4]:
 *   - When checking 4: Is 3 present? YES → Don't start here
 *   - When checking 3: Is 2 present? YES → Don't start here
 *   - When checking 2: Is 1 present? YES → Don't start here
 *   - When checking 1: Is 0 present? NO → START HERE! ✓
 * 
 * This way we count each sequence only ONCE (from its beginning)
 * 
 * ════════════════════════════════════════════════════════════════════
 * 
 * ALGORITHM:
 * 1. Put all numbers in a HashSet (for O(1) lookup)
 * 2. For each number:
 *    a. Check if it's the start of a sequence (num-1 not in set)
 *    b. If yes, count consecutive numbers forward
 *    c. Track maximum length
 * 
 * ════════════════════════════════════════════════════════════════════
 * 
 * TIME COMPLEXITY: O(n)
 * - Creating set: O(n)
 * - Outer loop: O(n)
 * - Inner while loop: O(n) TOTAL (amortized, not per iteration!)
 *   Why? Each number is visited at most twice:
 *   - Once in outer loop
 *   - Once in while loop (only if part of a sequence)
 *   Since we skip non-starts, total operations = O(n)
 * 
 * SPACE COMPLEXITY: O(n)
 * - HashSet stores all unique numbers
 * 
 * ════════════════════════════════════════════════════════════════════
 */

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // Edge case: Empty array
        if(nums.empty()) return 0;
        
        // ═══════════════════════════════════════════════════════════
        // STEP 1: Create HashSet for O(1) lookup
        // ═══════════════════════════════════════════════════════════
        // Why HashSet?
        // - Need to check if (num-1) and (num+1) exist quickly
        // - HashSet provides O(1) average lookup time
        // - Also removes duplicates automatically
        
        unordered_set<int> numSet(nums.begin(), nums.end());
        
        int maxLength = 0;  // Track longest sequence found
        
        // ═══════════════════════════════════════════════════════════
        // STEP 2: Iterate through each unique number
        // ═══════════════════════════════════════════════════════════
        
        for(int num : numSet) {
            
            // ───────────────────────────────────────────────────────
            // KEY OPTIMIZATION: Only process sequence starts
            // ───────────────────────────────────────────────────────
            // Check if (num-1) exists in the set
            // - If YES: num is NOT the start → skip it
            // - If NO: num IS the start → count from here
            
            if(numSet.find(num - 1) == numSet.end()) {
                
                // ───────────────────────────────────────────────────
                // This IS the start of a sequence!
                // ───────────────────────────────────────────────────
                
                int currentNum = num;        // Start counting from here
                int currentLength = 1;       // Current sequence length
                
                // ───────────────────────────────────────────────────
                // Count consecutive numbers forward
                // ───────────────────────────────────────────────────
                // Keep checking if (currentNum + 1) exists
                // Example: If num=2, check 3, then 4, then 5...
                
                while(numSet.find(currentNum + 1) != numSet.end()) {
                    currentNum++;      // Move to next number
                    currentLength++;   // Increment sequence length
                }
                
                // ───────────────────────────────────────────────────
                // Update maximum length if current sequence is longer
                // ───────────────────────────────────────────────────
                
                maxLength = max(maxLength, currentLength);
            }
            
            // If (num-1) exists, we skip this number entirely
            // We'll count the sequence when we reach (num-1)
        }
        
        return maxLength;
    }
};

/*
 * ════════════════════════════════════════════════════════════════════
 * TRACE EXAMPLE: nums = [100, 4, 200, 1, 3, 2]
 * ════════════════════════════════════════════════════════════════════
 * 
 * Step 1: Create set
 *   numSet = {1, 2, 3, 4, 100, 200} (unordered, duplicates removed)
 * 
 * Step 2: Iterate
 * 
 * ┌─────────────────────────────────────────────────────────────────┐
 * │ num = 1                                                         │
 * ├─────────────────────────────────────────────────────────────────┤
 * │ Check: Is (1-1=0) in set? NO → 1 is START ✓                   │
 * │ Count: 1 → 2 (found) → 3 (found) → 4 (found) → 5 (not found)  │
 * │ Sequence: [1, 2, 3, 4]                                         │
 * │ Length: 4                                                       │
 * │ maxLength = 4                                                   │
 * └─────────────────────────────────────────────────────────────────┘
 * 
 * ┌─────────────────────────────────────────────────────────────────┐
 * │ num = 2                                                         │
 * ├─────────────────────────────────────────────────────────────────┤
 * │ Check: Is (2-1=1) in set? YES → 2 is NOT start ✗              │
 * │ SKIP (already counted from 1)                                  │
 * └─────────────────────────────────────────────────────────────────┘
 * 
 * ┌─────────────────────────────────────────────────────────────────┐
 * │ num = 3                                                         │
 * ├─────────────────────────────────────────────────────────────────┤
 * │ Check: Is (3-1=2) in set? YES → 3 is NOT start ✗              │
 * │ SKIP (already counted from 1)                                  │
 * └─────────────────────────────────────────────────────────────────┘
 * 
 * ┌─────────────────────────────────────────────────────────────────┐
 * │ num = 4                                                         │
 * ├─────────────────────────────────────────────────────────────────┤
 * │ Check: Is (4-1=3) in set? YES → 4 is NOT start ✗              │
 * │ SKIP (already counted from 1)                                  │
 * └─────────────────────────────────────────────────────────────────┘
 * 
 * ┌─────────────────────────────────────────────────────────────────┐
 * │ num = 100                                                       │
 * ├─────────────────────────────────────────────────────────────────┤
 * │ Check: Is (100-1=99) in set? NO → 100 is START ✓              │
 * │ Count: 100 → 101 (not found)                                   │
 * │ Sequence: [100]                                                 │
 * │ Length: 1                                                       │
 * │ maxLength = 4 (unchanged)                                       │
 * └─────────────────────────────────────────────────────────────────┘
 * 
 * ┌─────────────────────────────────────────────────────────────────┐
 * │ num = 200                                                       │
 * ├─────────────────────────────────────────────────────────────────┤
 * │ Check: Is (200-1=199) in set? NO → 200 is START ✓             │
 * │ Count: 200 → 201 (not found)                                   │
 * │ Sequence: [200]                                                 │
 * │ Length: 1                                                       │
 * │ maxLength = 4 (unchanged)                                       │
 * └─────────────────────────────────────────────────────────────────┘
 * 
 * ANSWER: 4 ✓
 * 
 * ════════════════════════════════════════════════════════════════════
 * WHY O(n) TIME COMPLEXITY?
 * ════════════════════════════════════════════════════════════════════
 * 
 * Might seem O(n²) because of nested loops, but:
 * 
 * Outer loop: Visits each number once → O(n)
 * Inner while loop: Only runs for sequence STARTS
 * 
 * Example: For sequence [1,2,3,4]
 *   - num=1: Inner loop runs 3 times (checks 2,3,4)
 *   - num=2: SKIPPED (not a start)
 *   - num=3: SKIPPED (not a start)
 *   - num=4: SKIPPED (not a start)
 * 
 * Total inner loop iterations = 3 (not 3+2+1+0 = 6)
 * 
 * Each number appears in inner loop at most ONCE across ALL iterations
 * Total operations = O(n) + O(n) = O(n) ✓
 * 
 * ════════════════════════════════════════════════════════════════════
 */




//Approach 2 : Sorting (O(n log n)) and then counting consecutive sequences
// TC : O(n log n) due to sorting, SC : O(1) or O(N) depending on sorting algorithm
//Streak becomes zero when we encounter a gap (non-consecutive number) or a duplicate
int longestConsecutive(vector<int>& nums) {
    if (nums.empty()) return 0;
    sort(nums.begin(), nums.end());

    int res = 0, curr = nums[0], streak = 0, i = 0;

    while (i < nums.size()) {
        if (curr != nums[i]) {
            curr = nums[i];
            streak = 0;
        }
        while (i < nums.size() && nums[i] == curr) {
            i++;
        }
        streak++;
        curr++;
        res = max(res, streak);
    }
    return res;
}


//Approach 3 : Brute Force (O(n^2)) - Check each number and count how many consecutive numbers follow it
// TC : O(n^2), SC : O(1)
int longestConsecutive(vector<int>& nums) {
    int res = 0;
    unordered_set<int> store(nums.begin(), nums.end());

    for (int num : nums) {
        int streak = 0, curr = num;
        while (store.find(curr) != store.end()) {
            streak++;
            curr++;
        }
        res = max(res, streak);
    }
    return res;
}