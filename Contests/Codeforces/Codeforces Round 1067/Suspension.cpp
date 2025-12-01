#include <iostream>
using namespace std;
 
int main() {
	int t;cin>>t;
	while(t--){
        int n;cin>>n;
        int a,b;
        cin>>a>>b;
        int ans=a/2+b;
        cout<<min(n,ans)<<endl;
	}
}