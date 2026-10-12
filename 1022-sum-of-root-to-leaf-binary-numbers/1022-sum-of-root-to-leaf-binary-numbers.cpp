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
    int sumRootToLeaf(TreeNode* root) {
        int ans = 0;
        function<void(string, TreeNode*)> dfs = [&](string s, TreeNode* cur) {
            if (!cur) return;
            s += to_string(cur->val);
            if (!cur->left && !cur->right) {
                ans += stoi(s, nullptr, 2);
                return;
            }
            dfs(s, cur->left);
            dfs(s, cur->right);
        };
        dfs("", root);
        return ans;
    }
};
