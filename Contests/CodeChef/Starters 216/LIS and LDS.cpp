#include<bits/stdc++.h>
using namespace std;
int main(){
    
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<int>v(n);
        for(int i=0;i<n;i++){
            cin>>v[i];
        }
        int cnt=0,cntone=0;
        for(int i=0;i<n;i++){
            if(v[i]>1)cnt++;
            else cntone++;
        }
        cout<<(cnt+(cntone+1)/2)<<endl;
        // if(cntone%2==0){
        //     cout<<cnt+cntone/2<<endl;
        // }
        // else{
        //     cout<<cnt<<endl;   
        // }
    }
    return 0;
}