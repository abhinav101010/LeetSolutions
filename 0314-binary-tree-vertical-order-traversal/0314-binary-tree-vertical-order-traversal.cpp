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
    vector<vector<int>> verticalOrder(TreeNode* root) {
        if (!root) return {};
        map<int, vector<int>> m;
        queue<pair<int, TreeNode*>> q;
        q.push({0, root});
        while (!q.empty()) {
            auto [col, node] = q.front(); q.pop();
            m[col].push_back(node->val);
            if (node->left) q.push({col - 1, node->left});
            if (node->right) q.push({col + 1, node->right});
        }
        vector<vector<int>> res;
        for (auto &p : m) {
            res.push_back(p.second);
        }
        return res;
    }
};