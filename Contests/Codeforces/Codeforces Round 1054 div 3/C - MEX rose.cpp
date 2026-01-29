#include <iostream>
#include <vector>
using namespace std;
 
int main() {
    int t;cin>>t;
    while(t--){
        int n,k;cin>>n>>k;
        vector<int>v(n);
        for(int i=0;i<n;i++){
            cin>>v[i];
        }
        int cntequal=0,cntless=0;
        sort(v.begin(),v.end());
        vector<int>count(k+1);
        for(int i=0;i<n;i++){
            if(v[i]<=k)
                count[v[i]]++;
        }
        int ans=0;
        for(int i=0;i<count.size()-1;i++){
            if(count[i]==0)ans++;
        }
        if(ans!=0 && count[k]!=0 && count[k]>=ans){
            count[k]-=ans;
        }
        else if(ans!=0 && count[k]!=0 && ans>=count[k]){
            ans-=count[k];
        }
        cout<<ans+count[k]<<endl;
    }
    return 0;
}