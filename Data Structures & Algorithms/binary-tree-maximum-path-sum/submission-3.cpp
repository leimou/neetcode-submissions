/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int maxPathSum(TreeNode* root) {
        if (root == nullptr) {
            return INT_MIN;
        }

        int leftTreeSum = treeSum(root->left);
        int rightTreeSum = treeSum(root->right);

        return max({leftTreeSum + rightTreeSum + root->val, maxPathSum(root->left), maxPathSum(root->right)});
    }

    int treeSum(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        return max(0, root->val + max(treeSum(root->left), treeSum(root->right)));
    }
};
