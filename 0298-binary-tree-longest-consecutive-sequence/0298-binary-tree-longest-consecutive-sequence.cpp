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
    int res = 0;
    void dfs(TreeNode* node, TreeNode* parent, int len) {
        if (!node) return;
        if (parent && parent->val + 1 == node->val) {
            len++;
        } else {
            len = 1;
        }
        res = max(res, len);
        dfs(node->left, node, len);
        dfs(node->right, node, len);
    }
    int longestConsecutive(TreeNode* root) {
        dfs(root, nullptr, 0);
        return res;
    }
};