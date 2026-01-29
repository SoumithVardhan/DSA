#include <iostream>
#include <vector>
using namespace std;
 
int main() {
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<int>v(n);
        int cntminusones=0;
        int cntzero=0;
        for(int i=0;i<n;i++){
            cin>>v[i];
            if(v[i]==0)cntzero++;
            if(v[i]==-1)cntminusones++;
        }
        
        if(cntminusones%2!=0){
            cout<<cntzero+2<<endl;
        }
        else{
            cout<<cntzero<<endl;
        }
        
    }
 
}