#include <iostream>
using namespace std;
 
int main() {
	int t;cin>>t;
	while(t--){
	    int n,m;cin>>n>>m;
	    int px=0,py=0;
	    int points=0;
	    while(n--){
	        int x,y;cin>>x>>y;
	        points+=x-px;
	        
	        if(((x-px+2)%2) != (y-py+2)%2)
	            points--;
	       px=x;
	       py=y;
	    }
	    if(px!=m)
	    points+=m-px;
	    cout<<points<<endl;
	}
}