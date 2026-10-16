import java.util.*;
// Definition for a binary tree node.
class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode() {}
    TreeNode(int val) { this.val = val; }
    TreeNode(int val, TreeNode left, TreeNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}
class Solution {
    private List<Integer> res;
    private int i;
    public List<Integer> flipMatchVoyage(TreeNode root, int[] voyage) {
        res = new ArrayList<>();
        i = 0;
        if (dfs(root, voyage)) return res;
        return Arrays.asList(-1);
    }
    private boolean dfs(TreeNode node, int[] voyage) {
        if (node == null || i == voyage.length) return true;
        if (node.val != voyage[i]) return false;
        i++;
        if (node.left != null && node.left.val == voyage[i]) {
            return dfs(node.left, voyage) && dfs(node.right, voyage);
        }
        if (node.right != null && node.right.val == voyage[i]) {
            res.add(node.val);
            return dfs(node.right, voyage) && dfs(node.left, voyage);
        }
        return node.left == null && node.right == null;
    }
}
