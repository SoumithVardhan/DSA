package Practice.GFG.BinaryTree;
/*

Worst code eva:

class Solution {
    public static int maxsum=Integer.MIN_VALUE;
    public static int solve(Node root){
        if(root==null){
            return 0;
        }
        
        int ans1=solve(root.left);
        int ans2=solve(root.right);
        
        maxsum=Math.max(maxsum,Math.max(root.data+ans1,root.data+ans2));
        return maxsum;
        
        
    }
    public static int maxPathSum(Node root) {
        maxsum=Integer.MIN_VALUE;
        solve(root);
        return maxsum;
    }
}

💥 Failing Test Case:
Tree:
      -1
     /  \
    2    3
   /      \
  4        5
Expected: 7 (path: 5→3→-1)
Your code: 9 ❌

📝 Trace Showing the Failure:
javasolve(4): // Leaf
  maxsum = max(-∞, 4) = 4
  return 4  ✓

solve(2):
  ans1 = 4, ans2 = 0
  maxsum = max(4, max(2+4, 2+0)) = 6
  return 6  ✓

solve(5): // Leaf
  maxsum = max(6, 5) = 6  // Global max stays 6
  return 6  ❌ WRONG! Should return 5 (this leaf's value!)
  // This is where it breaks!

solve(3):
  ans1 = 0, ans2 = 6  ❌ (got global max 6, should be 5!)
  // Now calculating with wrong value:
  maxsum = max(6, max(3+0, 3+6)) = max(6, 9) = 9  ❌
  // Calculated 3+6=9 instead of 3+5=8!
  return 9  ❌

solve(-1):
  ans1 = 6, ans2 = 9
  maxsum = max(9, max(-1+6, -1+9)) = max(9, 8) = 9
  return 9

Final answer: 9  ❌

*/
/*

    2nd Failure Attempt
    // User function Template for Java

class Solution {
    public static int maxsum=Integer.MIN_VALUE;
    public static int solve(Node root){
        if(root==null){
            return Integer.MIN_VALUE;
        }
        
        if(root.left==null && root.right==null){
            maxsum=Math.max(maxsum,root.data);
            return root.data;
        }
        int ans1=solve(root.left);
        int ans2=solve(root.right);
        
        int currlen=root.data+Math.max(ans1,ans2);
        maxsum=Math.max(maxsum,currlen);
        return currlen;
        
    }
    public static int maxPathSum(Node root) {
        maxsum=Integer.MIN_VALUE;
        int finalans=solve(root);
        return Math.max(maxsum,finalans);
    }
}

🐛 The Remaining Bug:
javaif(root.left == null && root.right == null){
    maxsum = Math.max(maxsum, root.data);  // ❌ BUG HERE!
    return root.data;
}
```

**Problem:** You're updating `maxsum` at leaf nodes, but a **leaf alone is NOT a complete "leaf to root" path** (unless it IS the root)!

---

## 📝 **Trace with Failing Test Case: `10 N -20 -30`**
```
      10 (root)
        \
        -20
        /
      -30 (leaf)
Your code:
javasolve(-30): // Leaf
  maxsum = max(-∞, -30) = -30  ❌ Sets maxsum to leaf value!
  return -30

solve(-20):
  currlen = -20 + (-30) = -50
  maxsum = max(-30, -50) = -30
  return -50

solve(10): // Root
  currlen = 10 + (-50) = -40  ✓ This is the correct answer!
  maxsum = max(-30, -40) = -30  ❌ -30 > -40, so maxsum stays -30
  return -40

maxPathSum:
  return max(-30, -40) = -30  ❌ WRONG!
Expected: -40
You get: -30

*/

class Solution {
    public static int maxsum=Integer.MIN_VALUE;
    public static int solve(Node root){
        if(root==null){
            return Integer.MIN_VALUE;
        }
        
        if(root.left==null && root.right==null){
            return root.data;
        }
        int ans1=solve(root.left);
        int ans2=solve(root.right);
        
        int currlen=root.data+Math.max(ans1,ans2);
        maxsum=Math.max(maxsum,currlen);
        //even this statement is imp matters in other rec calls
        return currlen;
        
    }
    public static int maxPathSum(Node root) {
        maxsum=Integer.MIN_VALUE;
        int finalans=solve(root);
        return Math.max(maxsum,finalans);
    }
}