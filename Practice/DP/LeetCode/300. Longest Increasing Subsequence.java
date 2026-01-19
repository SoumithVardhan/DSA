package Practice.DP.LeetCode;

class Solution {

    //Recursion
    public int solveRec(int[] nums,int i){
        if(i==0)return 1;
        int maxlen=1;
        for(int j=i-1;j>=0;j--){
            if(nums[j]<nums[i])
                maxlen=Math.max(maxlen,1+solveRec(nums,j));
        }
        return maxlen;
    }
    public int lengthOfLISRec(int[] nums) {
        int n=nums.length;
        if(n==1)return 1;
        int res=1;
        for(int i=0;i<n;i++){
            res=Math.max(res,solveRec(nums,i));
        }
        return res;
    }


    //Memoization
    public int solvememo(int[] nums,int i,int[] dp){
        if(i==0)return 1;
        if(dp[i]!=0)return dp[i];
        int maxlen=1;
        for(int j=i-1;j>=0;j--){
            if(nums[j]<nums[i])
                maxlen=Math.max(maxlen,1+solvememo(nums,j,dp));
        }
        dp[i]=maxlen;
        return maxlen;
    }
    public int lengthOfLISMemo(int[] nums) {
        int n=nums.length;
        if(n==1)return 1;
        int res=1;
        int[] dp=new int[n];
        for(int i=0;i<n;i++){
            res=Math.max(res,solvememo(nums,i,dp));
        }
        return res;
    }

    //Tabulation My Version
    public int solveTab(int[] nums){
        int n=nums.length;
        int[] dp=new int[n];
        dp[0]=1;
        int maxlen=1;
        int globalmax=1;
        for(int i=1;i<n;i++){
            maxlen=1;
            for(int j=i-1;j>=0;j--){
                if(nums[j]<nums[i]){
                    maxlen=Math.max(maxlen,1+dp[j]);
                }
            }
            dp[i]=maxlen;
            globalmax=Math.max(globalmax,dp[i]);
        }
        return globalmax;
    }
    public int lengthOfLISTab(int[] nums) {
        int n=nums.length;
        if(n==1)return 1;
        return solveTab(nums);
    }

    //Tabulation Himanshu
    public int lengthOfLIS(int[] nums) {
        int n=nums.length;
        if(n==1)return 1;
        int lis=0;
        int[]dp=new int[n];
        dp[0]=1;
        for(int i=1;i<n;i++){
            int res=0;
            for(int j=i-1;j>=0;j--){
                if(nums[j]<nums[i]){
                    res=Math.max(dp[j],res);
                }
            }
            dp[i]=res+1;
            lis=Math.max(dp[i],lis);
        }return lis;
    }
}