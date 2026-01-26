#include <iostream>
using namespace std;
 
int main() {
    int t;cin>>t;
    while(t--){
        int a,b,c,d;cin>>a>>b>>c>>d;
        if(a==b && a==c && a==d){
            cout<<"Yes"<<endl;
        }else{
            cout<<"No"<<endl;
        }
    }
}