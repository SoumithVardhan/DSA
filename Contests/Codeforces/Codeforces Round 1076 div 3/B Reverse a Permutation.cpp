#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int t;cin>>t;
    while (t--)
    {
        int n;cin>>n;
        vector<int>v(n);
        for(int i=0;i<n;i++){
            cin>>v[i];
        }
        vector<int>prefix(n);
        prefix[n-1]=v[n-1];
        for(int i=n-2;i>=0;i--){
            prefix[i]=max(prefix[i+1],v[i]);
        }
        int i=0;
        while(i<n && v[i]==prefix[i]){
            i++;
        }
        if(i==n){
            for(int k=0;k<n;k++){
                cout<<v[k];
                if(k!=n-1) cout<<" ";
            }cout<<endl;
            continue;
        }
        int maxi=prefix[i];
        int curridx=i;
        int targetidx=-1;
        for(i=0;i<n;i++){
            if(v[i]==maxi){
                targetidx=i;
                break;
            }
        }
        reverse(v.begin()+curridx,v.begin()+targetidx+1);
        for(int k=0;k<n;k++){
            cout<<v[k];
            if(k!=n-1) cout<<" ";
        }cout<<endl;
    }
    return 0;
}