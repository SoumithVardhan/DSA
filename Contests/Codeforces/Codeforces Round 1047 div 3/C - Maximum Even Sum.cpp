#include <iostream>
using namespace std;
 
int main() {
	int t;cin>>t;
	while(t--){
	    long long a,b;cin>>a>>b;
	    long long ans=b;
	    long long maxi=-1;
	    while(ans>0){
	        if(b%ans==0){
                long long res=(a*ans)+(b/ans);
                // cout<<res<<" ";
    	        if(res%2==0){
    	            maxi=max(maxi,res);
    	        }
	        }
	        ans/=2;
	    }
        cout<<maxi<<endl;   
	}
}