#include<iostream>
#include<vector>
#include <climits>
using namespace std;

//string i/p
int solve(string s){   
    if(s=="0") return 0;
    int ans=INT_MAX;
    for(int i=0;i<s.size();i++){
        if(s[i]=='0') continue;
        int num=stoi(s);
        int desirednum=num-(s[i]-'0');
        ans=min(ans,1+solve(to_string(desirednum)));
    }
    return ans;
}

//integer i/p
int solve(int n){   
    if(n == 0) return 0;
    int ans = INT_MAX;
    int temp = n;
    while(temp > 0){
        int digit = temp % 10;
        if(digit != 0){
            ans = min(ans, 1 + solve(n - digit));
        }
        temp /= 10;
    }
    return ans;
}

//string i/p
int solvememo(string s,vector<int>&dp){   
    if(s=="0") return 0;
    if(dp[stoi(s)]!=-1) return dp[stoi(s)];
    int ans=INT_MAX;
    for(int i=0;i<s.size();i++){
        if(s[i]=='0') continue;
        int num=stoi(s);
        int desirednum=num-(s[i]-'0');
        ans=min(ans,1+solvememo(to_string(desirednum),dp));
    }
    dp[stoi(s)]=ans;
    return ans;
}

//integer i/p
int solvememo(int n, vector<int>& dp){   
    if(n == 0) return 0;
    if(dp[n] != -1) return dp[n];
    
    int ans = INT_MAX;
    int temp = n;
    while(temp > 0){
        int digit = temp % 10;
        if(digit != 0){
            ans = min(ans, 1 + solvememo(n - digit, dp));
        }
        temp /= 10;
    }
    
    dp[n] = ans;
    return ans;
}


int solvetab(int n){
    vector<int> dp(n+1,INT_MAX);
    dp[0]=0;

    for(int i=1;i<=n;i++){
        int temp=i; 
        while(temp>0){
            int digit=temp % 10; 
            if(digit!=0){
                dp[i]=min(dp[i],1+dp[i-digit]);
            }
            temp /= 10;
        }
    }
    return dp[n];
}

int main(){
    // string n;
    // cin>>n;

    int n;cin>>n;
    //recursive approach
    
    //string i/p
    // int ans=solve(n);

    //integer i/p
    // int ans=solve(n);
    // cout<<ans<<endl;

    //memoization approach
    //string i/p
    // int num=stoi(n);
    // vector<int> dp(num+1,-1);
    // int ansmemo=solvememo(n,dp);

    //integer i/p
    // vector<int>dp(n+1,-1);
    // int ansmemo=solvememo(n,dp);
    // cout<<ansmemo<<endl;

    //tabulation approach
    cout<<solvetab(n)<<endl;
    return 0;
}

