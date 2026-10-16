// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {};
};
class Solution {
private:
    int ans;
public:
    int minCameraCover(TreeNode* root) {
        ans = 0;
        int state = dfs(root);
        if (state == 0) {
            ans++;
        }
        return ans;
    }
private:
    int dfs(TreeNode* node) {
        if (!node) return 2; // covered
        int left = dfs(node->left);
        int right = dfs(node->right);
        if (left == 0 || right == 0) {
            ans++;
            return 1; // has camera
        }
        if (left == 1 || right == 1) {
            return 2; // covered
        }
        return 0; // not covered
    }
};
