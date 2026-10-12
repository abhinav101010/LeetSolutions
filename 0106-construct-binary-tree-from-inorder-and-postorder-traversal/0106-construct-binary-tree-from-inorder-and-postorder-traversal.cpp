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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> inIndex;
        for (int i = 0; i < (int)inorder.size(); i++) {
            inIndex[inorder[i]] = i;
        }

        int postPos = (int)postorder.size() - 1;
        return build(postorder, inIndex, postPos, 0, (int)inorder.size() - 1);
    }

private:
    TreeNode* build(vector<int>& postorder, unordered_map<int, int>& inIndex, int& postPos, int inStart, int inEnd) {
        if (inStart > inEnd) {
            return nullptr;
        }

        int rootVal = postorder[postPos--];
        TreeNode* root = new TreeNode(rootVal);
        int mid = inIndex[rootVal];

        root->right = build(postorder, inIndex, postPos, mid + 1, inEnd);
        root->left = build(postorder, inIndex, postPos, inStart, mid - 1);

        return root;
    }
};
