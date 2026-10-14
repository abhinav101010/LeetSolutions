#include <string>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
private:
    int i;
    string s;
    
    TreeNode* dfs() {
        if (i >= s.size()) return nullptr;
        // parse number (could be negative)
        int sign = 1;
        if (s[i] == '-') {
            sign = -1;
            i++;
        }
        long num = 0;
        while (i < s.size() && isdigit(s[i])) {
            num = num * 10 + (s[i] - '0');
            i++;
        }
        num *= sign;
        TreeNode* node = new TreeNode((int)num);
        // left child
        if (i < s.size() && s[i] == '(') {
            i++; // skip '('
            node->left = dfs();
            // after left subtree, expect ')'
            if (i < s.size() && s[i] == ')') {
                i++; // skip ')'
            }
        }
        // right child
        if (i < s.size() && s[i] == '(') {
            i++; // skip '('
            node->right = dfs();
            if (i < s.size() && s[i] == ')') {
                i++; // skip ')'
            }
        }
        return node;
    }
public:
    TreeNode* str2tree(string s) {
        if (s.empty()) return nullptr;
        this->s = s;
        this->i = 0;
        return dfs();
    }
};
