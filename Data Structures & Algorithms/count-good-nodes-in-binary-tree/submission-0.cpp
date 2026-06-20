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
    int goodNodes(TreeNode* root) {
        
        auto dfs = [&](this auto&& dfs, TreeNode* node, int max) -> int
        {
            if (node == nullptr) {
                return 0;
            }
            if (node->val >= max) 
            {
                return 1 + dfs(node->left, node->val) + dfs(node->right, node->val);
            }
            else {
                return dfs(node->left, max) + dfs(node->right, max);
            }
        };
        if (root == nullptr) {
            return 0;
        }
        return dfs(root, INT_MIN);
    }
};
