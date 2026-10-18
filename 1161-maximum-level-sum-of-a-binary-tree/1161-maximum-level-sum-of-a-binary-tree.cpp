#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        vector<int> levelSum;
        dfs(root, 0, levelSum);
        int ans = 0;
        for (int i = 0; i < (int)levelSum.size(); i++) {
            if (levelSum[i] > levelSum[ans]) ans = i;
        }
        return ans + 1;
    }

private:
    void dfs(TreeNode* node, int level, vector<int>& levelSum) {
        if (!node) return;
        if (level == (int)levelSum.size()) {
            levelSum.push_back(node->val);
        } else {
            levelSum[level] += node->val;
        }
        dfs(node->left, level + 1, levelSum);
        dfs(node->right, level + 1, levelSum);
    }
};
