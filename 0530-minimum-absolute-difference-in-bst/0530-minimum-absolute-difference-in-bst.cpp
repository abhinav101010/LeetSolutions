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
#include <vector>
#include <climits>
#include <algorithm>

class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
        std::vector<int> nums;
        inorder(root, nums);
        int ans = INT_MAX;
        for (size_t i = 1; i < nums.size(); ++i) {
            ans = std::min(ans, nums[i] - nums[i - 1]);
        }
        return ans;
    }
    
private:
    void inorder(TreeNode* root, std::vector<int>& nums) {
        if (!root) return;
        inorder(root->left, nums);
        nums.push_back(root->val);
        inorder(root->right, nums);
    }
};