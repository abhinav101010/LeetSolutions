class Solution {
    static class Pair{int depth;TreeNode node;Pair(int d,TreeNode n){depth=d;node=n;}}
    public TreeNode lcaDeepestLeaves(TreeNode root) {
        return dfs(root).node;
    }
    Pair dfs(TreeNode n){
        if(n==null) return new Pair(0,null);
        Pair l=dfs(n.left), r=dfs(n.right);
        if(l.depth>r.depth) return new Pair(l.depth+1,l.node);
        if(r.depth>l.depth) return new Pair(r.depth+1,r.node);
        return new Pair(l.depth+1,n);
    }
}