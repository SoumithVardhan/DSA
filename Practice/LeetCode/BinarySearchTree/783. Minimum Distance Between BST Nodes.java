/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public void solve(TreeNode root,ArrayList<Integer>arr){
        if(root==null)return;
        solve(root.left,arr);
        arr.add(root.val);
        solve(root.right,arr); 
    }
    public int minDiffInBST(TreeNode root) {
        ArrayList<Integer>arr=new ArrayList<>();
        solve(root,arr);
        int ans=Integer.MAX_VALUE;
        for(int i=1;i<arr.size();i++){
            ans=Math.min(ans,arr.get(i)-arr.get(i-1));
        }return ans;
    }
}