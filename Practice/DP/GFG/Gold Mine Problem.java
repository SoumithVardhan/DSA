package Practice.DP.GFG;

class Solution {

    //Recursion
    public int solve(int[][] mat,int startx,int starty,int cnt){
        if(startx<0 || startx>=mat.length || starty>=mat[0].length){
            return Integer.MIN_VALUE;
        }
        cnt+=mat[startx][starty];
        if(starty==mat[0].length-1){
            return cnt;
        }
        int option1=solve(mat,startx+1,starty+1,cnt);
        int option2=solve(mat,startx-1,starty+1,cnt);
        int option3=solve(mat,startx,starty+1,cnt);
        return Math.max(option1,Math.max(option2,option3));
    }
    public int maxGold(int[][] mat) {
        int n=mat.length,m=mat[0].length;
        int ans=Integer.MIN_VALUE;
        int cnt=0;
        for(int i=0;i<n;i++){
            ans=Math.max(solve(mat,i,0,cnt),ans);   
        }
        return ans;
    }


    //Memoization
    
}
