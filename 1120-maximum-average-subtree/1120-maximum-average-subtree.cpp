class Solution {
public:
    double maximumAverageSubtree(TreeNode* root) {
        double best=0;
        function<pair<int,int>(TreeNode*)> dfs=[&](TreeNode* n)->pair<int,int>{
            if(!n) return {0,0};
            auto l=dfs(n->left), r=dfs(n->right);
            int s=n->val+l.first+r.first, c=1+l.second+r.second;
            best=max(best,(double)s/c);
            return {s,c};
        };
        dfs(root);
        return best;
    }
};