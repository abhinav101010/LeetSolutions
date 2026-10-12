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
    
    int dfs(TreeNode* node) {
        if (!node) return 0;
        int left = dfs(node->left);
        int right = dfs(node->right);
        int leftLen = (node->left && node->left->val == node->val) ? left + 1 : 1;
        int rightLen = (node->right && node->right->val == node->val) ? right + 1 : 1;
        res = max(res, left + right);
        return max(leftLen, rightLen);
    }
    
    int longestUnivaluePath(TreeNode* root) {
        dfs(root);
        return res;
    }
};