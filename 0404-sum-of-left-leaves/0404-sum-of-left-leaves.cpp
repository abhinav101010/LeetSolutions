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
    int sumOfLeftLeaves(TreeNode* root) {
        int ans = 0;
        dfs(root, false, ans);
        return ans;
    }

private:
    void dfs(TreeNode* root, bool isLeft, int& ans) {
        if (!root) return;
        if (!root->left && !root->right && isLeft) {
            ans += root->val;
        }
        dfs(root->left, true, ans);
        dfs(root->right, false, ans);
    }
};