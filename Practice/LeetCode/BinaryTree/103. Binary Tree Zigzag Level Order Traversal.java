public /**
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
    public void solve(TreeNode root,List<List<Integer>>ans){
        Queue<TreeNode>q=new LinkedList<>();
        List<Integer>res=new ArrayList<>();
        q.add(root);
        res.add(root.val);
        ans.add(res);
        int cnt=1;
        while(!q.isEmpty()){
            int size=q.size();
            res=new ArrayList<>();
            for(int i=0;i<size;i++){
                TreeNode value=q.poll();
                if(value.left!=null){
                    q.add(value.left);
                    res.add(value.left.val);
                }
                if(value.right!=null){
                    q.add(value.right);
                    res.add(value.right.val);
                }
            }cnt++;
            if(res.size()!=0 && cnt%2==0){
                Collections.reverse(res);
                ans.add(res);
            }
            else if(res.size()!=0 && cnt%2!=0){
                ans.add(res);
            }
        }
    }
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        List<List<Integer>>ans=new ArrayList<>();
        if(root==null)return new ArrayList<>();
        solve(root,ans);
        return ans;
    }
}