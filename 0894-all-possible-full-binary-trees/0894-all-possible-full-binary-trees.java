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
    public List<TreeNode> allPossibleFBT(int n) {
        Map<Integer, List<TreeNode>> memo = new HashMap<>();
        memo.put(0, new ArrayList<>());
        List<TreeNode> base = new ArrayList<>();
        base.add(new TreeNode(0));
        memo.put(1, base);
        return dfs(n, memo);
    }
    private List<TreeNode> dfs(int n, Map<Integer, List<TreeNode>> memo) {
        if (memo.containsKey(n)) {
            return memo.get(n);
        }
        List<TreeNode> res = new ArrayList<>();
        for (int left = 1; left < n; left += 2) {
            int right = n - 1 - left;
            for (TreeNode leftTree : dfs(left, memo)) {
                for (TreeNode rightTree : dfs(right, memo)) {
                    TreeNode root = new TreeNode(0);
                    root.left = leftTree;
                    root.right = rightTree;
                    res.add(root);
                }
            }
        }
        memo.put(n, res);
        return res;
    }
}
