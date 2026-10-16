class TreeNode {
    int val; TreeNode left; TreeNode right;
    TreeNode() {}
    TreeNode(int val) { this.val = val; }
    TreeNode(int val, TreeNode left, TreeNode right) { this.val = val; this.left = left; this.right = right; }
}
class Solution {
    double ans = 0;
    public double maximumAverageSubtree(TreeNode root) {
        dfs(root);
        return ans;
    }
    private int[] dfs(TreeNode node) {
        if (node == null) return new int[]{0,0};
        int[] l = dfs(node.left), r = dfs(node.right);
        int total = l[0]+r[0]+node.val;
        int count = l[1]+r[1]+1;
        ans = Math.max(ans, (double)total/count);
        return new int[]{total, count};
    }
}
