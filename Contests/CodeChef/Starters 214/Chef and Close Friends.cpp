#include <iostream>
using namespace std;

int main() {
	int t;cin>>t;
	while(t--){
        int x,y,z;cin>>x>>y>>z;
        int reqrangex1=x-z;
        int reqrangex2=x+z;
        
        int friendrangex1=x-y;
        int friendrangex2=x+y;
        
        int ans1=reqrangex2-reqrangex1;
        int ans2=friendrangex2-friendrangex1;
        
        if(ans1>ans2){
            cout<<ans2<< endl;
        }else{
            cout<<ans1<<endl;
        
	    }
	}
}
