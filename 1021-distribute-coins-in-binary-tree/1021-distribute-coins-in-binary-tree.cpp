#include <cstdlib>
using namespace std;
struct TreeNode {
    int val; TreeNode *left,*right;
    TreeNode():val(0),left(nullptr),right(nullptr){}
    TreeNode(int x):val(x),left(nullptr),right(nullptr){}
    TreeNode(int x,TreeNode*l,TreeNode*r):val(x),left(l),right(r){}
};
class Solution {
    int ans;
    int dfs(TreeNode* node) {
        if (!node) return 0;
        int left=dfs(node->left), right=dfs(node->right);
        ans += abs(left)+abs(right);
        return node->val+left+right-1;
    }
public:
    int distributeCoins(TreeNode* root) {
        ans=0; dfs(root); return ans;
    }
};
