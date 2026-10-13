class Solution {
public:
    vector<vector<int>> res;
    int getHeight(TreeNode* node) {
        if (!node) return -1;
        int h = 1 + max(getHeight(node->left), getHeight(node->right));
        if (res.size() <= h) res.resize(h + 1);
        res[h].push_back(node->val);
        return h;
    }
    vector<vector<int>> findLeaves(TreeNode* root) {
        getHeight(root);
        return res;
    }
};