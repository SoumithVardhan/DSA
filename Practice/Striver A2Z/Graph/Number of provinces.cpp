#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution{
public:
    void bfs(vector<int> adjlist[],int n,int ind,vector<bool> &visited){
        queue<int>q;
        visited[ind]=true;
        q.push(ind);
        while(!q.empty()){
            int frontele=q.front();
            q.pop();
            for(int i=0;i<adjlist[frontele].size();i++){
                int ngb= adjlist[frontele][i];
                if(!visited[ngb]){
                    visited[ngb] = true;
                    q.push(ngb);
                }
            }
        }
    }

    int numProvinces(vector<vector<int>> adj) {
        int n=adj.size();
        vector<int>adjlist[n];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if( i!=j && adj[i][j]==1){
                    adjlist[i].push_back(j);
                }
            }
        }

        vector<bool>visited(n,false);
        int cnt=0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                cnt++;
                bfs(adjlist,n,i,visited);
            }
        }
        return cnt;
    }
};
