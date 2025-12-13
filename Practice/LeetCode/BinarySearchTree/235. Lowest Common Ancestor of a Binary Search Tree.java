/*
    problem link: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/

    https://takeuforward.org/interviews/blind-75-leetcode-problems-detailed-video-solutions
    
*/
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */

class Solution {
    public TreeNode solve(TreeNode root,TreeNode p,TreeNode q){
        if(root==null)return null;
        TreeNode ans1=null,ans2=null;
        if(root.val>p.val && root.val>q.val)ans1=lowestCommonAncestor(root.left,p,q);
        else if(root.val<p.val && root.val<q.val)ans2=lowestCommonAncestor(root.right,p,q);
        if(ans1!=null)return ans1;
        if(ans2!=null)return ans2;
        return root;
    }
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        return solve(root,p,q);
    }
}