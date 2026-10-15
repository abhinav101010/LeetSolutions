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
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        unordered_map<int, int> index;
        for (int i = 0; i < post.size(); i++) {
            index[post[i]] = i;
        }
        return helper(pre, post, 0, pre.size(), 0, post.size(), index);
    }
private:
    TreeNode* helper(vector<int>& pre, vector<int>& post, int preL, int preR, int postL, int postR, unordered_map<int, int>& index) {
        if (preL >= preR) return nullptr;
        TreeNode* root = new TreeNode(pre[preL]);
        if (preL + 1 == preR) return root;
        int leftRootVal = pre[preL+1];
        int leftPostIdx = index[leftRootVal];
        int leftSize = leftPostIdx - postL + 1;
        root->left = helper(pre, post, preL+1, preL+1+leftSize, postL, postL+leftSize, index);
        root->right = helper(pre, post, preL+1+leftSize, preR, postL+leftSize, postR-1, index);
        return root;
    }
};
