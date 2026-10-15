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
#include <stack>
using namespace std;

class Solution {
private:
    void addLeaves(TreeNode* node, vector<int>& res) {
        if (!node) return;
        if (!node->left && !node->right) {
            res.push_back(node->val);
            return;
        }
        addLeaves(node->left, res);
        addLeaves(node->right, res);
    }
public:
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        vector<int> res;
        if (!root) return res;
        if (!root->left && !root->right) {
            res.push_back(root->val);
            return res;
        }
        res.push_back(root->val);
        // left boundary
        TreeNode* node = root->left;
        while (node) {
            if (node->left || node->right) {
                res.push_back(node->val);
            }
            if (node->left) {
                node = node->left;
            } else {
                node = node->right;
            }
        }
        // leaves
        addLeaves(root, res);
        // right boundary
        stack<int> st;
        node = root->right;
        while (node) {
            if (node->left || node->right) {
                st.push(node->val);
            }
            if (node->right) {
                node = node->right;
            } else {
                node = node->left;
            }
        }
        while (!st.empty()) {
            res.push_back(st.top());
            st.pop();
        }
        return res;
    }
};
