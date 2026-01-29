#include <iostream>
#include <vector>
using namespace std;
 
int main() {
	int t;cin>>t;
	while(t--){
	    int n;cin>>n;
	    vector<int>v(n);
	    bool flag=false;
	    int cnt=0;
	    for(int i=0;i<n;i++){
	        cin>>v[i];
	        if(v[i]%2!=0){flag=true;cnt++;}
	    }
	    sort(v.begin(),v.end());
	    if(flag==false){
	        cout<<0<<endl;
	        continue;
	    }
	    long long ans=0;
	    int totalconsider=(cnt+1)/2;
	    for(int i=n-1;i>=0;i--){
	        if(v[i]%2==0){
	            ans+=v[i];
	        }
	        else if(v[i]%2!=0 && totalconsider>0){
	            ans+=v[i];
	            totalconsider--;
	        }
	    }
	    cout<<ans<<endl;
	}
	return 0;
}