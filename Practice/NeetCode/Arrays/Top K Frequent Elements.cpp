#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
using namespace std;

class Solution {
public:

    //Approach 1: Using a vector of pairs to store frequency and element, then sorting it
    //TC: O(N) for counting frequencies + O(N log N) for sorting = O(N log N)
    //SC: O(N) for the frequency map and the vector of pairs
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        for (int num : nums) {
            count[num]++;
        }

        vector<pair<int, int>> arr;
        for (const auto& p : count) {
            arr.push_back({p.second, p.first});
        }
        sort(arr.rbegin(), arr.rend());

        vector<int> res;
        for (int i = 0; i < k; ++i) {
            res.push_back(arr[i].second);
        }
        return res;
    }

    //Approach 2: Using a min-heap (priority queue) to keep track of top k elements
    //TC: O(N) for counting frequencies + O(N log k) for maintaining the heap = O(N log k)
    //SC: O(N) for the frequency map + O(k) for the heap = O(N) in worst case when k is close to N          
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        for (int num : nums) {
            count[num]++;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;
        for (auto& entry : count) {
            heap.push({entry.second, entry.first});
            if (heap.size() > k) {
                heap.pop();
            }
        }

        vector<int> res;
        for (int i = 0; i < k; i++) {
            res.push_back(heap.top().second);
            heap.pop();
        }
        return res;
    }
};
