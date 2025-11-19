#include <iostream>
using namespace std;

int main() {
	int n;cin>>n;
	while(n--){
	    int t;cin>>t;
	    int maxi=0;
	    int index=0;
	    int prevmax=0;
	    for(int i=0;i<t;i++){
	        int d,t;cin>>d>>t;
	        maxi=max(d/t,maxi);
	        if(maxi>prevmax){
	            prevmax=maxi;
	            index=i+1;
	        }
	    }cout<<index<<endl;
	}
}
