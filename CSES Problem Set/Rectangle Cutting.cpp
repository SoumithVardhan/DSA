#include<iostream>
#include<vector>
#include <climits>
using namespace std;

int solverec(int m,int n){
    if(m==n)return 0;
    int ans=INT_MAX,ans2=INT_MAX,finalres=INT_MAX;
    for(int i=1;i<m;i++){
        ans=min((1+solverec(m-i,n)+solverec(i,n)),ans);
    }
    for(int i=1;i<n;i++){
        ans2=min((1+solverec(m,n-i)+solverec(m,i)),ans2);
    }
    return finalres=min(ans,ans2);
}

int solvememo(int m,int n,vector<vector<int> >&dp){
    if(m==n)return 0;
    if(dp[m][n]!=-1)return dp[m][n];
    int ans=INT_MAX;
    for(int i=1;i<m;i++){
        ans=min(1+solvememo(m-i,n,dp)+solvememo(i,n,dp),ans);
    }
    for(int i=1;i<n;i++){
        ans=min(1+solvememo(m,n-i,dp)+solvememo(m,i,dp),ans);
    }
    return dp[m][n]=ans;
}

//m=3 n=5
int solvetab(int m,int n){
    vector<vector<int> >dp(m+1,vector<int>(n+1,0));
    for(int i=1; i<=m; i++){        // i = rectangle HEIGHT (1, 2, 3)
        for(int j=1; j<=n; j++){    // j = rectangle WIDTH (1, 2, 3, 4, 5)
            if(i==j){
                dp[i][j]=0;
                continue;
            }
            
            int ans = INT_MAX;
            
            //For every i and j you should try out all the cuts possible to get the min
            
            // Try horizontal cuts on THIS i×j rectangle
            for(int k=1; k<i; k++){  // k = CUT POSITION (1, 2, ..., i-1)
                ans = min(ans, 1 + dp[k][j] + dp[i-k][j]);
            }
            
            // Try vertical cuts on THIS i×j rectangle
            for(int k=1; k<j; k++){  // k = CUT POSITION (1, 2, ..., j-1)
                ans = min(ans, 1 + dp[i][k] + dp[i][j-k]);
            }
            
            dp[i][j] = ans;
        }
    }return dp[m][n];
}

int main(){
    int m,n;cin>>m>>n; 
    vector<vector<int> >dp(m+1,vector<int>(n+1,-1));

    // int result=solverec(m,n);
    // int result=solvememo(m,n,dp);
    int result=solvetab(m,n);
    if(result!=INT_MAX){
        cout<<result<<endl;
    }
    else{
        cout<<-1<<endl;
    }
    return 0;
}

