#include <iostream>
#include <string>  
using namespace std;
 
int main() {
	int t;cin>>t;
	while(t--){
	    int initialstringnum;cin>>initialstringnum;
	    string initialstring;cin>>initialstring;
	    int tobeadded;cin>>tobeadded;
	    string tobeadd;cin>>tobeadd;
	    string pos;cin>>pos;
	    
	    for(int i=0;i<pos.size();i++){
	        if(pos[i]=='D'){
	            initialstring+=tobeadd[i];
	        }
	        else{
	            initialstring=tobeadd[i]+initialstring;
	        }
	    }
	    cout<<initialstring<<endl;
	}
}
