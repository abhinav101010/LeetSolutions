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
class Solution {
    private int getHeight(TreeNode node) {
        if (node == null) return 0;
        return 1 + Math.max(getHeight(node.left), getHeight(node.right));
    }
    
    public List<List<String>> printTree(TreeNode root) {
        int h = getHeight(root);
        int m = h, n = (1 << h) - 1;
        List<List<String>> res = new ArrayList<>();
        for (int i = 0; i < m; i++) {
            List<String> row = new ArrayList<>();
            for (int j = 0; j < n; j++) row.add("");
            res.add(row);
        }
        dfs(root, 0, 0, n - 1, res);
        return res;
    }
    
    private void dfs(TreeNode node, int row, int left, int right, List<List<String>> res) {
        if (node == null || left > right) return;
        int mid = (left + right) / 2;
        res.get(row).set(mid, String.valueOf(node.val));
        dfs(node.left, row + 1, left, mid - 1, res);
        dfs(node.right, row + 1, mid + 1, right, res);
    }
}