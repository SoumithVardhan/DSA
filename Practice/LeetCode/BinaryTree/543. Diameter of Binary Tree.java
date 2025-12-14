/*
This is failed approach as you are only calculating the diameter which only passes through root
what if the diameter passes through some other node than root view in images folder 
*/ 

// class Solution {
//     public int solve(TreeNode root){
//         if(root==null)return 0;
//         if(root!=null && root.left==null && root.right==null)return 1;
//         int ans1=0,ans2=0;
//         if(root.left!=null){
//             ans1=1+solve(root.left);
//         }
//         if(root.right!=null){
//             ans2=1+solve(root.right);
//         }
//         return Math.max(ans1,ans2);
//     }
//     public int diameterOfBinaryTree(TreeNode root) {
//         int res1=0,res2=0;
//         if(root.left!=null){
//             res1=solve(root.left);
//         }
//         if(root.right!=null){
//             res2=solve(root.right);
//         }
//         return res1+res2;
//     }
// }


//
/**
Solution : You should make count of a field named maxdiameter at every instance while traversing the tree.

class Solution {
    int maxdiameter=0;
    public int solve(TreeNode root){
        if(root==null)return 0;
        if(root!=null && root.left==null && root.right==null)return 1;
        int ans1=0,ans2=0;
        if(root.left!=null){
            ans1=1+solve(root.left);
        }
        if(root.right!=null){
            ans2=1+solve(root.right);
        }
        maxdiameter=Math.max(maxdiameter,ans1+ans2);
        return Math.max(ans1,ans2);
    }
    public int diameterOfBinaryTree(TreeNode root) {
        int res1=0,res2=0;
        if(root.left!=null){
            res1=solve(root.left);
        }
        if(root.right!=null){
            res2=solve(root.right);
        }
        return maxdiameter;
    }
}

Then thought like this worst idea 
Made a blunder which failed almost every test case 

Issue 1 :

public int solve(TreeNode root){
    if(root == null) return 0;
    if(root != null && root.left == null && root.right == null) return 1;  // ❌ EARLY RETURN!
    // ... rest of code (including maxdiameter update) is NEVER reached for leaves!
}
maxdiameter = Math.max(maxdiameter, ans1 + ans2);  // SKIPPED for leaf nodes!
---
```
    1
   / \
  2   3
```

---

🔑 Key Fixes:
Fix #1: Call solve(root), not solve(root.left) and solve(root.right)
java// ❌ Your code:
solve(root.left);
solve(root.right);

// ✅ Correct:
solve(root);  // This recursively processes ALL nodes including root
Fix #2: Remove early return for leaf nodes
java// ❌ Your code:
if(root != null && root.left == null && root.right == null) return 1;  // Skips maxdiameter update!

// ✅ Correct:
// No special case for leaves - let them fall through to the maxdiameter line
Fix #3: Don't add +1 before recursion
java// ❌ Your code:
ans1 = 1 + solve(root.left);  // Adds too early

// ✅ Correct:
ans1 = solve(root.left);      // Get height first
// ... update maxDiameter ...
return 1 + Math.max(ans1, ans2);  // Add +1 when returning

 */


/**
    Why return 1; fails!
 */
// class Solution {
//     int maxdiameter=0;
//     public int solve(TreeNode root){
//         if(root==null)return 0;
//         if(root!=null && root.left==null && root.right==null){
//             maxdiameter = Math.max(maxdiameter, 0);
//             return 1;
//         }
//         int ans1=0,ans2=0;
//         if(root.left!=null){
//             ans1=1+solve(root.left);
//         }
//         if(root.right!=null){
//             ans2=1+solve(root.right);
//         }
//         maxdiameter=Math.max(maxdiameter,ans1+ans2);
//         return Math.max(ans1,ans2);
//     }
//     public int diameterOfBinaryTree(TreeNode root) {
//         int res1=0,res2=0;
//         solve(root);
//         return maxdiameter;
//     }
// }

/*

    🐛 Why return 1; Fails:
With return 1; (WRONG):
javaif(root.left == null && root.right == null){
    maxdiameter = Math.max(maxdiameter, 0);
    return 1;  // ❌ Returns here, exits early!
}
```

**Trace with tree [1,2,3,4,5]:**
```
      1
     / \
    2   3
   / \
  4   5
javasolve(4): // Leaf
  - Enters leaf case
  - return 1  // ❌ Exits here!

solve(2):
  - ans1 = 1 + solve(4) = 1 + 1 = 2  // ❌ DOUBLE COUNT!
  // (1 from the if statement, +1 from leaf return)
  
  - ans2 = 1 + solve(5) = 1 + 1 = 2  // ❌ DOUBLE COUNT!
  
  - maxdiameter = 2 + 2 = 4  // ❌ WRONG! (Expected: 2)
The edge from 2→4 is counted TWICE:

Once in ans1 = 1 + ...
Once in return 1 from the leaf

*/


/*

    Final Correct Code

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
    int maxdiameter=0;
    public int solve(TreeNode root){
        if(root==null)return 0;
        int ans1=0,ans2=0;
        if(root.left!=null){
            ans1=1+solve(root.left);
        }
        if(root.right!=null){
            ans2=1+solve(root.right);
        }
        maxdiameter=Math.max(maxdiameter,ans1+ans2);
        return Math.max(ans1,ans2);
    }
    public int diameterOfBinaryTree(TreeNode root) {
        maxdiameter=0;
        solve(root);
        return maxdiameter;
    }
}