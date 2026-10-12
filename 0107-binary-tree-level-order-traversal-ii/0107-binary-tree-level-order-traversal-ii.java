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
    public List<List<Integer>> levelOrderBottom(TreeNode root) {
        int depth = height(root);
        List<List<Integer>> ans = new ArrayList<>();
        for (int i = 0; i < depth; i++) {
            ans.add(new ArrayList<>());
        }
        checkLevel(root, depth - 1, ans);
        return ans;
    }

    int height(TreeNode root) {
        if (root == null) {
            return 0;
        }
        return 1 + Math.max(height(root.left), height(root.right));
    }

    void checkLevel(TreeNode root, int level, List<List<Integer>> ans) {
        if (root == null) {
            return;
        }
        ans.get(level).add(root.val);
        checkLevel(root.left, level - 1, ans);
        checkLevel(root.right, level - 1, ans);
    }
}
