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
	        cin>>v[i];
	        maxi=max(maxi,v[i]);
	    }
	    int finalnum=maxi+1;
	    for(int i=0;i<n;i++){
	        cout<<finalnum-v[i]<<" ";
	    }cout<<endl;
	}
}
