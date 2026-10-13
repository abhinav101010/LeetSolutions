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
    public int closestValue(TreeNode root, double target) {
        int res = root.val;
        TreeNode cur = root;
        while (cur != null) {
            if (Math.abs(cur.val - target) < Math.abs(res - target)) {
                res = cur.val;
            }
            if (target < cur.val) {
                cur = cur.left;
            } else {
                cur = cur.right;
            }
        }
        return res;
    }
}