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
    int getHeight(TreeNode* node) {
        if (!node) return 0;
        return 1 + max(getHeight(node->left), getHeight(node->right));
    }
    
    vector<vector<string>> printTree(TreeNode* root) {
        int h = getHeight(root);
        int m = h, n = (1 << h) - 1;
        vector<vector<string>> res(m, vector<string>(n, ""));
        dfs(root, 0, 0, n - 1, res);
        return res;
    }
    
private:
    void dfs(TreeNode* node, int row, int left, int right, vector<vector<string>>& res) {
        if (!node || left > right) return;
        int mid = (left + right) / 2;
        res[row][mid] = to_string(node->val);
        dfs(node->left, row + 1, left, mid - 1, res);
        dfs(node->right, row + 1, mid + 1, right, res);
    }
};