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
    public int[] findMode(TreeNode root) {
        Map<Integer, Integer> count = new HashMap<>();
        dfs(root, count);
        int maxCount = 0;
        for (int c : count.values()) {
            maxCount = Math.max(maxCount, c);
        }
        List<Integer> modes = new ArrayList<>();
        for (Map.Entry<Integer, Integer> entry : count.entrySet()) {
            if (entry.getValue() == maxCount) {
                modes.add(entry.getKey());
            }
        }
        return modes.stream().mapToInt(i -> i).toArray();
    }
    
    private void dfs(TreeNode root, Map<Integer, Integer> count) {
        if (root == null) return;
        count.put(root.val, count.getOrDefault(root.val, 0) + 1);
        dfs(root.left, count);
        dfs(root.right, count);
    }
}