#include <string>
#include <algorithm>
using namespace std;
struct TreeNode {
    int val; TreeNode *left,*right;
    TreeNode():val(0),left(nullptr),right(nullptr){}
    TreeNode(int x):val(x),left(nullptr),right(nullptr){}
    TreeNode(int x,TreeNode*l,TreeNode*r):val(x),left(l),right(r){}
};
class Solution {
    string ans = "~";
    void dfs(TreeNode* node, string path) {
        if (!node) return;
        path += ('a' + node->val);
        if (!node->left && !node->right) {
            string s = path;
            reverse(s.begin(), s.end());
            if (s < ans) ans = s;
            return;
        }
        if (node->left) dfs(node->left, path);
        if (node->right) dfs(node->right, path);
    }
public:
    string smallestFromLeaf(TreeNode* root) {
        dfs(root, "");
        return ans;
    }
};
