
#include<iostream>
using namespace std;
 
int main() {
	int t;cin>>t;
	while(t--){
	    long long k,x;cin>>k>>x;
	    long long ans=x;
	    while(k--){
	        ans*=2;
	    }
	    cout<<ans<<endl;
	}
}