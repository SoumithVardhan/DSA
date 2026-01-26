#include<iostream>
#include<vector>
using namespace std;

const long long MOD = 1e9+7;

int solverec(vector<vector<int> >&grid,int n,int xcor,int ycor){

    if(xcor<0 || xcor>=n || ycor<0 || ycor>=n || grid[xcor][ycor]==1)return 0;
    if(xcor==n-1 && ycor==n-1)return 1;

    int totalways=solverec(grid,n,xcor+1,ycor)+solverec(grid,n,xcor,ycor+1);
    return totalways;

}
long long solvememo(vector<vector<int> >&grid,int n,int xcor,int ycor,vector<vector<long long> >&dp){

    if(xcor<0 || xcor>=n || ycor<0 || ycor>=n || grid[xcor][ycor]==1)return 0;
    if(xcor==n-1 && ycor==n-1)return 1;

    if(dp[xcor][ycor]!=-1){
        return dp[xcor][ycor];
    }
    long long totalways=0;
    long long down=solvememo(grid,n,xcor+1,ycor,dp);
    long long right=solvememo(grid,n,xcor,ycor+1,dp);
    totalways = (down+right)%MOD;
    dp[xcor][ycor]=totalways;
    return totalways;

}

int solvetab(vector<vector<int> >&grid,int n){
    if(grid[0][0] == 1 || grid[n-1][n-1] == 1) return 0;
    vector<vector<long long> >dp(n,vector<long long>(n,0));
    dp[n-1][n-1]=1;
    for(int i=n-2;i>=0;i--){
        if(grid[n-1][i]==1){
            dp[n-1][i]=0;
        }
        else{
            dp[n-1][i]=dp[n-1][i+1];
        }
    }
    for(int j=n-2;j>=0;j--){
        if(grid[j][n-1]==1){
            dp[j][n-1]=0;
        }
        else{
            dp[j][n-1]=dp[j+1][n-1];
        }
    }

    for(int i=n-2;i>=0;i--){
        for(int j=n-2;j>=0;j--){
            if(grid[i][j]==1){
                dp[i][j]=0;
            }else{
                dp[i][j]=(dp[i+1][j]+dp[i][j+1])%MOD;
            }
        }
    }
    return dp[0][0];
}
int main() {

    int n;cin>>n;
    vector<vector<int> >grid(n,vector<int>(n,0));
    vector<vector<long long> >dp(n,vector<long long>(n,-1));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            char ch;cin>>ch;
            if(ch=='.') grid[i][j]=0;
            else grid[i][j]=1;       
        }
    }

    // cout<<solverec(grid,n,0,0)<<endl;
    // cout<<solvememo(grid,n,0,0,dp)<<endl;
    cout<<solvetab(grid,n)<<endl;
}