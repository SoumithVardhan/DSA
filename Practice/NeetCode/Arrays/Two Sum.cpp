#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        unordered_map<int,int>um;
        for(int i=0;i<n;i++){
            int diff=target-nums[i];
            if(um.find(diff)!=um.end())return{um[diff],i};
            um.insert({nums[i],i});
        }return {};
    }
};
