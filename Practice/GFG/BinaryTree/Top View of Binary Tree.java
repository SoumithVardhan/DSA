package Practice.GFG.BinaryTree;
import java.util.*;
class Node {
    int data;
    Node left, right;

    Node(int val) {
        this.data = val;
        this.left = null;
        this.right = null;
    }
}

class Solution {
    public void solve(Node root,TreeMap<Integer,Integer>hm,Queue<Node>q,Queue<Integer>dist){
        
        q.add(root);
        dist.add(0);
        while(!q.isEmpty()){
            Node value=q.poll();
            int currdist=dist.poll();
            
            if(!hm.containsKey(currdist)){
                hm.put(currdist,value.data);
            }
            
            if(value.left!=null){
                q.add(value.left);
                dist.add(currdist-1);
            }
            
            if(value.right!=null){
                q.add(value.right);
                dist.add(currdist+1);
            }
            
        }
    }
    public ArrayList<Integer> topView(Node root) {
        TreeMap<Integer,Integer>hm=new TreeMap<>();
        ArrayList<Integer>arr=new ArrayList<>();
        if(root==null)return arr;
        Queue<Node>q=new LinkedList<>();
        Queue<Integer>dist=new LinkedList<>();
        solve(root,hm,q,dist);
        for(int value:hm.values()){
            arr.add(value);
        }
        return arr;
    }
}