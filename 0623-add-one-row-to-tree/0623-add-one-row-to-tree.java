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
    public TreeNode addOneRow(TreeNode root, int val, int depth) {
        if (depth == 1) {
            TreeNode newRoot = new TreeNode(val);
            newRoot.left = root;
            return newRoot;
        }
        dfs(root, 1, val, depth);
        return root;
    }
    
    private void dfs(TreeNode node, int currentDepth, int val, int depth) {
        if (node == null) return;
        if (currentDepth == depth - 1) {
            TreeNode newLeft = new TreeNode(val);
            TreeNode newRight = new TreeNode(val);
            newLeft.left = node.left;
            newRight.right = node.right;
            node.left = newLeft;
            node.right = newRight;
            return;
        }
        dfs(node.left, currentDepth + 1, val, depth);
        dfs(node.right, currentDepth + 1, val, depth);
    }
}