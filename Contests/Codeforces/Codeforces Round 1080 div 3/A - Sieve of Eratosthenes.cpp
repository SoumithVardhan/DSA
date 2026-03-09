#include <iostream>
using namespace std;
 
int main() {
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        bool flag1=false;
        while(n--){
            int a;cin>>a;
            if(a==67)flag1=true;
        }
        if(flag1)cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
}