struct TreeNode {
    int val; TreeNode *left; TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
#include <algorithm>
using namespace std;
class Solution {
    int ans = 0;
    void dfs(TreeNode* node, int lo, int hi) {
        if (!node) return;
        ans = max(ans, max(abs(node->val - lo), abs(node->val - hi)));
        dfs(node->left, min(lo, node->val), max(hi, node->val));
        dfs(node->right, min(lo, node->val), max(hi, node->val));
    }
public:
    int maxAncestorDiff(TreeNode* root) {
        dfs(root, root->val, root->val);
        return ans;
    }
};
