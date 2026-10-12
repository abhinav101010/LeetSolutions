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
import java.util.HashSet;
import java.util.Set;

class Solution {
    private Set<Integer> seen = new HashSet<>();
    
    public boolean findTarget(TreeNode root, int k) {
        return dfs(root, k);
    }
    
    private boolean dfs(TreeNode node, int k) {
        if (node == null) {
            return false;
        }
        if (seen.contains(k - node.val)) {
            return true;
        }
        seen.add(node.val);
        return dfs(node.left, k) || dfs(node.right, k);
    }
}
