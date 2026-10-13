class Solution {
public:
    int res = 0;
    vector<int> dfs(TreeNode* node) {
        if (!node) return {INT_MAX, INT_MIN, 0};
        auto left = dfs(node->left);
        auto right = dfs(node->right);
        if (left[2] == -1 || right[2] == -1 || node->val <= left[1] || node->val >= right[0]) {
            return {0, 0, -1};
        }
        int size = left[2] + right[2] + 1;
        res = max(res, size);
        return {min(left[0], node->val), max(right[1], node->val), size};
    }
    int largestBSTSubtree(TreeNode* root) {
        dfs(root);
        return res;
    }
};