import java.util.*;
class TreeNode {
    int val; TreeNode left,right;
    TreeNode(){} TreeNode(int v){val=v;}
    TreeNode(int v,TreeNode l,TreeNode r){val=v;left=l;right=r;}
}
class Solution {
    private int ans;
    public int distributeCoins(TreeNode root) {
        ans=0; dfs(root); return ans;
    }
    private int dfs(TreeNode node) {
        if (node==null) return 0;
        int left=dfs(node.left), right=dfs(node.right);
        ans += Math.abs(left)+Math.abs(right);
        return node.val+left+right-1;
    }
}
