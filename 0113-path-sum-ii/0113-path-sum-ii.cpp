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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> path;
        dfs(root, targetSum, path, ans);
        return ans;
    }

private:
    void dfs(TreeNode* root, int sum, vector<int>& path, vector<vector<int>>& ans) {
        if (root == nullptr) {
            return;
        }

        path.push_back(root->val);

        if (root->left == nullptr && root->right == nullptr && root->val == sum) {
            ans.push_back(path);
        } else {
            dfs(root->left, sum - root->val, path, ans);
            dfs(root->right, sum - root->val, path, ans);
        }

        path.pop_back();
    }
};
