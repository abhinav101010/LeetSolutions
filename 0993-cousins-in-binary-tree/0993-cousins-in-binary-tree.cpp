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
    bool isCousins(TreeNode* root, int x, int y) {
        int xDepth = -1, yDepth = -1;
        TreeNode* xParent = nullptr;
        TreeNode* yParent = nullptr;
        function<void(TreeNode*, TreeNode*, int)> dfs = [&](TreeNode* parent, TreeNode* cur, int k) {
            if (!cur) return;
            if (cur->val == x) {
                xParent = parent;
                xDepth = k;
            }
            if (cur->val == y) {
                yParent = parent;
                yDepth = k;
            }
            if (xDepth == -1 || yDepth == -1) {
                dfs(cur, cur->left, k + 1);
                dfs(cur, cur->right, k + 1);
            }
        };
        dfs(nullptr, root, 0);
        return (xDepth == yDepth && xParent != yParent);
    }
};
