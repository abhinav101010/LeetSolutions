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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> st;
        TreeNode* curr = root;
        TreeNode* last = nullptr;
        while (curr || !st.empty()) {
            if (curr) {
                st.push(curr);
                curr = curr->left;
            } else {
                TreeNode* top = st.top();
                if (top->right && top->right != last) {
                    curr = top->right;
                } else {
                    ans.push_back(top->val);
                    last = top;
                    st.pop();
                }
            }
        }
        return ans;
    }
};