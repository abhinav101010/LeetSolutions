/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

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
    ListNode* node;

public:
    TreeNode* build(int left, int right) {
        if (left > right) {
            return nullptr;
        }

        int mid = left + (right - left) / 2;

        TreeNode* leftChild = build(left, mid - 1);
        TreeNode* root = new TreeNode(node->val);
        root->left = leftChild;
        node = node->next;
        root->right = build(mid + 1, right);
        return root;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        node = head;
        int size = 0;
        while (node != nullptr) {
            size++;
            node = node->next;
        }
        node = head;
        return build(0, size - 1);
    }
};
