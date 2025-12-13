/*
    problem link: https://leetcode.com/problems/kth-smallest-element-in-a-bst/
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


 //our approach
class Solution {
    int ans=0;
    int cnt=0;
    public int solve(TreeNode root,int k){
        if(root==null)return 0;
        int ans1=solve(root.left,k);
        if(ans != 0) return ans;
        cnt++;
        if(k==cnt){
            ans=root.val;
            return root.val;
        }
        int ans2=solve(root.right,k);
        return 0;
    }
    public int kthSmallest(TreeNode root, int k) {
        solve(root,k);
        return ans;
    }
};




// using stack 
/*
class Solution {
    public int kthSmallest(TreeNode root, int k) {
        Stack<TreeNode> stack = new Stack<>();
        TreeNode curr = root;
        int count = 0;
        
        while (curr != null || !stack.isEmpty()) {
            // Go to leftmost node
            while (curr != null) {
                stack.push(curr);
                curr = curr.left;
            }
            
            // Process current node
            curr = stack.pop();
            count++;
            if (count == k) {
                return curr.val;
            }
            
            // Move to right subtree
            curr = curr.right;
        }
        
        return -1; // Should never reach here
    }
}

*/