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
    private int count;
    private Map<Long, Integer> prefixSum;
    
    public int pathSum(TreeNode root, int targetSum) {
        count = 0;
        prefixSum = new HashMap<>();
        prefixSum.put(0L, 1);
        dfs(root, 0, targetSum);
        return count;
    }
    
    private void dfs(TreeNode node, long currentSum, int targetSum) {
        if (node == null) return;
        
        currentSum += node.val;
        count += prefixSum.getOrDefault(currentSum - targetSum, 0);
        prefixSum.put(currentSum, prefixSum.getOrDefault(currentSum, 0) + 1);
        
        dfs(node.left, currentSum, targetSum);
        dfs(node.right, currentSum, targetSum);
        
        prefixSum.put(currentSum, prefixSum.get(currentSum) - 1);
    }
}