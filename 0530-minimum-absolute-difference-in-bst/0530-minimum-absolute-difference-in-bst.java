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
    public int getMinimumDifference(TreeNode root) {
        List<Integer> nums = new ArrayList<>();
        inorder(root, nums);
        int ans = Integer.MAX_VALUE;
        for (int i = 1; i < nums.size(); i++) {
            ans = Math.min(ans, nums.get(i) - nums.get(i - 1));
        }
        return ans;
    }
    
    private void inorder(TreeNode root, List<Integer> nums) {
        if (root == null) return;
        inorder(root.left, nums);
        nums.add(root.val);
        inorder(root.right, nums);
    }
}