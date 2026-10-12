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
    int rob(TreeNode* root) {
        auto result = dfs(root);
        return max(result.first, result.second);
    }
    
private:
    pair<int, int> dfs(TreeNode* node) {
        if (!node) return {0, 0};
        
        auto left = dfs(node->left);
        auto right = dfs(node->right);
        
        int rob = node->val + left.second + right.second;
        int notRob = max(left.first, left.second) + max(right.first, right.second);
        
        return {rob, notRob};
    }
};