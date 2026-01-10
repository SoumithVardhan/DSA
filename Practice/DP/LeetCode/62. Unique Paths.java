// Blind 75 LeetCode Questions
package Practice.DP.LeetCode;

class Solution {

    //Recursion
    public int solve(int m,int n,int startx,int starty){
        if(startx>=m || starty>=n)return 0;
        if(startx==m-1 && starty==n-1)return 1;
        int option1=solve(m,n,startx+1,starty);
        int option2=solve(m,n,startx,starty+1);
        return option1+option2;
    }
    public int uniquePaths(int m, int n) {
        return solve(m,n,0,0);
    }

    //Memoization
    public int solve(int m,int n,int startx,int starty,int[][] memo){
        if(startx>=m || starty>=n)return 0;
        if(startx==m-1 && starty==n-1)return 1;

        if(memo[startx][starty]!=-1){
            return memo[startx][starty];
        }

        int option1=solve(m,n,startx+1,starty,memo);
        int option2=solve(m,n,startx,starty+1,memo);
        memo[startx][starty]=option1+option2;
        return memo[startx][starty];
    }
    public int uniquePathsMemoization(int m, int n) {
        int[][] memo=new int[m][n];
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                memo[i][j]=-1;
            }
        }
        return solve(m,n,0,0,memo);
    }

    //Tabulation
    public int solve(int m,int n){
        int[][] tabulation=new int[m][n];
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(i==m-1 && j==n-1)tabulation[i][j]=1;
                else if(j==n-1)tabulation[i][j]=tabulation[i+1][j];
                else if(i==m-1)tabulation[i][j]=tabulation[i][j+1];
                else{
                    tabulation[i][j]=tabulation[i+1][j]+tabulation[i][j+1];
                }
            }
        }
        return tabulation[0][0];
    }
    public int uniquePathsTabulation(int m, int n) {
        return solve(m,n);
    }

    public int solveopt(int m,int n){
        int[] tabulation=new int[n];
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(i==m-1 && j==n-1)tabulation[j]=1;
                else if(j==n-1)tabulation[j]=1;
                else if(i==m-1)tabulation[j]=1;
                else{
                    tabulation[j]=tabulation[j]+tabulation[j+1];
                }
            }
        }
        return tabulation[0];
    }
    public int uniquePathstabulationopt(int m, int n) {
        return solveopt(m,n);
    }

}