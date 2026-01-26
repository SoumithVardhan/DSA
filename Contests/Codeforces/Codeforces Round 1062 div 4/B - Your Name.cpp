#include <iostream>
#include <string>
using namespace std;
 
int main() {
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        string a,b;
        cin>>a>>b;
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        if(a==b){
            cout<<"Yes"<<endl;
        }else{
            cout<<"No"<<endl;
        }
    }
}