// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
    Node(int v) : val(v), left(nullptr), right(nullptr), parent(nullptr) {}
};

class Solution {
public:
    Node* inorderSuccessor(Node* node) {
        if (node->right) {
            node = node->right;
            while (node->left) {
                node = node->left;
            }
            return node;
        }
        // go up until we are left child
        while (node->parent && node->parent->right == node) {
            node = node->parent;
        }
        return node->parent;
    }
};
