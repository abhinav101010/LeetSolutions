import java.util.*;
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
class Solution {
    public boolean isCompleteTree(TreeNode root) {
        if (root == null) return true;
        Deque<TreeNode> q = new ArrayDeque<>();
        q.addLast(root);
        boolean seenNull = false;
        while (!q.isEmpty()) {
            TreeNode node = q.pollFirst();
            if (node == null) {
                seenNull = true;
            } else {
                if (seenNull) return false;
                q.addLast(node.left);
                q.addLast(node.right);
            }
        }
        return true;
    }
}
