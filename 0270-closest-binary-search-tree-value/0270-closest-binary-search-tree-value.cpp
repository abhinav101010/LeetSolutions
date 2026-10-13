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
    int closestValue(TreeNode* root, double target) {
        int res = root->val;
        TreeNode* cur = root;
        while (cur) {
            if (abs(cur->val - target) < abs(res - target)) {
                res = cur->val;
            }
            if (target < cur->val) {
                cur = cur->left;
            } else {
                cur = cur->right;
            }
        }
        return res;
    }
};