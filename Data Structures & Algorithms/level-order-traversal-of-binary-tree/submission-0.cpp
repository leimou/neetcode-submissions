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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (root == nullptr) {
            return result;
        }

        vector<TreeNode*> levelNodes;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty())
        {
            levelNodes.clear();
    
            while (!q.empty())
            {
                levelNodes.push_back(q.front());
                q.pop();
            }

            result.emplace_back();
            auto& values = result.back();
    
            for (auto node : levelNodes)
            {
                values.push_back(node->val);
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
        }
        return result;
    }
};
