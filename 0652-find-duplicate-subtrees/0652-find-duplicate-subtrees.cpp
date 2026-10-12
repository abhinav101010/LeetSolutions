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
private:
    unordered_map<string, int> count;
    vector<TreeNode*> res;
    
    string dfs(TreeNode* node) {
        if (!node) return "#";
        string s = to_string(node->val) + "," + dfs(node->left) + "," + dfs(node->right);
        count[s]++;
        if (count[s] == 2) {
            res.push_back(node);
        }
        return s;
    }
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        dfs(root);
        return res;
    }
};