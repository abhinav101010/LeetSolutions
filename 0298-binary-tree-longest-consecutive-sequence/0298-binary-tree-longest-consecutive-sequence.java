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
    
    public int longestConsecutive(TreeNode root) {
        dfs(root, null, 0);
        return res;
    }
    
    private void dfs(TreeNode node, TreeNode parent, int len) {
        if (node == null) return;
        if (parent != null && parent.val + 1 == node.val) {
            len++;
        } else {
            len = 1;
        }
        res = Math.max(res, len);
        dfs(node.left, node, len);
        dfs(node.right, node, len);
    }
}