#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Approach 1: Greedy with Disjoint Set Union (DSU) - Optimized Slot Finding
// 
// PROBLEM: Need to schedule jobs in available time slots to maximize profit.
// Each job takes 1 unit time and must be completed by its deadline.
//
// STRATEGY:
// 1. GREEDY: Sort jobs by profit (descending) - do most profitable jobs first
// 2. SCHEDULING: Try to schedule each job as LATE as possible (but before deadline)
//    This leaves earlier slots free for other jobs
// 3. OPTIMIZATION: Use DSU to find the next available slot in nearly O(1) time
//
// WHY DSU? Without DSU, finding free slots takes O(M) time per job (scanning slots).
// With DSU + path compression, it becomes O(α(M)) ≈ O(1) amortized.
//
// HOW DSU WORKS HERE:
// - parent[i] = i means "slot i is FREE, use me!"
// - parent[i] = i-1 means "slot i is OCCUPIED, next free slot is at parent[i]"
// - When we find a free slot k, we do: parent[k] = k-1 (mark as occupied)
// - Path compression: After finding free slot, all searched slots directly point to it
//
// EXAMPLE:
// parent = [0,1,2,3,4] → all slots free
// Schedule job at slot 3 → parent[3] = 2
// findParent(3) now returns 2 (next free slot)
// After path compression: findParent(4)→findParent(3) both return 2 in O(1)
//
// TIME COMPLEXITY:
// - Sorting: O(N log N) where N = number of jobs
// - DSU operations: O(N × α(M)) where M = max deadline, α = inverse Ackermann (≈ constant)
// - Total: O(N log N) - Much better than O(N²) brute force which causes TLE
// - α(M) is practically ≤ 4 for all realistic values, so it's essentially O(1) per operation
//
// SPACE COMPLEXITY: O(M) for parent array where M = max deadline
class Solution {
  public:
    int findParent(int x, vector<int>& parent){
        if(parent[x] == x) 
            return x;
        return parent[x] = findParent(parent[x], parent); // Path compression
    }
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
    int n = deadline.size();
        
        // Create pairs of (profit, deadline, index)
        vector<pair<int, int>> jobs;
        for(int i = 0; i < n; i++){
            jobs.push_back({profit[i], deadline[i]});
        }
        
        // Sort by profit in descending order
        sort(jobs.begin(), jobs.end(), greater<pair<int, int>>());
        
        // Find maximum deadline
        int maxDeadline = *max_element(deadline.begin(), deadline.end());
        
        // DSU parent array
        // parent[i] = i means slot i is free
        // parent[i] = i-1 means slot i is occupied, next free is at parent[i]
        vector<int> parent(maxDeadline + 1);
        for(int i = 0; i <= maxDeadline; i++){
            parent[i] = i;
        }
        
        int jobCount = 0;
        int totalProfit = 0;
        
        // Process each job
        for(int i = 0; i < n; i++){
            int prof = jobs[i].first;
            int dead = jobs[i].second;
            
            // Find the latest available slot <= deadline
            int availableSlot = findParent(dead, parent);
            
            if(availableSlot > 0){
                // Schedule job at availableSlot
                jobCount++;
                totalProfit += prof;
                
                // Mark this slot as occupied
                // Point to the previous slot for future searches
                parent[availableSlot] = availableSlot - 1;
            }
        }
        
        return {jobCount, totalProfit};
    }
};


class Solution {
  public:
    // Approach 2: Greedy with Sorting and Slot Allocation
    // The idea is to sort jobs based on profit in descending order.
    // Then, for each job, we try to schedule it in the latest possible slot before its deadline.
    // We maintain a slot array to keep track of occupied time slots.
    // If we find a free slot for a job, we schedule it and update the count of jobs and total profit accordingly.
    // TC: O(N * M) ~ O(N^2) where N is the number of jobs and M is the maximum deadline (in worst case, M can be equal to N).
    // TLE
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        int n = deadline.size();
        
        // Create pairs of (profit, deadline)
        vector<pair<int, int>> jobs;
        for(int i = 0; i < n; i++){
            jobs.push_back({profit[i], deadline[i]});
        }
        
        // Sort by profit in descending order (greedy: most profitable first)
        sort(jobs.begin(), jobs.end(), greater<pair<int, int>>());
        
        // Find maximum deadline to create slot array
        int maxDeadline = *max_element(deadline.begin(), deadline.end());
        
        // Slot array: -1 means free, otherwise occupied
        vector<int> slot(maxDeadline + 1, -1);
        
        int jobCount = 0;
        int totalProfit = 0;
        
        // Process each job in sorted order
        for(int i = 0; i < n; i++){
            int prof = jobs[i].first;
            int dead = jobs[i].second;
            
            // Find latest free slot before deadline
            // Try from deadline backwards to slot 1
            for(int j = dead; j >= 1; j--){
                if(slot[j] == -1){
                    slot[j] = i;  // Schedule this job
                    jobCount++;
                    totalProfit += prof;
                    break;  // Move to next job
                }
            }
        }
        
        return {jobCount, totalProfit};
    }
};