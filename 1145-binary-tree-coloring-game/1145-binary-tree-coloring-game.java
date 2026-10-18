class Solution {
    int[] sz=new int[2];
    int dfs(TreeNode node,int x){
        if(node==null) return 0;
        int l=dfs(node.left,x), r=dfs(node.right,x);
        if(node.val==x){sz[0]=l; sz[1]=r;}
        return l+r+1;
    }
    public boolean btreeGameWinningMove(TreeNode root, int n, int x) {
        dfs(root,x);
        int parent=n-1-sz[0]-sz[1];
        return Math.max(Math.max(sz[0],sz[1]),parent)>n/2;
    }}
