#include <iostream>
using namespace std;
 
int main() {
	int t;cin>>t;
	while(t--){
        int n;cin>>n;
        vector<int>v(2*n);
        for(int i=0;i<2*n;i++){
            cin>>v[i];
        }
        unordered_map<int,int>mp;
        for(int i=0;i<2*n;i++){
            mp[v[i]]++;
        }
        int cntodd=0,ans=0,cnt=0;
        for(auto it:mp){
            if(it.second%2!=0){
                ans++;
                cntodd++;
            }
            else{
                int freqcnt=it.second/2;
                if(freqcnt%2!=0){
                    ans+=2;
                }else{
                    cnt++;
                }
            }
        }
        if(cntodd<2){
            cout<<ans + 2 * (cnt - cnt%2) <<endl;
        }
        else{
            cout<<ans + 2 * (cnt) <<endl;
        }
	}
}