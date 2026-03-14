#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans = "";

        while(columnNumber > 0) {
            int rem = columnNumber % 26;
            if(rem == 0) {
                ans += 'Z';
                columnNumber = columnNumber / 26 - 1;
            } else {
                ans += (char)('A' + rem - 1);
                columnNumber = columnNumber / 26;
            }
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};