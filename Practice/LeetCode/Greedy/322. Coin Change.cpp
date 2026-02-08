#include <iostream>
#include <vector>
using namespace std;

//dp[i-coins[j-1]][j]
// To match the indexing of coints with the dp table, we are using j-1 to access the coins array.

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>dp(amount+1,vector<int>(n+1,INT_MAX));

        // First row is 0 because if amount is 0 then we don't need any coins to make the amount.
        for(int j=0; j<=n; j++){
            dp[0][j] = 0;
        }
        
        for(int i=1;i<=amount;i++){
            for(int j=1;j<=n;j++){
                //excl
                dp[i][j] = dp[i][j-1];
                //incl
                if(i >= coins[j-1] && dp[i-coins[j-1]][j] != INT_MAX){
                    dp[i][j] = min(dp[i][j], 1 + dp[i-coins[j-1]][j]);
                }
            }
        }return dp[amount][n] == INT_MAX? -1:dp[amount][n];
    }
};