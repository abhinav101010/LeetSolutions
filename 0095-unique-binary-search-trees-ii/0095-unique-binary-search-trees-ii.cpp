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
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return {};
        return generate(1, n);
    }
    
private:
    vector<TreeNode*> generate(int start, int end) {
        vector<TreeNode*> result;
        if (start > end) {
            result.push_back(nullptr);
            return result;
        }
        
        for (int rootVal = start; rootVal <= end; rootVal++) {
            vector<TreeNode*> leftTrees = generate(start, rootVal - 1);
            vector<TreeNode*> rightTrees = generate(rootVal + 1, end);
            
            for (TreeNode* left : leftTrees) {
                for (TreeNode* right : rightTrees) {
                    TreeNode* root = new TreeNode(rootVal);
                    root->left = left;
                    root->right = right;
                    result.push_back(root);
                }
            }
        }
        
        return result;
    }
};