/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    private int res = 0;
    
    private int dfs(TreeNode node) {
        if (node == null) return 0;
        int left = dfs(node.left);
        int right = dfs(node.right);
        int leftLen = (node.left != null && node.left.val == node.val) ? left + 1 : 1;
        int rightLen = (node.right != null && node.right.val == node.val) ? right + 1 : 1;
        res = Math.max(res, left + right);
        return Math.max(leftLen, rightLen);
    }
    
    public int longestUnivaluePath(TreeNode root) {
        dfs(root);
        return res;
    }
}