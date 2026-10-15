/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
     * TreeNode *left;
     * TreeNode *right;
     * TreeNode() : val(0), left(nullptr), right(nullptr) {}
     * TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     * TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class CBTInserter {
private:
    vector<TreeNode*> tree;
    TreeNode* root;
public:
    CBTInserter(TreeNode* root) {
        this->root = root;
        deque<TreeNode*> st;
        st.push_back(root);
        while (!st.empty()) {
            TreeNode* node = st.front(); st.pop_front();
            tree.push_back(node);
            if (node->left) st.push_back(node->left);
            if (node->right) st.push_back(node->right);
        }
    }
    
    int insert(int v) {
        TreeNode* node = new TreeNode(v);
        tree.push_back(node);
        int n = tree.size();
        TreeNode* parent = tree[(n-2)/2];
        if (n % 2 == 0)
            parent->left = node;
        else
            parent->right = node;
        return parent->val;
    }
    
    TreeNode* get_root() {
        return root;
    }
};
