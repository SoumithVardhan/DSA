#include <iostream>
#include <vector>
using namespace std;

//Approach 1 : Better than O(N^2)
//TIME COMPLEXITY: O(N)
//SPACE COMPLEXITY: O(N)
class Solution {
public:
    // Variant 1
    string twoSumExists(vector<int>& arr, int target) {
        unordered_map<int, int> mp;
        for (int i = 0; i < arr.size(); i++) {
            int need = target - arr[i];
            if (mp.find(need) != mp.end())
                return "YES";
            mp[arr[i]] = i;
        }
        return "NO";
    }

    // Variant 2
    vector<int> twoSumIndices(vector<int>& arr, int target) {
        unordered_map<int, int> mp;
        for (int i = 0; i < arr.size(); i++) {
            int need = target - arr[i];
            if (mp.find(need) != mp.end())
                return {mp[need], i};
            mp[arr[i]] = i;
        }
        return {-1, -1};
    }
};

// Approach 3 : Two Pointer
// TIME COMPLEXITY: O(N log N) due to sorting
// SPACE COMPLEXITY: O(1), but if we need original indices, then O(N) to store pairs before sorting
class Solution {
public:
    // Variant 1 — Two pointer works perfectly
    string twoSumExists(vector<int> arr, int target) {
        sort(arr.begin(), arr.end());
        int left = 0, right = arr.size() - 1;
        while (left < right) {
            int sum = arr[left] + arr[right];
            if (sum == target)      return "YES";
            else if (sum < target)  left++;
            else                    right--;
        }
        return "NO";
    }

    // Variant 2 — Must store original indices before sorting
    vector<int> twoSumIndices(vector<int> arr, int target) {
        int n = arr.size();
        vector<pair<int,int>> sorted;
        for (int i = 0; i < n; i++)
            sorted.push_back({arr[i], i});
        
        sort(sorted.begin(), sorted.end());

        int left = 0, right = n - 1;
        while (left < right) {
            int sum = sorted[left].first + sorted[right].first;
            if (sum == target)
                return {sorted[left].second, sorted[right].second};
            else if (sum < target)  left++;
            else                    right--;
        }
        return {-1, -1};
    }
};