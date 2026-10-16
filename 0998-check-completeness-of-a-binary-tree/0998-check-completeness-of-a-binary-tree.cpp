// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
#include <deque>
using namespace std;

class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        if (!root) return true;
        deque<TreeNode*> q;
        q.push_back(root);
        bool seenNull = false;
        while (!q.empty()) {
            TreeNode* node = q.front(); q.pop_front();
            if (!node) {
                seenNull = true;
            } else {
                if (seenNull) return false;
                q.push_back(node->left);
                q.push_back(node->right);
            }
        }
        return true;
    }
};
