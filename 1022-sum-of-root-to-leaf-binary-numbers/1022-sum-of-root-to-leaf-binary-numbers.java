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
    int ans = 0;

    public int sumRootToLeaf(TreeNode root) {
        generate("", root);
        return ans;
    }

    private void generate(String s, TreeNode root) {
        if (root == null) {
            return;
        }
        s += root.val;
        if (root.left == null && root.right == null) {
            ans += Integer.parseInt(s, 2);
            return;
        }
        generate(s, root.left);
        generate(s, root.right);
    }
}
