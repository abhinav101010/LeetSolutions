class Solution {
    double best=0;
    public double maximumAverageSubtree(TreeNode root) {
        dfs(root); return best;
    }
    int[] dfs(TreeNode n){
        if(n==null) return new int[]{0,0};
        int[] l=dfs(n.left), r=dfs(n.right);
        int s=n.val+l[0]+r[0], c=1+l[1]+r[1];
        best=Math.max(best,(double)s/c);
        return new int[]{s,c};
    }
}