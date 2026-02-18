#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int t;cin>>t;
    while (t--)
    {
        int n,s,x;
        cin>>n>>s>>x;
        vector<int>v(n);
        int sum=0;
        for(int i=0;i<n;i++){
            cin>>v[i];  
            sum+=v[i];
        }
        int currsum=sum;
        while(currsum<s){
            currsum+=x;
        }
        if(currsum==s){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}