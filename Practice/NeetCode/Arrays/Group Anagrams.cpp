#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;    

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>um;
        for(auto& s: strs){
            string ans=s;
            sort(ans.begin(),ans.end());
            um[ans].push_back(s);
        }
        vector<vector<string>>res;
        for(auto& pair:um){
            res.push_back(pair.second);
        }return res;
    }
};
