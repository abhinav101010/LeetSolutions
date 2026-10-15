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
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {};
};

class Solution {
public:
    vector<TreeNode*> splitBST(TreeNode* root, int target) {
        if (!root) {
            return {nullptr, nullptr};
        }
        if (root->val <= target) {
            auto rightSplit = splitBST(root->right, target);
            root->right = rightSplit[0];
            return {root, rightSplit[1]};
        } else {
            auto leftSplit = splitBST(root->left, target);
            root->left = leftSplit[1];
            return {leftSplit[0], root};
        }
    }
};
