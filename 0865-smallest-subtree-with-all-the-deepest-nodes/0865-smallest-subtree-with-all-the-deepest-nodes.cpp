// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return dfs(root).node;
    }
private:
    struct Result {
        int depth;
        TreeNode* node;
        Result(int d, TreeNode* n) : depth(d), node(n) {}
    };
    Result dfs(TreeNode* node) {
        if (!node) {
            return Result(0, nullptr);
        }
        Result left = dfs(node->left);
        Result right = dfs(node->right);
        if (left.depth > right.depth) {
            return Result(left.depth + 1, left.node);
        } else if (right.depth > left.depth) {
            return Result(right.depth + 1, right.node);
        } else {
            return Result(left.depth + 1, node);
        }
    }
};
