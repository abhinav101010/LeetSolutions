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
    void recoverTree(TreeNode* root) {
        TreeNode* first = nullptr;
        TreeNode* second = nullptr;
        TreeNode* prev = nullptr;
        TreeNode* curr = root;

        while (curr != nullptr) {
            if (curr->left == nullptr) {
                if (prev != nullptr && prev->val > curr->val) {
                    if (first == nullptr) {
                        first = prev;
                    }
                    second = curr;
                }
                prev = curr;
                curr = curr->right;
            } else {
                TreeNode* node = curr->left;
                while (node->right != nullptr && node->right != curr) {
                    node = node->right;
                }

                if (node->right == nullptr) {
                    node->right = curr;
                    curr = curr->left;
                } else {
                    node->right = nullptr;
                    if (prev != nullptr && prev->val > curr->val) {
                        if (first == nullptr) {
                            first = prev;
                        }
                        second = curr;
                    }
                    prev = curr;
                    curr = curr->right;
                }
            }
        }

        if (first != nullptr && second != nullptr) {
            swap(first->val, second->val);
        }
    }
};
