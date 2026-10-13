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
    private int count = 0;
    
    public int countUnivalSubtrees(TreeNode root) {
        isUnival(root);
        return count;
    }
    
    private boolean isUnival(TreeNode node) {
        if (node == null) return true;
        boolean left = isUnival(node.left);
        boolean right = isUnival(node.right);
        if (left && right) {
            if ((node.left == null || node.left.val == node.val) && (node.right == null || node.right.val == node.val)) {
                count++;
                return true;
            }
        }
        return false;
    }
}