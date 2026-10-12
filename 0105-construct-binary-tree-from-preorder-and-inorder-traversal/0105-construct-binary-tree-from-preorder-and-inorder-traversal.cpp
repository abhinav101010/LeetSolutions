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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> inIndex;
        for (int i = 0; i < (int)inorder.size(); i++) {
            inIndex[inorder[i]] = i;
        }

        int prePos = 0;
        return build(preorder, inIndex, prePos, 0, (int)inorder.size() - 1);
    }

private:
    TreeNode* build(vector<int>& preorder, unordered_map<int, int>& inIndex, int& prePos, int inStart, int inEnd) {
        if (inStart > inEnd) {
            return nullptr;
        }

        int rootVal = preorder[prePos++];
        TreeNode* root = new TreeNode(rootVal);
        int mid = inIndex[rootVal];

        root->left = build(preorder, inIndex, prePos, inStart, mid - 1);
        root->right = build(preorder, inIndex, prePos, mid + 1, inEnd);

        return root;
    }
};
