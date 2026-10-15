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
private:
    long long total;
    bool found;
    TreeNode* root;
public:
    bool checkEqualTree(TreeNode* root) {
        this->root = root;
        total = totalSum(root);
        found = false;
        dfs(root);
        return found;
    }
    
    long long totalSum(TreeNode* node) {
        if (!node) return 0;
        return node->val + totalSum(node->left) + totalSum(node->right);
    }
    
    long long dfs(TreeNode* node) {
        if (!node) return 0;
        long long sum = node->val + dfs(node->left) + dfs(node->right);
        if (sum * 2 == total && node != root) {
            found = true;
        }
        return sum;
    }
};
