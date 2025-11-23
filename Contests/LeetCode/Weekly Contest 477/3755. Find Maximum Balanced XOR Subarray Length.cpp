#include <iostream>
#include <map>
#include <vector>
#include <unordered_map>
#include <map>
#include <utility>
using namespace std;

// Approach 1: Using Hashmap
class Solution {
public:
    int maxBalancedSubarray(vector<int>& nums) {
        long long ans=0;
        int odd=0,even=0;
        int maxlen=0;
        unordered_map<long long,unordered_map<int,int>>mp;
        mp[0][0]=-1;
        for(int i=0;i<nums.size();i++){
            ans^=nums[i];
            if(nums[i]%2==0)even++;
            else odd++;
            int del=odd-even;
            if(mp[ans].count(del)){
                maxlen=max(maxlen,i-mp[ans][del]);
            }else{
                mp[ans][del]=i;
            }
        }return maxlen;
    }
};

// Approach 2: Using Map with pair as key
class Solution {
public:
    int maxBalancedSubarray(vector<int>& nums) {
        int maxlen = 0;
        long long xorVal = 0;
        int diff = 0;  // odd_count - even_count
        
        // Store {XOR, difference} → first index
        map<pair<long long, int>, int> mp;
        mp[{0, 0}] = -1;  // Starting condition
        
        for(int i = 0; i < nums.size(); i++) {
            // Update XOR
            xorVal ^= nums[i];
            
            // Update difference
            if(nums[i] % 2 == 0) {
                diff--;  // Even number, difference decreases
            } else {
                diff++;  // Odd number, difference increases
            }
            
            // Create the key
            auto key = make_pair(xorVal, diff);
            
            // Have we seen this {XOR, diff} before?
            if(mp.count(key)) {
                // Yes! Found a valid subarray
                maxlen = max(maxlen, i - mp[key]);
            } else {
                // No! Store it for first time
                mp[key] = i;
            }
        }
        
        return maxlen;
    }
};