#include <iostream>
#include <vector>
using namespace std;
 
int main() {
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<int>v(n);
        int cntodd=0,cnteven=0;
        for(int i=0;i<n;i++){
            cin>>v[i];
            if(v[i]%2==0){
                cnteven++;
            }else{
                cntodd++;
            }
        }
        if(cnteven && cntodd){
            sort(v.begin(),v.end());
        }
        for(int i=0;i<n;i++){
            cout<<v[i]<<" ";
        }cout<<endl;
    }
}