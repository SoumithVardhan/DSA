#include<iostream>
#include<vector>
using namespace std;

bool solvememo(vector<int> &coins, int targetsum, vector<bool> &dp) {
    if(targetsum == 0) return true;
    if(targetsum < 0) return false;
    if(dp[targetsum] != false) return dp[targetsum];
    bool ways = false;
    for(int i = 0; i < coins.size(); i++) {
        ways = solvememo(coins, targetsum - coins[i], dp);
        if(ways==true){
            break;
        }
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
    vector<bool> dp(x + 1);

    int cnt=0;
    for(int i=0;i<coins.size();i++){
        bool res = solvememo(coins, x-coins[i], dp);
        if(res)cnt++;
    }
    cout<<cnt<<endl;
    // cout << solvememo(coins, x, dp) << endl;

    // cout<<solvetab(coins,x)<<endl;

    return 0;
}