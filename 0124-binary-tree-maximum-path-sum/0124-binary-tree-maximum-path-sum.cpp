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
private:
    int maxSum = INT_MIN;
    
public:
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return maxSum;
    }
    
private:
    int dfs(TreeNode* node) {
        if (!node) return 0;
        
        int leftMax = max(dfs(node->left), 0);
        int rightMax = max(dfs(node->right), 0);
        
        int currentMax = node->val + leftMax + rightMax;
        maxSum = max(maxSum, currentMax);
        
        return node->val + max(leftMax, rightMax);
    }
};