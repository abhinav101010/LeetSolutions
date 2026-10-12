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
import java.util.TreeSet;

class Solution {
    private TreeSet<Integer> set = new TreeSet<>();
    public int findSecondMinimumValue(TreeNode root) {
        dfs(root);
        if (set.size() < 2) return -1;
        Integer first = set.first();
        Integer second = set.higher(first);
        return second == null ? -1 : second;
    }
    private void dfs(TreeNode node) {
        if (node == null) return;
        set.add(node.val);
        dfs(node.left);
        dfs(node.right);
    }
}
