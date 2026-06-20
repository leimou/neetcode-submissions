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
    bool isValidBST(TreeNode* root) {
        stack<pair<TreeNode*, bool>> st;
        int prev = INT_MIN;
        // false: expand
        // true: visit
        st.push({root, false});
        while (!st.empty())
        {
            auto [node, visit] = st.top();
            st.pop();

            if (node == nullptr) {
                continue;
            }

            if (visit) {
                if (node->val <= prev) {
                    return false;
                }
                prev = node->val;
            }
            else {
                st.push({node->right, false});
                st.push({node, true});                
                st.push({node->left, false});
            }
        }
        return true;
    }
};
