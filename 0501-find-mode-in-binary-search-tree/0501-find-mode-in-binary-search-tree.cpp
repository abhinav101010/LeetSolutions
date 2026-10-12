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
    vector<int> findMode(TreeNode* root) {
        unordered_map<int, int> count;
        dfs(root, count);
        int maxCount = 0;
        for (const auto& p : count) {
            maxCount = max(maxCount, p.second);
        }
        vector<int> modes;
        for (const auto& p : count) {
            if (p.second == maxCount) {
                modes.push_back(p.first);
            }
        }
        return modes;
    }
    
private:
    void dfs(TreeNode* root, unordered_map<int, int>& count) {
        if (!root) return;
        count[root->val]++;
        dfs(root->left, count);
        dfs(root->right, count);
    }
};