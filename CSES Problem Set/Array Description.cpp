#include<iostream>
#include<vector>
using namespace std;

const int MOD = 1e9 + 7;
int solverec(vector<int>&v,int prevval,int ind,int m){
    if(ind==v.size()){
        return 1;
    }
    int count=0;
    // 1 0 9 0 3
    // This below condition skips the value of 1 _ 9 _ 3
    // 1 2 9 _ 3 lets say you filled it with 2 then abs(2-9)>1 so it will not go further
    // This rec call wont further go and return 1
    if(v[ind]!=0){
        if(abs(v[ind]-prevval)<=1){
            count=solverec(v,v[ind],ind+1,m);
        }
    }
    // else condition ensure that you only fill a value 1 or 2 in 1 _ 9 in this blank
    else {
        for (int val = 1; val <= m; val++) {
            if (abs(val - prevval) <= 1) {
                count=(count+solverec(v,val,ind+1,m))% MOD;
            }
        }
    }
    // Only valid counts will be returned atlast !e
    return count;
}

int solvememo(vector<int>&v,int prevval,int ind,int m,vector<vector<int> >&dp){
    if(ind==v.size()){
        return 1;
    }
    if (dp[ind][prevval] != -1) {
        return dp[ind][prevval];
    }
    int count=0;
    // 1 0 9 0 3
    // This below condition skips the value of 1 _ 9 _ 3
    // 1 2 9 _ 3 lets say you filled it with 2 then abs(2-9)>1 so it will not go further
    // This rec call wont further go and return 1
    if(v[ind]!=0){
        if(abs(v[ind]-prevval)<=1){
            count=solvememo(v,v[ind],ind+1,m,dp);
        }
    }
    // else condition ensure that you only fill a value 1 or 2 in 1 _ 9 in this blank
    else {
        for (int val = 1; val <= m; val++) {
            if (abs(val - prevval) <= 1) {
                count=(count+solvememo(v,val,ind+1,m,dp))% MOD;
            }
        }
    }
    // Only valid counts will be returned atlast !e
    return dp[ind][prevval]=count;
}

int solvetab(vector<int>&v,int n,int m){
    // prev[v] = ways to reach previous position with value v
    // curr[v] = ways to reach current position with value v
    vector<long long> prev(m + 1, 0);
    vector<long long> curr(m + 1, 0);
    
    // Base case: first element
    if (v[0] == 0) {
        for (int i = 1; i <= m; i++) {
            prev[i] = 1;
        }
    } else {
        prev[v[0]] = 1;
    }
    
    // Fill remaining positions
    for (int i = 1; i < n; i++) {
        fill(curr.begin(), curr.end(), 0);
        
        if (v[i] == 0) {
            // Current position is unknown
            for (int val = 1; val <= m; val++) {
                for (int p = val - 1; p <= val + 1; p++) {
                    if (p >= 1 && p <= m) {
                        curr[val] = (curr[val] + prev[p]) % MOD;
                    }
                }
            }
        } else {
            // Current position is fixed
            int val = v[i];
            for (int p = val - 1; p <= val + 1; p++) {
                if (p >= 1 && p <= m) {
                    curr[val] = (curr[val] + prev[p]) % MOD;
                }
            }
        }
        
        swap(prev, curr);
    }
    
    // Sum all ways
    long long result = 0;
    for (int val = 1; val <= m; val++) {
        result = (result + prev[val]) % MOD;
    }
    
    return result;
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<int>v(n);
    int result=0;
    for(int i=0;i<n;i++){
        cin>>v[i];
    }

    //Recursive Approach

    // if(v[0]!=0){
    //     result=solverec(v,v[0],1,m);
    // }else{
    //     for (int val = 1; val <= m; val++) {
    //         result = (result + solverec(v, val, 1, m)) % MOD;
    //     }
    // }

    //Memoization Approach

    // vector<vector<int> > dp(n, vector<int>(m + 1, -1));
    // if (v[0] != 0) {
    //     result = solvememo(v, v[0], 1, m, dp);
    // } else {
    //     for (int val = 1; val <= m; val++) {
    //         vector<vector<int> > dp(n, vector<int>(m+1, -1));
    //         result = (result + solvememo(v, val, 1, m, dp)) % MOD;
    //     }
    // }
    
    //Tabulation Approach
    result = solvetab(v, n, m);
    cout << result << endl;
    return 0;
}

