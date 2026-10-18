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
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxLen = 0;
    pair<int,int> dfs(TreeNode* root) {
        if (!root) return {0,0};
        auto left = dfs(root->left);
        auto right = dfs(root->right);
        int d1 = 1, d2 = 1;
        if (root->left) {
            if (root->left->val == root->val + 1) d1 = max(d1, left.first + 1);
            if (root->left->val == root->val - 1) d2 = max(d2, left.second + 1);
        }
        if (root->right) {
            if (root->right->val == root->val + 1) d1 = max(d1, right.first + 1);
            if (root->right->val == root->val - 1) d2 = max(d2, right.second + 1);
        }
        maxLen = max(maxLen, d1 + d2 - 1);
        return {d1, d2};
    }
    int longestConsecutive(TreeNode* root) {
        maxLen = 0;
        dfs(root);
        return maxLen;
    }
};
