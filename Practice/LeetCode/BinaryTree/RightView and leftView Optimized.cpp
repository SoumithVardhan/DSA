/*
    link: https://takeuforward.org/data-structure/right-left-view-of-binary-tree/
*/
#include <iostream>
#include <vector>
typedef long long ll;
using namespace std;
 
vector<vector<int>>vec;
vector<ll>res;
void dfs(int curr,int parent){
  if(vec[curr].size()==1 && vec[curr][0]==parent){
    res[curr]=1;
  }
  else{
    for(int i=0;i<vec[curr].size();i++){
      if(vec[curr][i]!=parent){
        dfs(vec[curr][i],curr);
        res[curr]+=res[vec[curr][i]];
      }
    }
  }
}
void solve(){
  int n;cin>>n;
  vec.assign(n, {});
  res.assign(n, 0);
  for(int i=0;i<n-1;i++){
    int u,v;
    cin>>u>>v;
    u--;v--;
    vec[u].push_back(v);
    vec[v].push_back(u);
  }
  dfs(0,-1);
  int appletobecount;cin>>appletobecount;
  for(int i=0;i<appletobecount;i++){
    int a,b;
    cin>>a>>b;
    a--;b--;
    ll ans=res[a]*res[b];
    cout<<ans<<endl;
  }
}
int main() 
{
  int t;cin>>t;
  while(t--){
    solve();
  }
}