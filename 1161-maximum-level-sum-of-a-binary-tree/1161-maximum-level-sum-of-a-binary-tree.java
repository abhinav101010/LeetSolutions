import java.util.*;

class Solution {
    public int maxLevelSum(TreeNode root) {
        List<Integer> levelSum = new ArrayList<>();
        dfs(root, 0, levelSum);
        int ans = 0;
        for (int i = 0; i < levelSum.size(); i++) {
            if (levelSum.get(i) > levelSum.get(ans)) ans = i;
        }
        return ans + 1;
    }

    private void dfs(TreeNode node, int level, List<Integer> levelSum) {
        if (node == null) return;
        if (level == levelSum.size()) {
            levelSum.add(node.val);
        } else {
            levelSum.set(level, levelSum.get(level) + node.val);
        }
        dfs(node.left, level + 1, levelSum);
        dfs(node.right, level + 1, levelSum);
    }
}

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
