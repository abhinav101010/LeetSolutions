class TreeNode {
    int val; TreeNode left; TreeNode right;
    TreeNode() {}
    TreeNode(int val) { this.val = val; }
    TreeNode(int val, TreeNode left, TreeNode right) { this.val = val; this.left = left; this.right = right; }
}
class Solution {
    int ans = 0;
    public int maxAncestorDiff(TreeNode root) {
        dfs(root, root.val, root.val);
        return ans;
    }
    void dfs(TreeNode node, int lo, int hi) {
        if (node == null) return;
        ans = Math.max(ans, Math.abs(node.val - lo));
        ans = Math.max(ans, Math.abs(node.val - hi));
        dfs(node.left, Math.min(lo, node.val), Math.max(hi, node.val));
        dfs(node.right, Math.min(lo, node.val), Math.max(hi, node.val));
    }
}
