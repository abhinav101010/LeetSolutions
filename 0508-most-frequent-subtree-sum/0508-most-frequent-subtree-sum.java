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
    private Map<Integer, Integer> count = new HashMap<>();
    
    public int[] findFrequentTreeSum(TreeNode root) {
        subtreeSum(root);
        int maxFreq = 0;
        for (int freq : count.values()) {
            maxFreq = Math.max(maxFreq, freq);
        }
        
        List<Integer> result = new ArrayList<>();
        for (Map.Entry<Integer, Integer> entry : count.entrySet()) {
            if (entry.getValue() == maxFreq) {
                result.add(entry.getKey());
            }
        }
        return result.stream().mapToInt(i -> i).toArray();
    }
    
    private int subtreeSum(TreeNode node) {
        if (node == null) return 0;
        int s = node.val + subtreeSum(node.left) + subtreeSum(node.right);
        count.put(s, count.getOrDefault(s, 0) + 1);
        return s;
    }
}