package Practice.DP.GFG;

class Solution {
    public int knapsack(int W, int val[], int wt[]) {
        int n=val.length;
        int[][]dp=new int[n+1][W+1];
        for(int i=1;i<=n;i++){
            for(int j=1;j<=W;j++){
                //excl
                int ans1=dp[i-1][j];
                //incl
                int ans2=0;
                if(j>=wt[i-1]){
                    ans2=(val[i-1]+dp[i-1][j-wt[i-1]]);
                }
                dp[i][j]=Math.max(ans1,ans2);
            }
        }return dp[n][W];
    }
}

