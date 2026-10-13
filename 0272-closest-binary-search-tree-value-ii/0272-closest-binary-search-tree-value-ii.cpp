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
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        vector<int> res;
        stack<int> s1, s2;
        function<void(TreeNode*, bool)> inorder = [&](TreeNode* node, bool isLeft) {
            if (!node) return;
            if (isLeft) {
                inorder(node->left, true);
                if ((double)node->val <= target) s1.push(node->val);
                else return;
                inorder(node->right, true);
            } else {
                inorder(node->right, false);
                if ((double)node->val > target) s2.push(node->val);
                else return;
                inorder(node->left, false);
            }
        };
        inorder(root, true);
        inorder(root, false);
        while (k--) {
            if (s1.empty()) {
                res.push_back(s2.top()); s2.pop();
            } else if (s2.empty()) {
                res.push_back(s1.top()); s1.pop();
            } else if (abs((double)s1.top() - target) < abs((double)s2.top() - target)) {
                res.push_back(s1.top()); s1.pop();
            } else {
                res.push_back(s2.top()); s2.pop();
            }
        }
        return res;
    }
};