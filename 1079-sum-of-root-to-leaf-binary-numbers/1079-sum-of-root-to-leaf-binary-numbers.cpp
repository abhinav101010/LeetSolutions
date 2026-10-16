struct TreeNode {
    int val; TreeNode *left; TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
    int ans = 0;
    void dfs(TreeNode* node, int val) {
        if (!node) return;
        val = (val << 1) | node->val;
        if (!node->left && !node->right) { ans += val; return; }
        dfs(node->left, val); dfs(node->right, val);
    }
public:
    int sumRootToLeaf(TreeNode* root) { dfs(root, 0); return ans; }
};
