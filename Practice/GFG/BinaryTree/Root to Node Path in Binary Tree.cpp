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

// Approach 1: Backtracking
// TC: O(N) | SC: O(N)
class SolutionBacktrack {
private:
    bool getPath(TreeNode* root, int target, vector<int>& path) {
        if (root == NULL) return false;

        // add current node to path
        path.push_back(root->val);

        // found target
        if (root->val == target) return true;

        // check left and right subtrees
        if (getPath(root->left, target, path) ||
            getPath(root->right, target, path))
            return true;

        // not found in this path, backtrack
        path.pop_back();
        return false;
    }

public:
    vector<int> rootToNode(TreeNode* root, int target) {
        vector<int> path;
        getPath(root, target, path);
        return path;
    }
};

// TC: O(N^2) | SC: O(N)
// Approach 2: Using isPresent function to check presence of target in left or right subtree
class SolutionIsPresent {
private:
    bool isPresent(TreeNode* root, int target) {
        if (root == NULL) return false;
        if (root->val == target) return true;
        return isPresent(root->left, target) ||
               isPresent(root->right, target);
    }

public:
    vector<int> rootToNode(TreeNode* root, int target) {
        vector<int> path;
        TreeNode* curr = root;

        while (curr->val != target) {
            if (isPresent(curr->left, target)) {
                path.push_back(curr->val);
                curr = curr->left;
            } else {
                path.push_back(curr->val);
                curr = curr->right;
            }
        }
        path.push_back(curr->val); // add target itself
        return path;
    }
};

TreeNode* buildTree() {
    //        1
    //       / \
    //      2   3
    //     / \
    //    4   5
    TreeNode* root = new TreeNode(1);
    root->left      = new TreeNode(2);
    root->right     = new TreeNode(3);
    root->left->left  = new TreeNode(4);
    root->left->right = new TreeNode(5);
    return root;
}

void printPath(vector<int>& path) {
    for (int i = 0; i < path.size(); i++) {
        cout << path[i];
        if (i != path.size() - 1) cout << " -> ";
    }
    cout << endl;
}

int main() {
    TreeNode* root = buildTree();
    int target = 5;

    // Approach 1
    SolutionBacktrack s1;
    vector<int> path1 = s1.rootToNode(root, target);
    cout << "Approach 1 (Backtracking) O(N): ";
    printPath(path1);

    // Approach 2
    SolutionIsPresent s2;
    vector<int> path2 = s2.rootToNode(root, target);
    cout << "Approach 2 (isPresent)   O(N^2): ";
    printPath(path2);

    return 0;
}

// ## Output
// Target: 5
// ----------------------------
// Approach 1 (Backtracking) O(N):  1 -> 2 -> 5
// Approach 2 (isPresent)   O(N^2): 1 -> 2 -> 5