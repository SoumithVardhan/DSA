/*
    link : https://leetcode.com/problems/subtree-of-another-tree/
*/
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
    public boolean solve(TreeNode root, TreeNode subroot,boolean ans,boolean ans2){
        if(root==null)return false;
        if(root!=subroot && root.left==null && root.right==null)return false;
        if(root.left==subroot || root.right==subroot)return true;
        if(root.left!=null){
            ans=solve(root.left,subroot,ans,ans2);
        }
        if(root.right!=null){
            ans2=solve(root.right,subroot,ans,ans2);   
        }
        return ans || ans2;
    }
    public boolean solve2(TreeNode root1,TreeNode root2){
        if(root1==null && root2==null)return true;
        if(root1==null && root2!=null || root1!=null && root2==null || root1.val!=root2.val)return false;
        return solve2(root1.left,root2.left) && solve2(root1.right,root2.right);
    }
    public boolean isSubtree(TreeNode root, TreeNode subRoot) {
        // boolean ans=false;
        // boolean ans2=false;
        // return solve(root,subRoot,ans,ans2);z
        if(root==null)return false;
        if(solve2(root,subRoot))return true;
        boolean ans=(isSubtree(root.left,subRoot) || isSubtree(root.right,subRoot));
        return ans;
    }
}