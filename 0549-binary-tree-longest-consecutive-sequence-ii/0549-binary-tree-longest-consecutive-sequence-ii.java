public class Solution {
    public static class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;
        TreeNode() {}
        TreeNode(int val) { this.val = val; }
        TreeNode(int val, TreeNode left, TreeNode right) {
            this.val = val; this.left = left; this.right = right;
        }
    }
    private int maxLen = 0;
    private int[] dfs(TreeNode root) {
        if (root == null) return new int[]{0, 0};
        int d1 = 1, d2 = 1;
        int[] left = dfs(root.left);
        int[] right = dfs(root.right);
        if (root.left != null) {
            if (root.left.val == root.val + 1) d1 = Math.max(d1, left[0] + 1);
            if (root.left.val == root.val - 1) d2 = Math.max(d2, left[1] + 1);
        }
        if (root.right != null) {
            if (root.right.val == root.val + 1) d1 = Math.max(d1, right[0] + 1);
            if (root.right.val == root.val - 1) d2 = Math.max(d2, right[1] + 1);
        }
        maxLen = Math.max(maxLen, d1 + d2 - 1);
        return new int[]{d1, d2};
    }
    public int longestConsecutive(TreeNode root) {
        maxLen = 0;
        dfs(root);
        return maxLen;
    }
}
