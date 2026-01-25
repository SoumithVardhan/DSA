#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;

/*
 * RECURSION: O(2^(x/min_coin)) time, O(x) space (stack)
 * Try including/excluding each coin
 */
long long solveRecursion(vector<int>& coins, int idx, int sum) {
    if(sum == 0) return 1;  
    if(sum < 0 || idx >= (int)coins.size()) return 0; 
    
    // Include coin (stay at idx) + Exclude coin (move to idx+1)
    return (solveRecursion(coins, idx, sum - coins[idx]) + 
            solveRecursion(coins, idx + 1, sum)) % MOD;
}

/*
 * MEMOIZATION: O(n*x) time, O(n*x) space
 * Cache results in 2D dp table
 */

//  **coins = [2, 3, 5], target = 9**

// how it avoids duplicates:
// ```
// solve(idx=0, sum=9)  // Start with coin 2
// ├─ Include coin 2: solve(idx=0, sum=7)  // Can use coin 2 again
// │  ├─ Include coin 2: solve(idx=0, sum=5)
// │  │  ├─ Include coin 2: solve(idx=0, sum=3)
// │  │  │  ├─ Include coin 2: solve(idx=0, sum=1) → 0
// │  │  │  └─ Exclude coin 2: solve(idx=1, sum=3)  // Move to coin 3
// │  │  │      ├─ Include coin 3: solve(idx=1, sum=0) → 1 ✓ [2,2,2,3]
// │  │  │      └─ Exclude coin 3: solve(idx=2, sum=3) → 0
// │  │  └─ Exclude coin 2: solve(idx=1, sum=5)  // Move to coin 3
// │  │      ├─ Include coin 3: solve(idx=1, sum=2) → 0
// │  │      └─ Exclude coin 3: solve(idx=2, sum=5)  // Move to coin 5
// │  │          ├─ Include coin 5: solve(idx=2, sum=0) → 1 ✓ [2,2,5]
// │  │          └─ Exclude coin 5: solve(idx=3, sum=5) → 0
// │  └─ Exclude coin 2: solve(idx=1, sum=7)
// └─ Exclude coin 2: solve(idx=1, sum=9)
// ```

// **Key observation:**

// Once we **exclude** coin 2 (by moving to `idx=1`), we can NEVER use coin 2 again in that branch!

// So we get:
// - ✅ `[2, 2, 2, 3]` - Uses coin 2 three times, then coin 3
// - ✅ `[2, 2, 5]` - Uses coin 2 twice, then coin 5
// - ❌ `[2, 2, 3, 2]` - **IMPOSSIBLE** because once we use coin 3 (idx=1), we can't go back to coin 2 (idx=0)

// ---

// ## Why No Duplicates?

// The algorithm enforces this rule:

// **"You can only use coins from index `idx` onwards"**
// ```
// State (idx=0, sum=9): Can use coins [2, 3, 5]
// State (idx=1, sum=7): Can use coins [3, 5] only (coin 2 excluded forever)
// State (idx=2, sum=4): Can use coins [5] only (coins 2,3 excluded forever)
// ```

long long solveMemo(vector<int>& coins, int idx, int sum, 
                    vector<vector<long long>>& dp) {
    if(sum == 0) return 1;
    if(sum < 0 || idx >= (int)coins.size()) return 0;
    
    if(dp[idx][sum] != -1) return dp[idx][sum]; 
    
    long long ways = 0;
    if(sum >= coins[idx]) {
        ways = solveMemo(coins, idx, sum - coins[idx], dp);
    }
    // Directly adds include data + exclude data
    ways = (ways + solveMemo(coins, idx + 1, sum, dp)) % MOD;
    
    return dp[idx][sum] = ways;
}


// 2D DP table: dp[idx][sum]
// We need dp[coin_index][target_sum]

// Final answer will be in dp[0][9]

// Key states computed (not all shown):
// dp[0][0] = 1  (base case)
// dp[0][2] = 1  (use coin 2 once)
// dp[0][3] = 1  (use coin 3 once) 
// dp[0][4] = 1  (use coin 2 twice)
// dp[0][5] = 2  (2+3 or 5)
// dp[0][6] = 2  (2+2+2 or 3+3)
// dp[0][7] = 2  (2+2+3 or 2+5)
// dp[0][8] = 2  (2+3+3 or 3+5)
// dp[0][9] = 3  (2+2+5, 3+3+3, 2+2+2+3)

// Answer: dp[0][9] = 3
// Still this approach will fail for runtimeerror (stack overflow) for large x
long long solveMemoMulti(vector<int>& coins, int idx, int targetsum,
                         vector<vector<long long>>& dp) {
    if(targetsum == 0) return 1;
    if(targetsum < 0 || idx >= (int)coins.size()) return 0;
    
    if(dp[idx][targetsum] != -1) return dp[idx][targetsum];
    
    long long ways = 0;
    
    // Option 1: Don't use any more coins from this index onwards
    // (This is implicit - if we don't enter the loop for current coin)
    
    // Option 2: Use coins starting from idx
    for(int i = idx; i < (int)coins.size(); i++) {
        // Use coin[i], then recursively solve with coins from i onwards
        ways = (ways + solveMemoMulti(coins, i, targetsum - coins[i], dp)) % MOD;
    }
    
    return dp[idx][targetsum] = ways;
}


/*
 * TABULATION: O(n*x) time, O(x) space
 * Build solution bottom-up
 */

// Final DP table for coins={2,3,5}, x=9:
// dp = [1, 0, 1, 1, 1, 2, 2, 2, 3, 3]
// idx   0  1  2  3  4  5  6  7  8  9

long long solveTab(vector<int>& coins, int x) {
    vector<long long> dp(x + 1, 0);
    dp[0] = 1;
    
    for(int coin : coins) {  
        for(int i = coin; i <= x; i++) {  
            dp[i] = (dp[i] + dp[i - coin]) % MOD;
        }
    }
    
    return dp[x];
}

int main() {
    int n, x;
    cin >> n >> x;
    
    vector<int> coins(n);
    for(int i = 0; i < n; i++) {
        cin >> coins[i];
    }
    
    // cout << solveRecursion(coins, 0, x) << endl;
    
    // vector<vector<long long>> dp(n, vector<long long>(x + 1, -1));
    // cout << solveMemo(coins, 0, x, dp) << endl;
    vector<vector<long long>> dp(n, vector<long long>(x + 1, -1));
    cout << solveMemoMulti(coins,0, x, dp) << endl;
    // cout << solveTab(coins, x) << endl;  
    
    return 0;
}