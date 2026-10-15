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
    public TreeNode constructFromPrePost(int[] pre, int[] post) {
        Map<Integer, Integer> index = new HashMap<>();
        for (int i = 0; i < post.length; i++) {
            index.put(post[i], i);
        }
        return helper(pre, post, 0, pre.length, 0, post.length, index);
    }
    private TreeNode helper(int[] pre, int[] post, int preL, int preR, int postL, int postR, Map<Integer, Integer> index) {
        if (preL >= preR) return null;
        TreeNode root = new TreeNode(pre[preL]);
        if (preL + 1 == preR) return root;
        int leftRootVal = pre[preL+1];
        int leftPostIdx = index.get(leftRootVal);
        int leftSize = leftPostIdx - postL + 1;
        root.left = helper(pre, post, preL+1, preL+1+leftSize, postL, postL+leftSize, index);
        root.right = helper(pre, post, preL+1+leftSize, preR, postL+leftSize, postR-1, index);
        return root;
    }
}
