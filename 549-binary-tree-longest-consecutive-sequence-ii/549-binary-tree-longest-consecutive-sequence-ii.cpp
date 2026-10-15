// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#include <algorithm>
#include <utility>
using namespace std;

class Solution {
private:
    int best;
    pair<int,int> dfs(TreeNode* node) {
        if (!node) return make_pair(0,0);
        int inc = 1, dec = 1;
        if (node->left) {
            auto left = dfs(node->left);
            if (node->left->val == node->val + 1) {
                inc = left.first + 1;
            } else if (node->left->val == node->val - 1) {
                dec = left.second + 1;
            }
        }
        if (node->right) {
            auto right = dfs(node->right);
            if (node->right->val == node->val + 1) {
                inc = max(inc, right.first + 1);
            } else if (node->right->val == node->val - 1) {
                dec = max(dec, right.second + 1);
            }
        }
        best = max(best, inc + dec - 1);
        return make_pair(inc, dec);
    }
public:
    int longestConsecutive(TreeNode* root) {
        best = 0;
        dfs(root);
        return best;
    }
};
