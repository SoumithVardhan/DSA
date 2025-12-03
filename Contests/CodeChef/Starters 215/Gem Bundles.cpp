#include <iostream>
using namespace std;

int main() {
	int n;cin>>n;
	while(n--){
	    int a,b,c;cin>>a>>b>>c;
	    int ans=0;
	    while(a!=0 && b!=0 && c!=0){
	        ans+=10;
	        a--;
	        b--;
	        c--;
	    }
	    while(a!=0){
	        ans+=3;
	        a--;
	    }
	    while(b!=0){
	        ans+=3;
	        b--;
	    }
	    while(c!=0){
	        ans+=3;
	        c--;
	    }cout<<ans<<endl;
	}
}
