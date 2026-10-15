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
public:
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        ans.clear();
        index = 0;
        this->voyage = voyage;
        if (dfs(root)) {
            return ans;
        } else {
            return {-1};
        }
    }
private:
    int index;
    vector<int> voyage;
    vector<int> ans;
    bool dfs(TreeNode* node) {
        if (!node) return true;
        if (node->val != voyage[index]) {
            ans.clear();
            ans.push_back(-1);
            return false;
        }
        index++;
        if (index == voyage.size()) return true;
        // if left exists and matches next, continue; else try flip
        if (node->left && node->left->val == voyage[index]) {
            if (!dfs(node->left)) return false;
            if (!dfs(node->right)) return false;
        } else {
            // need to flip
            if (node->right) {
                ans.push_back(node->val);
            }
            if (!dfs(node->right)) return false;
            if (!dfs(node->left)) return false;
        }
        return true;
    }
};
