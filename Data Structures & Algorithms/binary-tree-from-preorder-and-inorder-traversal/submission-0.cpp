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
    TreeNode* build(span<int> preorder, span<int> inorder) {
        if (preorder.empty()) {
            return nullptr;
        }

        int left_size = ranges::find(inorder, preorder[0]) - inorder.begin();
        TreeNode* left = build(preorder.subspan(1, left_size), inorder.subspan(0, left_size));
        TreeNode* right = build(preorder.subspan(1 + left_size), inorder.subspan(1 + left_size));
        return new TreeNode{preorder[0], left, right};
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(preorder, inorder);
    }
};
