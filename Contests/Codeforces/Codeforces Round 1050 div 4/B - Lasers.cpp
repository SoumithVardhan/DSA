#include <iostream>
using namespace std;
 
int main() {
	int t;cin>>t;
	while(t--){
	    int n,m,x,y;
	    cin>>n>>m>>x>>y;
	    int cnt=0;
	    for(int i=0;i<n;i++){
	        int a;
	        cin>>a;
	        if(a<=y && a>=0)cnt++;
	    }
	    for(int i=0;i<m;i++){
	        int b;
	        cin>>b;
	        if(b<=x && b>=0)cnt++;
	    }
	    cout<<cnt<<endl;
	}
	return 0;
}