// Definition for a binary tree node.
class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode() {}
    TreeNode(int val) { this.val = val; }
    TreeNode(int val, TreeNode left, TreeNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}
import java.util.*;
class Solution {
    private List<Integer> ans = new ArrayList<>();
    private int index = 0;
    private int[] voyage;
    public List<Integer> flipMatchVoyage(TreeNode root, int[] voyage) {
        this.voyage = voyage;
        this.ans.clear();
        this.index = 0;
        if (dfs(root)) {
            return ans;
        } else {
            return Arrays.asList(-1);
        }
    }
    private boolean dfs(TreeNode node) {
        if (node == null) return true;
        if (node.val != voyage[index]) {
            ans.clear();
            ans.add(-1);
            return false;
        }
        index++;
        if (index == voyage.length) return true;
        // if left exists and matches next, continue; else try flip
        if (node.left != null && node.left.val == voyage[index]) {
            if (!dfs(node.left)) return false;
            if (!dfs(node.right)) return false;
        } else {
            // need to flip
            if (node.right != null) {
                ans.add(node.val);
            }
            if (!dfs(node.right)) return false;
            if (!dfs(node.left)) return false;
        }
        return true;
    }
}
