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
import java.util.*;

class Solution {
    private Map<String, Integer> count = new HashMap<>();
    private List<TreeNode> res = new ArrayList<>();
    
    public List<TreeNode> findDuplicateSubtrees(TreeNode root) {
        dfs(root);
        return res;
    }
    
    private String dfs(TreeNode node) {
        if (node == null) return "#";
        String s = node.val + "," + dfs(node.left) + "," + dfs(node.right);
        count.put(s, count.getOrDefault(s, 0) + 1);
        if (count.get(s) == 2) {
            res.add(node);
        }
        return s;
    }
}