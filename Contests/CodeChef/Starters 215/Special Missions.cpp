#include <iostream> 
#include <vector>
using namespace std;

int main() {
	int num;cin>>num;
	while(num--){
	    int n,c;cin>>n>>c;
	    int ans=0;
	    int cnt=0;
	    bool flag=false;
	    vector<int>v1(n);
	    vector<char>v2(n);
	    for(int i=0;i<n;i++){
	        int a;cin>>a;
	        v1[i]=a;
	    }
	    string s;
	    cin>>s;
	    for(int i=0;i<s.size();i++){
	        v2[i]=(s[i]-'0');
	    }
	    for(int i=0;i<n;i++){
	        if(v2[i]==0)ans+=v1[i];
	    }
	    for(int i=0;i<n;i++){
	        if(v2[i]==1)cnt+=v1[i];
	        if(v2[i]==1 && ans>=c){
	            flag=true;
	        }
	    }
	    
	    if(flag){
	        cout<<max(ans+cnt-c,ans)<<endl;
	    }else{
	        cout<<ans<<endl;
	    }
	}
}