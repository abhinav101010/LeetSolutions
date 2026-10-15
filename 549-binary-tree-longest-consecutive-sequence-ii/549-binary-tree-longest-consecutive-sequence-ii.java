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
    private int best;
    public int longestConsecutive(TreeNode root) {
        best = 0;
        dfs(root);
        return best;
    }
    private int[] dfs(TreeNode node) {
        if (node == null) return new int[]{0,0};
        int inc = 1, dec = 1;
        if (node.left != null) {
            int[] left = dfs(node.left);
            if (node.left.val == node.val + 1) {
                inc = left[0] + 1;
            } else if (node.left.val == node.val - 1) {
                dec = left[1] + 1;
            }
        }
        if (node.right != null) {
            int[] right = dfs(node.right);
            if (node.right.val == node.val + 1) {
                inc = Math.max(inc, right[0] + 1);
            } else if (node.right.val == node.val - 1) {
                dec = Math.max(dec, right[1] + 1);
            }
        }
        best = Math.max(best, inc + dec - 1);
        return new int[]{inc, dec};
    }
}
