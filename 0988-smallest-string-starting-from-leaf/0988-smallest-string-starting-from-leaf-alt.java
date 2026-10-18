import java.util.*;
class TreeNode {
    int val; TreeNode left,right;
    TreeNode(){} TreeNode(int v){val=v;}
    TreeNode(int v,TreeNode l,TreeNode r){val=v;left=l;right=r;}
}
class Solution {
    private String ans = "~";
    public String smallestFromLeaf(TreeNode root) {
        dfs(root, new StringBuilder());
        return ans;
    }
    private void dfs(TreeNode node, StringBuilder path) {
        if (node == null) return;
        path.append((char)('a' + node.val));
        if (node.left == null && node.right == null) {
            String s = path.reverse().toString();
            if (s.compareTo(ans) < 0) ans = s;
            path.reverse();
            return;
        }
        dfs(node.left, path);
        dfs(node.right, path);
        path.deleteCharAt(path.length()-1);
    }
}
