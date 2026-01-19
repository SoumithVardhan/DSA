package Practice.DP.LeetCode;

class Solution{
    //Recursion
    public int solve(int[] nums, int start, int end, int cnt){
        if(start > end) return 0;
        
        // Exclude current house
        int excl = solve(nums, start+1, end, cnt);
        // Include current house
        int incl = nums[start] + solve(nums, start+2, end, cnt);
        
        return Math.max(incl, excl);
    }
    
    public int rob(int[] nums) {
        int n = nums.length;
        if(n == 1) return nums[0];
        if(n == 2) return Math.max(nums[0], nums[1]);
        
        int ans1 = solve(nums, 0, n-2, 0);
        int ans2 = solve(nums, 1, n-1, 0);
        return Math.max(ans1, ans2);

    }

    //Memoization
    public int solvememo(int[] nums, int start, int end, int cnt, int[] res){
        if(start > end) return 0;
        if(res[start] != -1) return res[start];
        
        // Exclude current house
        int excl = solvememo(nums, start+1, end, cnt, res);
        // Include current house
        int incl = nums[start] + solvememo(nums, start+2, end, cnt, res);
        
        res[start] = Math.max(incl, excl);
        return res[start];
    }
    
    public int robmemo(int[] nums) {
        int n = nums.length;
        if(n == 1) return nums[0];
        if(n == 2) return Math.max(nums[0], nums[1]);
        
        int[] res = new int[n];
        for(int i = 0; i < n; i++) res[i] = -1;
        int ans1 = solvememo(nums, 0, n-2, 0, res);
        
        int[] res2 = new int[n];
        for(int i = 0; i < n; i++) res2[i] = -1;
        int ans2 = solvememo(nums, 1, n-1, 0, res2);
        
        return Math.max(ans1, ans2);
    }

    //Tabulation
    public int solvetab(int[] nums, int start, int end, int cnt){
        if(start > end) return 0;
        
        int[] dp = new int[nums.length-1];
        dp[0] = nums[start];
        dp[1] = Math.max(nums[start], nums[start+1]);
        
        for(int i = 2; i < end-start+1; i++){
            dp[i] = Math.max(dp[i-1], nums[start+i] + dp[i-2]);
        }
        
        return dp[nums.length-2];
    }
    
    public int robtab(int[] nums) {
        int n = nums.length;
        if(n == 1) return nums[0];
        if(n == 2) return Math.max(nums[0], nums[1]);
        
        int ans1 = solvetab(nums, 0, n-2, 0);
        int ans2 = solvetab(nums, 1, n-1, 0);
        return Math.max(ans1, ans2);
    }

    //Space Optimization
    public int solveopt(int[] nums, int start, int end, int cnt){
        if(start > end) return 0;
        
        int prev2 = nums[start];
        int prev1 = Math.max(nums[start], nums[start+1]);
        
        for(int i = 2; i < end-start+1; i++){
            int curr = Math.max(prev1, nums[start+i] + prev2);
            prev2 = prev1;
            prev1 = curr;
        }
        
        return prev1;
    }
    
    public int robopt(int[] nums) {
        int n = nums.length;
        if(n == 1) return nums[0];
        if(n == 2) return Math.max(nums[0], nums[1]);
        
        int ans1 = solveopt(nums, 0, n-2, 0);
        int ans2 = solveopt(nums, 1, n-1, 0);
        return Math.max(ans1, ans2);
    }
}