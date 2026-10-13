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
    int count = 0;
    bool isUnival(TreeNode* node) {
        if (!node) return true;
        bool left = isUnival(node->left);
        bool right = isUnival(node->right);
        if (left && right) {
            if ((!node->left || node->left->val == node->val) && (!node->right || node->right->val == node->val)) {
                count++;
                return true;
            }
        }
        return false;
    }
    int countUnivalSubtrees(TreeNode* root) {
        isUnival(root);
        return count;
    }
};