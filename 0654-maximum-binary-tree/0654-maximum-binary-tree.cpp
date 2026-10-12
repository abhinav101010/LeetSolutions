/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return build(nums, 0, nums.size() - 1);
    }
    
private:
    TreeNode* build(const vector<int>& nums, int l, int r) {
        if (l > r) return nullptr;
        int maxIdx = l;
        for (int i = l; i <= r; i++) {
            if (nums[i] > nums[maxIdx]) maxIdx = i;
        }
        TreeNode* root = new TreeNode(nums[maxIdx]);
        root->left = build(nums, l, maxIdx - 1);
        root->right = build(nums, maxIdx + 1, r);
        return root;
    }
};