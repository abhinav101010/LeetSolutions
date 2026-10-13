/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node() {}
    Node(int _val) {
        val = _val;
        left = nullptr;
        right = nullptr;
    }
    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/

class Solution {
public:
    Node* first = nullptr;
    Node* last = nullptr;
    void inorder(Node* node) {
        if (!node) return;
        inorder(node->left);
        if (!last) {
            first = node;
            last = node;
        } else {
            last->right = node;
            node->left = last;
            last = node;
        }
        inorder(node->right);
    }
    Node* treeToDoublyList(Node* root) {
        if (!root) return nullptr;
        inorder(root);
        first->left = last;
        last->right = first;
        return first;
    }
};