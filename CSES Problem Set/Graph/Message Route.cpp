#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

vector<int> solve(vector<vector<int> >&ngb,int n,int m){
    vector<bool>visited(n+1,false);
    queue<int>q;
    q.push(1);
    visited[1]=true;
    vector<int>parent(n+1,-1);
    while(!q.empty()){
        int front=q.front();
        q.pop();
        if(front == n) break; 
        vector<int> num=ngb[front];
        for(int i=0;i<num.size();i++){
            if(visited[num[i]]==true)continue;
            parent[num[i]]=front;
            q.push(num[i]);
            visited[num[i]]=true;
        }
    }

    if(!visited[n]){
        return vector<int>(); 
    }
    vector<int>res;
    int curr=n;
    while(curr!=1){
        res.push_back(curr);
        curr = parent[curr];
    }
    res.push_back(1);
    reverse(res.begin(), res.end()); 
    return res;
}
int main(){

    int n,m;cin>>n>>m;
    // The adjacency list only stores actual edges, not all possible pairs.
    // Each of the M edges is stored exactly twice (once for each endpoint)
    // So total space = N (for the N lists) + 2M (for the edge entries) = O(N+M).
    vector<vector<int> >v(n+1);
    for(int i=0;i<m;i++){
        int a,b;cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    vector<int>ans=solve(v,n,m);
    if(ans.size() == 0){
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    cout<<ans.size()<<endl;
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i];
        if(i != ans.size() - 1) cout << " ";
    }
    return 0;
}