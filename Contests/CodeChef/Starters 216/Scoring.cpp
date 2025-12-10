#include<bits/stdc++.h>
using namespace std;
int main(){
    
    int t;cin>>t;
    while(t--){
        int x,y;cin>>x>>y;
        
        int b=(y-x)/2;
        int a=b+x;
        cout<<a<<" "<<b<<endl;
    }
    return 0;
}