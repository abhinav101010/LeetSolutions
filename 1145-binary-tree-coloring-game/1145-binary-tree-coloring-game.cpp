class Solution {
public:
    int sz[2]={0,0};
    int dfs(TreeNode* node,int x){
        if(!node) return 0;
        int l=dfs(node->left,x), r=dfs(node->right,x);
        if(node->val==x){sz[0]=l; sz[1]=r;}
        return l+r+1;
    }
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        dfs(root,x);
        int parent=n-1-sz[0]-sz[1];
        return max({sz[0],sz[1],parent})>n/2;
    }}
