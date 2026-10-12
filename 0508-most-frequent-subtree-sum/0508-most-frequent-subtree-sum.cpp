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
private:
    unordered_map<int, int> count;
    
    int subtreeSum(TreeNode* node) {
        if (!node) return 0;
        int s = node->val + subtreeSum(node->left) + subtreeSum(node->right);
        count[s]++;
        return s;
    }

public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        subtreeSum(root);
        int maxFreq = 0;
        for (auto& [_, freq] : count) {
            maxFreq = max(maxFreq, freq);
        }
        
        vector<int> result;
        for (auto& [s, freq] : count) {
            if (freq == maxFreq) result.push_back(s);
        }
        return result;
    }
};