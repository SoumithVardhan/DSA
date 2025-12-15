
// The below code TC:O(N^2)

// // FUNCTION CODE
// /* A Binary Tree node
// class Node
// {
//     int data;
//     Node left, right;
//    Node(int item)    {
//         data = item;
//         left = right = null;
//     }
// } */

// /* Should return minimum distance between a and b
//    in a tree with given root*/
   
//  /*
//  1.ispresent(root)
//  2.roottonode
//  3.calculate dist using formulae
//  */
// class GfG {
//     boolean ispresent(Node root,int a){
//         if(root==null)return false;
//         if(root.data==a)return true;
//         boolean ans1=ispresent(root.left,a);
//         boolean ans2=ispresent(root.right,a);
//         return ans1 || ans2;
//     }
//     void calculateroottonode(Node root,int a,int b,ArrayList<Integer>res1,ArrayList<Integer>res2){
//         if(root==null){
//             return ;
//         }
//         boolean ans1=ispresent(root,a);
//         boolean ans2=ispresent(root,b);
//         if(ans1==true){
//             res1.add(root.data);
//         }
//         if(ans2==true){
//             res2.add(root.data);
//         }
        
//         calculateroottonode(root.left,a,b,res1,res2);
//         calculateroottonode(root.right,a,b,res1,res2);
//     }
//     int findDist(Node root, int a, int b) {
//         ArrayList<Integer>res1=new ArrayList<>();
//         ArrayList<Integer>res2=new ArrayList<>();
//         calculateroottonode(root,a,b,res1,res2);
//         int i=0,j=0;
//         int cnt=res1.size()+res2.size();
//         while(i<res1.size() && j<res2.size() && res1.get(i).equals(res2.get(j))){
//                 i++;
//                 j++;
//                 cnt-=2;
//         }return cnt;
//     }
// }

// Imp Note :
// Here’s a clear, polished rephrasing:

// **Comparison Method | Works For | Fails For**
// `==` → Values from **-128 to 127**; fails for values outside this range
// `.equals()` → **All values**; never fails




//Optimized 
class GfG {
    boolean solve(Node root,int a,ArrayList<Integer>arr){
        if(root==null)return false;
        arr.add(root.data);
        if(root.data==a)return true;
        if(solve(root.left,a,arr) || solve(root.right,a,arr)){
            return true;
        }
        arr.remove(arr.size()-1);
        return false;
    }
    int findDist(Node root, int a, int b) {
        ArrayList<Integer>arr1=new ArrayList<>();
        ArrayList<Integer>arr2=new ArrayList<>();
        solve(root,a,arr1);
        solve(root,b,arr2);
        int i=0;
        while(i<arr1.size() && i<arr2.size() && arr1.get(i).equals(arr2.get(i))){
            i++;
        }
        return arr1.size()-i + arr2.size()-i;
    }
}

// But both solution worked for this constraint: 2 <= number of nodes <= 105