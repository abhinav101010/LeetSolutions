class Solution {
public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        function<pair<int,TreeNode*>(TreeNode*)> dfs=[&](TreeNode* n)->pair<int,TreeNode*>{
            if(!n) return {0,nullptr};
            auto l=dfs(n->left), r=dfs(n->right);
            if(l.first>r.first) return {l.first+1,l.second};
            if(r.first>l.first) return {r.first+1,r.second};
            return {l.first+1,n};
        };
        return dfs(root).second;
    }