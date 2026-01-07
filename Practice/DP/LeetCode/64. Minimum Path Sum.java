package Practice.DP.LeetCode;

// Recursion
class Solution {
    public int solve(int[][] grid,int sx,int sy,int px,int py,int cnt){
        if(sx>=grid.length || sy>=grid[0].length)return Integer.MAX_VALUE;
        cnt+=grid[sx][sy];
        if(sx==px && sy==py){
            return cnt;
        }
        int right=solve(grid,sx+1,sy,px,py,cnt);
        int down=solve(grid,sx,sy+1,px,py,cnt);
        return Math.min(right,down);
    }
    public int minPathSum(int[][] grid) {
        int px=grid.length-1,py=grid[0].length-1;
        int sx=0,sy=0;
        return solve(grid,sx,sy,px,py,0);
    }


//Memoization
    public int solve(int[][] grid,int sx,int sy,int px,int py,int cnt,int[][]memo){
        if(sx>px || sy>py)return Integer.MAX_VALUE;
        cnt+=grid[sx][sy];
        if(sx==px && sy==py){
            return cnt;
        }
        if(memo[sx][sy]!=0){
            return cnt+memo[sx][sy];
        }
        int right=solve(grid,sx+1,sy,px,py,cnt,memo);
        int down=solve(grid,sx,sy+1,px,py,cnt,memo);
        int best=Math.min(right,down);
        memo[sx][sy] = best - cnt;
        return best;
    }
    public int minPathSum2(int[][] grid) {
        int px=grid.length-1,py=grid[0].length-1;
        int sx=0,sy=0;
        int[][]memo=new int[px+1][py+1];
        return solve(grid,sx,sy,px,py,0,memo);
    }

//Tabulation

    public int solve(int[][] grid,int px,int py,int cnt){
        int[][]dp=new int[px+1][py+1];
        for(int i=px;i>=0;i--){
            for(int j=py;j>=0;j--){
                if(i==px && j==py){
                    dp[i][j]=grid[i][j];
                }
                else if(i==px && j!=py){
                    dp[i][j]=grid[i][j]+dp[i][j+1];
                }
                else if(j==py && i!=px){
                    dp[i][j]=grid[i][j]+dp[i+1][j];
                }
                else{
                    dp[i][j]=grid[i][j]+Math.min(dp[i+1][j],dp[i][j+1]);
                }
            }
        }return dp[0][0];
    }
    public int minPathSum3(int[][] grid) {
        int px=grid.length-1,py=grid[0].length-1;
        return solve(grid,px,py,0);
    }

}