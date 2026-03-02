#include <iostream>
#include <vector>
using namespace std;


class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        vector<int>ans(V,1e8);
        ans[src]=0;
        for(int i=1;i<=V-1;i++){
            for(auto& it:edges){
                int u=it[0];
                int v=it[1];
                int wt=it[2];
                if(ans[u]!=1e8 && ans[u]+wt<ans[v]){
                    ans[v]=ans[u]+wt;
                }
            }
        }
        //negative cycle detection
        for(auto& it:edges){
            int u=it[0];
                int v=it[1];
                int wt=it[2];
                if(ans[u]!=1e8 && ans[u]+wt<ans[v]){
                    return {-1};
                }
        }
        return ans;
    }
};
