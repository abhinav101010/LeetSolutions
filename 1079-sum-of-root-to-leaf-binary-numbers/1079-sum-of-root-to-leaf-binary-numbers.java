class TreeNode {
    int val; TreeNode left; TreeNode right;
    TreeNode() {}
    TreeNode(int val) { this.val = val; }
    TreeNode(int val, TreeNode left, TreeNode right) { this.val = val; this.left = left; this.right = right; }
}
class Solution {
    int ans = 0;
    public int sumRootToLeaf(TreeNode root) { dfs(root, 0); return ans; }
    private void dfs(TreeNode node, int val) {
        if (node == null) return;
        val = (val << 1) | node.val;
        if (node.left == null && node.right == null) { ans += val; return; }
        dfs(node.left, val); dfs(node.right, val);
    }
}
