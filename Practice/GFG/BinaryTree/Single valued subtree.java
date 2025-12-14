package Practice.GFG.BinaryTree;
// User function Template for Java

/*class Node{
    int data;
    Node left;
    Node right;
    Node(int data){
        this.data = data;
        left=null;
        right=null;
    }
}*/

class Solution {
    int cnt=0;
    public boolean solve(Node root){
        if(root==null)return true;
        
        boolean ans1=solve(root.left);
        boolean ans2=solve(root.right);
        
        if(ans1==false || ans2==false)return false;
        if(root.left!=null && root.data!=root.left.data)return false;
        if(root.right!=null && root.data!=root.right.data)return false;
        
        cnt++;
        return true;
    }
    public int singlevalued(Node root) {
        solve(root);
        return cnt;
    }
}