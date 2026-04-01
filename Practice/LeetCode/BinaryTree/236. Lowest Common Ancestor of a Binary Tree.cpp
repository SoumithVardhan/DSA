#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};


// This approach also works for Binary Search Tree
// But we can do better in that case by using the properties of BST

// Approach 1: Backtracking
// TC: O(N) | SC: O(N)
class SolutionPath {
private:
    bool getPath(TreeNode* root, int target, vector<TreeNode*>& path) {
        if (root == NULL) return false;

        path.push_back(root);

        if (root->val == target) return true;

        if (getPath(root->left, target, path) ||
            getPath(root->right, target, path))
            return true;

        path.pop_back();
        return false;
    }

public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> pathP, pathQ;

        getPath(root, p->val, pathP);
        getPath(root, q->val, pathQ);

        // last common node in both paths
        TreeNode* lca = NULL;
        for (int i = 0; i < min(pathP.size(), pathQ.size()); i++) {
            if (pathP[i]->val == pathQ[i]->val)
                lca = pathP[i];
            else
                break;
        }
        return lca;
    }
};

// Approach 2: Recursion
// TC: O(N) | SC: O(N)
class SolutionRecursion {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL) return NULL;

        if (root == p || root == q) return root;

        TreeNode* left  = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        // both sides found something → current node is LCA
        if (left && right) return root;

        // return whichever side found something
        return left ? left : right;
    }
};

TreeNode* buildTree() {
    //        3
    //       / \
    //      5   1
    //     / \ / \
    //    6  2 0  8
    //      / \
    //     7   4
    TreeNode* root       = new TreeNode(3);
    root->left           = new TreeNode(5);
    root->right          = new TreeNode(1);
    root->left->left     = new TreeNode(6);
    root->left->right    = new TreeNode(2);
    root->right->left    = new TreeNode(0);
    root->right->right   = new TreeNode(8);
    root->left->right->left  = new TreeNode(7);
    root->left->right->right = new TreeNode(4);
    return root;
}

int main() {
    TreeNode* root = buildTree();

    // test case 1: LCA of 6 and 4 → expected 5
    TreeNode* p = root->left;               // node 5
    TreeNode* q = root->left->right->right; // node 4

    SolutionPath s1;
    cout << "Approach 1 (Two Paths):      "
         << s1.lowestCommonAncestor(root, p, q)->val << endl;

    SolutionRecursion s2;
    cout << "Approach 2 (Single Recursion): "
         << s2.lowestCommonAncestor(root, p, q)->val << endl;

    return 0;
}