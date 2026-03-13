#include<iostream>
#include<vector>
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
    void solve(TreeNode* root, int targetSum, vector<int> ans, vector<vector<int>>& finalarr) {
        if(root == NULL) return;

        ans.push_back(root->val);

        if(root->left == NULL && root->right == NULL && targetSum == root->val) {
            finalarr.push_back(ans);
            return;
        }

        solve(root->left,  targetSum - root->val, ans, finalarr);
        solve(root->right, targetSum - root->val, ans, finalarr);
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> ans;
        vector<vector<int>> finalarr;
        solve(root, targetSum, ans, finalarr);
        return finalarr;
    }
};

int main() {
    //       5
    //      / \
    //     4   8
    //    /   / \
    //   11  13  4
    //  /  \    / \
    // 7    2  5   1

    TreeNode* root = new TreeNode(5);
    root->left     = new TreeNode(4);
    root->right    = new TreeNode(8);
    root->left->left         = new TreeNode(11);
    root->left->left->left   = new TreeNode(7);
    root->left->left->right  = new TreeNode(2);
    root->right->left        = new TreeNode(13);
    root->right->right       = new TreeNode(4);
    root->right->right->left = new TreeNode(5);
    root->right->right->right= new TreeNode(1);

    Solution obj;
    vector<vector<int>> result = obj.pathSum(root, 22);

    for(auto& path : result) {
        for(int x : path) cout << x << " ";
        cout << "\n";
    }
    // 5 4 11 2
    // 5 8 4 5

    return 0;
}