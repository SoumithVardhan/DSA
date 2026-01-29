#include <iostream>
#include <vector>
using namespace std;
 
int main() {
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<int>v(n);
        for(int i=0;i<n;i++){
            cin>>v[i];
        }
        int maxi=0;
        sort(v.begin(),v.end());
        for(int i=1;i<n;i+=2){
            maxi=max(maxi,(v[i]-v[i-1]));
        }
        cout<<maxi<<endl;
    }
    return 0;
}