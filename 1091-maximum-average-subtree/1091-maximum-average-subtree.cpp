#include <utility>
#include <algorithm>
using namespace std;
struct TreeNode {
    int val; TreeNode *left; TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
    double ans = 0;
    pair<int,int> dfs(TreeNode* node) {
        if (!node) return {0,0};
        auto l = dfs(node->left), r = dfs(node->right);
        int total = l.first + r.first + node->val;
        int count = l.second + r.second + 1;
        ans = max(ans, (double)total/count);
        return {total, count};
    }
public:
    double maximumAverageSubtree(TreeNode* root) {
        dfs(root);
        return ans;
    }
};
