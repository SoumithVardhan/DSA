#include <iostream>
#include <vector>
#include <utility>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    pair<TreeNode*,int> solvedfs(TreeNode* root){
        if(root==NULL) return {NULL,0};

        pair<TreeNode*,int> ans1 = solvedfs(root->left);
        pair<TreeNode*,int> ans2 = solvedfs(root->right);

        if(ans1.second > ans2.second){
            return {ans1.first, ans1.second+1};
        }

        if(ans2.second > ans1.second){
            return {ans2.first, ans2.second+1};
        }

        return {root, ans1.second+1};
    }

    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return solvedfs(root).first;
    }
};

int main(){

    TreeNode* root = new TreeNode(3);

    root->left = new TreeNode(5);
    root->right = new TreeNode(1);

    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);

    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);

    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    Solution obj;

    TreeNode* ans = obj.subtreeWithAllDeepest(root);

    cout << ans->val << endl;
}