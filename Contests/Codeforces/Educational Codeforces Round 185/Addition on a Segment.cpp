#include <iostream>
#include <vector>
using namespace std;
 
int main() {
	int t;cin>>t;
	while(t--){
        int n;cin>>n;
        vector<int>arr(n);
        int cntzero=0;
        long long sum=0;
        for(int i=0;i<n;i++){
            int a;
            cin>>a;
            if(a==0)cntzero++;
            sum+=a;
        }
        cout<< min((long long)n-cntzero,sum-(n-1))<<'\n'<<endl;
	}
    return 0;
}
