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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});
        int maxWidth = 0;
        while (!q.empty()) {
            long long leftIdx = q.front().second;
            int size = q.size();
            long long lastIdx = 0;
            for (int i = 0; i < size; i++) {
                auto [node, idx] = q.front();
                q.pop();
                lastIdx = idx;
                if (node->left) q.push({node->left, idx * 2});
                if (node->right) q.push({node->right, idx * 2 + 1});
            }
            maxWidth = max(maxWidth, (int)(lastIdx - leftIdx + 1));
        }
        return maxWidth;
    }
};