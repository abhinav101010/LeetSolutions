struct TreeNode {
    int val; TreeNode *left; TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
#include <stack>
#include <string>
using namespace std;
class Solution {
public:
    TreeNode* recoverFromPreorder(string s) {
        int i = 0;
        stack<TreeNode*> st;
        while (i < s.size()) {
            int depth = 0;
            while (i < s.size() && s[i] == '-') { depth++; i++; }
            int val = 0;
            while (i < s.size() && isdigit(s[i])) { val = val * 10 + (s[i] - '0'); i++; }
            TreeNode* node = new TreeNode(val);
            while (st.size() > depth) st.pop();
            if (!st.empty()) {
                if (st.top()->left == nullptr) st.top()->left = node;
                else st.top()->right = node;
            }
            st.push(node);
        }
        return st.top();
    }
};
