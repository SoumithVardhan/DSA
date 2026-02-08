#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        if(g.size()==0 || s.size()==0)return 0;
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int ans=0;
        int i=g.size()-1;
        int j=s.size()-1;
        while(i>=0 && j>=0){
            if(s[j]>=g[i]){
                ans++;
                i--;
                j--;
            }
            else{
                i--;
            }
        }
        return ans;
    }
};
