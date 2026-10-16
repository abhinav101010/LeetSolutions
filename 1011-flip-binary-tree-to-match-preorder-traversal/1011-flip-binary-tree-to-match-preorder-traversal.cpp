// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
#include <vector>
using namespace std;
class Solution {
    vector<int> res;
    int i;
public:
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        res.clear(); i = 0;
        if (dfs(root, voyage)) return res;
        return vector<int>{-1};
    }
private:
    bool dfs(TreeNode* node, vector<int>& voyage) {
        if (!node || i == voyage.size()) return true;
        if (node->val != voyage[i]) return false;
        i++;
        if (node->left && node->left->val == voyage[i]) {
            return dfs(node->left, voyage) && dfs(node->right, voyage);
        }
        if (node->right && node->right->val == voyage[i]) {
            res.push_back(node->val);
            return dfs(node->right, voyage) && dfs(node->left, voyage);
        }
        return !node->left && !node->right;
    }
};
