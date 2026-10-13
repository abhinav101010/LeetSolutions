import java.util.*;

class Solution {
    private int res = 0;
    
    public int largestBSTSubtree(TreeNode root) {
        dfs(root);
        return res;
    }
    
    private int[] dfs(TreeNode node) {
        if (node == null) {
            return new int[]{Integer.MAX_VALUE, Integer.MIN_VALUE, 0};
        }
        int[] left = dfs(node.left);
        int[] right = dfs(node.right);
        if (left[2] == -1 || right[2] == -1 || node.val <= left[1] || node.val >= right[0]) {
            return new int[]{0, 0, -1};
        }
        int size = left[2] + right[2] + 1;
        res = Math.max(res, size);
        return new int[]{Math.min(left[0], node.val), Math.max(right[1], node.val), size};
    }
}