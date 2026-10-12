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
    public List<List<Integer>> pathSum(TreeNode root, int targetSum) {
        List<List<Integer>> ans = new ArrayList<>();
        List<Integer> path = new ArrayList<>();
        dfs(root, targetSum, path, ans);
        return ans;
    }

    void dfs(TreeNode root, int sum, List<Integer> path, List<List<Integer>> ans) {
        if (root == null) {
            return;
        }

        path.add(root.val);

        if (root.left == null && root.right == null && root.val == sum) {
            ans.add(new ArrayList<>(path));
        } else {
            dfs(root.left, sum - root.val, path, ans);
            dfs(root.right, sum - root.val, path, ans);
        }

        path.remove(path.size() - 1);
    }
}
