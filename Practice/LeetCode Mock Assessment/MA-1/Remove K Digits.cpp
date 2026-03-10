#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
    // Monotonic Stack Approach
    string removeKdigits(string num, int k) {
        stack<int>s;
        for(int i = 0; i < num.size(); i++) {
            int digit = num[i] - '0';
            while(k > 0 && !s.empty() && s.top() > digit) {
                s.pop();
                k--;
            }
            s.push(digit);
        }
        while(k--) s.pop();
        string ans="";
        while(!s.empty()){
            ans+=to_string(s.top());
            s.pop();
        }
        reverse(ans.begin(), ans.end());
        
        int start = 0;
        while(start < (int)ans.size() - 1 && ans[start] == '0') start++;
        
        
        return ans.empty() ? "0" : ans.substr(start);
    }
};