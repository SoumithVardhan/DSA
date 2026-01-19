#include <iostream>
using namespace std;
 
int main() {
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        int cnt=0;
        for(int i=2;;i++){
            cnt++;
            cout<<i*i<<" ";
            if(cnt==n)break;
        }cout<<endl;
    }
 
    return 0;
}
