/*
    link:https://leetcode.com/problems/validate-binary-search-tree/description/
    Approach: ✨ Use recursion to validate each node against its valid range (leftlimit, rightlimit). For the left subtree, update the right boundary to the current node's value. For the right subtree, update the left boundary.
    If any node violates its range, return false.

🔑 Why Long instead of Integer?
If a node's value is Integer.MIN_VALUE or Integer.MAX_VALUE, using int limits would incorrectly validate it. For example, a root node with value Integer.MIN_VALUE would be considered invalid since we check root.val <= leftlimit. 
Using Long.MIN_VALUE and Long.MAX_VALUE ensures all valid integer node values fall strictly within our boundaries.
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
    boolean solve(TreeNode root,long leftlimit,long rightlimit){
        if(root==null)return true;
        if((long)root.val<=leftlimit || (long)root.val>=rightlimit)return false;
        boolean ans1=solve(root.left,leftlimit,root.val);
        boolean ans2=solve(root.right,root.val,rightlimit);
        return ans1 && ans2;
    }
    public boolean isValidBST(TreeNode root) {
        long leftlimit=Long.MIN_VALUE,rightlimit=Long.MAX_VALUE;
        return solve(root,leftlimit,rightlimit);
    }
}