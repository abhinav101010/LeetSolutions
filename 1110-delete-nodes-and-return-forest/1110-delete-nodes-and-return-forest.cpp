class Solution {
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int> s(to_delete.begin(),to_delete.end());
        vector<TreeNode*> res;
        function<TreeNode*(TreeNode*,bool)> dfs=[&](TreeNode* node,bool isRoot)->TreeNode*{
            if(!node) return nullptr;
            bool del=s.count(node->val);
            if(isRoot && !del) res.push_back(node);
            node->left=dfs(node->left,del);
            node->right=dfs(node->right,del);
            return del?nullptr:node;
        };
        dfs(root,true);
        return res;
    }
};