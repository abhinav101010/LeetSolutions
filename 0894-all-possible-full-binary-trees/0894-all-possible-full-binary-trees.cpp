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
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<TreeNode*> allPossibleFBT(int n) {
        unordered_map<int, vector<TreeNode*>> memo;
        memo[0] = {};
        memo[1] = {new TreeNode(0)};
        return dfs(n, memo);
    }
private:
    vector<TreeNode*> dfs(int n, unordered_map<int, vector<TreeNode*>>& memo) {
        if (memo.find(n) != memo.end()) {
            return memo[n];
        }
        vector<TreeNode*> res;
        for (int left = 1; left < n; left += 2) {
            int right = n - 1 - left;
            for (TreeNode* leftTree : dfs(left, memo)) {
                for (TreeNode* rightTree : dfs(right, memo)) {
                    TreeNode* root = new TreeNode(0);
                    root->left = leftTree;
                    root->right = rightTree;
                    res.push_back(root);
                }
            }
        }
        memo[n] = res;
        return res;
    }
};
