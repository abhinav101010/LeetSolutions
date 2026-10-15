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
    private int ans;
    public int minCameraCover(TreeNode root) {
        ans = 0;
        int rootState = dfs(root);
        return (rootState == 0 ? 1 : 0) + ans;
    }
    private int dfs(TreeNode node) {
        if (node == null) return 2; // covered
        int left = dfs(node.left);
        int right = dfs(node.right);
        if (left == 0 || right == 0) {
            ans++;
            return 1; // has camera
        }
        if (left == 1 || right == 1) {
            return 2; // covered
        }
        return 0; // not covered
    }
}
