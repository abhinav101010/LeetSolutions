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
    private long total;
    private boolean found;
    private TreeNode root;
    public boolean checkEqualTree(TreeNode root) {
        this.root = root;
        total = totalSum(root);
        found = false;
        dfs(root);
        return found;
    }
    
    private long totalSum(TreeNode node) {
        if (node == null) return 0;
        return node.val + totalSum(node.left) + totalSum(node.right);
    }
    
    private long dfs(TreeNode node) {
        if (node == null) return 0;
        long sum = node.val + dfs(node.left) + dfs(node.right);
        if (sum * 2 == total && node != root) {
            found = true;
        }
        return sum;
    }
}
