#include <vector>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Codec {
public:
    // Encodes an n-ary tree to a binary tree.
    TreeNode* encode(Node* root) {
        if (!root) return nullptr;
        TreeNode* bRoot = new TreeNode(root->val);
        if (root->children.empty()) return bRoot;
        // encode first child
        bRoot->left = encode(root->children[0]);
        // link siblings via right pointers
        TreeNode* cur = bRoot->left;
        for (size_t i = 1; i < root->children.size(); i++) {
            cur->right = encode(root->children[i]);
            cur = cur->right;
        }
        return bRoot;
    }

    // Decodes your binary tree to an n-ary tree.
    Node* decode(TreeNode* data) {
        if (!data) return nullptr;
        Node* nRoot = new Node(data->val);
        // first child is left of binary node
        TreeNode* cur = data->left;
        while (cur) {
            nRoot->children.push_back(decode(cur));
            cur = cur->right;
        }
        return nRoot;
    }
};
