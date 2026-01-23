#include<iostream>
#include<vector>
typedef long long ll;
const int mod=1000000007;
using namespace std;


// Recursive approach
int solverec(int remsum){
    if(remsum<0) return 0;
    if(remsum==0) return 1;
    int sum=0;
    for(int i=1;i<=6;i++){
        sum=(sum+solverec(remsum-i))%mod;
    }
    return sum%mod;
}
int main(){
    int n;
    cin>>n;
    int remsum=n;
    cout<<solverec(remsum)<<endl;
    return 0;
}

//Memoization approach
int solvememo(int remsum, vector<int>&dp){
    if(remsum<0) return 0;
    if(remsum==0) return 1;
    if(dp[remsum]!=0) return dp[remsum];
    int sum=0;
    for(int i=1;i<=6;i++){
        sum=(sum+solvememo(remsum-i,dp))%mod;
    }
    return dp[remsum]=sum%mod;
}
int main(){
    int n;
    cin>>n;
    int remsum=n;
    vector<int>dp(n+1);
    cout<<solvememo(remsum,dp)<<endl;
    return 0;
}

//Tabulation approach
int solvetab(int n){
    vector<int>dp(n+1);
    dp[0]=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=6;j++){
            if(i>=j){
                dp[i]=(dp[i]+dp[i-j]) %mod;
            }
        }
    }
    return dp[n];
}
int main(){
    int n;
    cin>>n;
    cout<<solvetab(n)<<endl;
    return 0;
}