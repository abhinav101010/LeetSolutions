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
    public int sumOfLeftLeaves(TreeNode root) {
        int ans = 0;
        dfs(root, false, ans);
        return ans;
    }

    private void dfs(TreeNode root, boolean isLeft, int[] ans) {
        if (root == null) return;
        if (root.left == null && root.right == null && isLeft) {
            ans[0] += root.val;
        }
        dfs(root.left, true, ans);
        dfs(root.right, false, ans);
    }
}