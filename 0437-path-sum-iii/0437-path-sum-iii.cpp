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
    int count = 0;
    unordered_map<long long, int> prefixSum;
    
    void dfs(TreeNode* node, long long currentSum, int targetSum) {
        if (!node) return;
        
        currentSum += node->val;
        count += prefixSum[currentSum - targetSum];
        prefixSum[currentSum]++;
        
        dfs(node->left, currentSum, targetSum);
        dfs(node->right, currentSum, targetSum);
        
        prefixSum[currentSum]--;
    }
    
public:
    int pathSum(TreeNode* root, int targetSum) {
        prefixSum[0] = 1;
        dfs(root, 0, targetSum);
        return count;
    }
};