#include<iostream>
#include<vector>
using namespace std;

const int MOD = 1e9 + 7;

int solvememo(vector<int> &coins, int targetsum, vector<int> &dp) {
    if(targetsum == 0) return 1;
    if(targetsum < 0) return 0;
    if(dp[targetsum] != -1) return dp[targetsum];
    long long ways = 0;
    for(int i = 0; i < coins.size(); i++) {
        ways = (ways + solvememo(coins, targetsum - coins[i], dp)) % MOD;
    }
    return dp[targetsum] = ways;
}

int solvetab(vector<int> &coins, int x) {
    const int MOD = 1e9 + 7;
    vector<long long> dp(x + 1, 0);
    dp[0] = 1; 
    
    for(int i = 1; i <= x; i++) {
        for(int j = 0; j < (int)coins.size(); j++) {
            if(i >= coins[j]) {  
                dp[i] = (dp[i] + dp[i - coins[j]]) % MOD;  
            }
        }
    }
    
    return dp[x];
}

int main(){
    int n, x;
    cin >> n >> x;
    vector<int> coins(n);
    for(int i = 0; i < n; i++) {
        cin >> coins[i];
    }
    // vector<int> dp(x + 1, -1);
    // cout << solvememo(coins, x, dp) << endl;

    cout<<solvetab(coins,x)<<endl;

    return 0;
}