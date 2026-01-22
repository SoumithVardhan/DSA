#include<iostream>
typedef long long ll;
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        ll s,k,m;cin>>s>>k>>m;
        if(s<k){
            cout<<s-min(m%k,s)<<endl;
        }
        else{
            if((m/k)%2==0){
                cout<<s-(m%k)<<endl;
            }
            else{
                cout<<(k-(m%k))<<endl;
            }
        }
    }
    return 0;
}