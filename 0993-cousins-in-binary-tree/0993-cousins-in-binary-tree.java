import java.util.*;

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
    private int xDepth = -1;
    private int yDepth = -1;
    private TreeNode xParent = null;
    private TreeNode yParent = null;

    public boolean isCousins(TreeNode root, int x, int y) {
        dfs(null, root, 0, x, y);
        return (xDepth == yDepth && xParent != yParent);
    }

    private void dfs(TreeNode parent, TreeNode root, int k, int x, int y) {
        if (root == null) {
            return;
        }
        if (root.val == x) {
            xParent = parent;
            xDepth = k;
        }
        if (root.val == y) {
            yParent = parent;
            yDepth = k;
        }
        if (xDepth == -1 || yDepth == -1) {
            dfs(root, root.left, k + 1, x, y);
            dfs(root, root.right, k + 1, x, y);
        }
    }
}
