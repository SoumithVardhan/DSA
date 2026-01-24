#include<iostream>
#include<vector>
using namespace std;

const int MOD = 1e9 + 7;

// COIN COMBINATIONS I (ORDERED) - Memoization
// Multi-way branching: Try ALL coins at each step (allows reordering)
// Time: O(n*x), Space: O(x) + O(x) recursion stack
// Note: May cause stack overflow for large x (use tabulation instead)
// Multi-way branching: For current sum, try each coin and recurse with reduced sum
// All coins remain available in next recursive call (allows any ordering)

//                         targetsum=9
//             /        |        \        \
//          coin1     coin2     coin3     ...
//        (9-coin1) (9-coin2) (9-coin3)   ...
//        /   |   \    /  |  \    /  |  \
//   coin1 coin2 coin3 coin1 coin2 coin3 ...
//    ...   ...   ...   ...   ...   ...


// Final dp table would look like:
// dp value -> 1,0,1,1,1,3,2,5,6,8
// indices  -> 0 1 2 3 4 5 6 7 8 9
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

// ============================================================
// ALTERNATIVE APPROACH: Include/Exclude Pattern (Binary branching)
// ⚠️ Causes RUNTIME ERROR for large x due to deep recursion
// ============================================================
// For COIN COMBINATIONS I: Reset idx to 0 when including (allows reordering)
// For COIN COMBINATIONS II: Stay at idx when including (prevents reordering) 

//                             targetsum=9, idx=0
//                     /                           \
//                Include coin0                  Exclude coin0
//          (9-coin0, idx=0)                 (9, idx=1)
//            /          \                       /        \
//      Include coin0  Exclude coin0       Include coin1  Exclude coin1
//     (9-2*coin0,0)  (9-coin0,1)     (9-coin1,1)     (9,2)
//      ...       ...               ...             ...

long long solveCombinationsI(vector<int>& coins, int idx, int sum, 
                              vector<vector<long long>>& dp) {
    if(sum == 0) return 1;
    if(sum < 0 || idx >= (int)coins.size()) return 0;
    
    if(dp[idx][sum] != -1) return dp[idx][sum];
    
    long long incl = 0;
    
    // Include: reset to idx=0 (all coins available again)
    if(sum >= coins[idx]) {
        incl = solveCombinationsI(coins, 0, sum - coins[idx], dp);
    }
    
    // Exclude: move to next coin
    long long excl = solveCombinationsI(coins, idx + 1, sum, dp);
    
    return dp[idx][sum] = (incl + excl) % MOD;
}

int main() {
    int n, x;
    cin >> n >> x;
    
    vector<int> coins(n);
    for(int i = 0; i < n; i++) {
        cin >> coins[i];
    }
    
    vector<vector<long long>> dp(n, vector<long long>(x + 1, -1));
    
    // Choose one:
    
    // For Coin Combinations I (Ordered)
    cout << solveCombinationsI(coins, 0, x, dp) << endl;
    
    // For Coin Combinations II (Unordered)
    // cout << solveCombinationsII(coins, 0, x, dp) << endl;
    
    return 0;
}
