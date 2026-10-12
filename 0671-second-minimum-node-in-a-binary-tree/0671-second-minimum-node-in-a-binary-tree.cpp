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
    void dfs(TreeNode* node, set<int>& s) {
        if (node == nullptr) {
            return;
        }
        s.insert(node->val);
        dfs(node->left, s);
        dfs(node->right, s);
    }
    
    int findSecondMinimumValue(TreeNode* root) {
        set<int> s;
        dfs(root, s);
        if (s.size() < 2) {
            return -1;
        }
        auto it = s.begin();
        ++it;
        return *it;
    }
};
