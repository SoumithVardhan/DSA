#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int t;cin>>t;
    while (t--)
    {
        int n,q;cin>>n>>q;
        vector<int>v1(n);
        for(int i=0;i<n;i++){
            cin>>v1[i];
        }
        vector<int>v2(n);
        for(int i=0;i<n;i++){
            cin>>v2[i];
        }
        for(int j=n-1;j>=0;j--){
            v1[j]=max(v1[j],v2[j]);
        }
        for(int j=n-2;j>=0;j--){
            v1[j]=max(v1[j+1],v1[j]);
        }
        vector<long long> prefix(n+1,0);
        for(int i=0;i<n;i++){
            prefix[i+1]=prefix[i]+v1[i];
        }
        while(q--){
            int l,r;
            cin>>l>>r;
            long long sum =prefix[r]-prefix[l - 1];
            cout<<sum<< " ";
        }
        cout << endl;

    }
    return 0;
}