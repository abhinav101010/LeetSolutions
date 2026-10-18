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
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    TreeNode* str2tree(string s) {
        if (s.empty()) return nullptr;
        stack<TreeNode*> st;
        int i = 0;
        while (i < s.size()) {
            if (s[i] == '(' || s[i] == ')') {
                ++i;
                continue;
            }
            int sign = 1;
            if (s[i] == '-' || s[i] == '+') {
                sign = (s[i++] == '-') ? -1 : 1;
            }
            int num = 0;
            while (i < s.size() && isdigit(s[i])) {
                num = num * 10 + (s[i++] - '0');
            }
            TreeNode* node = new TreeNode(sign * num);
            if (!st.empty()) {
                TreeNode* parent = st.top();
                if (parent->left == nullptr) {
                    parent->left = node;
                } else {
                    parent->right = node;
                }
            }
            st.push(node);
            if (i < s.size() && s[i] == ')') {
                st.pop();
                ++i;
            }
        }
        return st.empty() ? nullptr : st.top();
    }
};
