#include <iostream>
#include <vector>
using namespace std;
 
int main() {
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<int>v(n);
        int maxi=0;
        for(int i=0;i<n;i++){
            int a;
            cin>>v[i];
            a=v[i];
            maxi=max(a,maxi);
        }cout<<maxi*n<<endl;
    }
 
    return 0;
}