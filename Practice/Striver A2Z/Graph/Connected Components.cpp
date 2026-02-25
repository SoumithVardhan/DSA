#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
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

    int findNumberOfComponent(int V, vector<vector<int>> &edges) {

      int n=V;
      vector<int>adjlist[n];

      for(int i = 0; i < edges.size(); i++){
          int u = edges[i][0];
          int v = edges[i][1];
          adjlist[u].push_back(v);
          adjlist[v].push_back(u); 
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