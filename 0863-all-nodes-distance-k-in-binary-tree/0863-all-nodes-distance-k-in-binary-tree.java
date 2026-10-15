import java.util.*;
 // Definition for a binary tree node.
class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x) { val = x; }
}
class Solution {
    public List<Integer> distanceK(TreeNode root, TreeNode target, int k) {
        Map<TreeNode, TreeNode> parent = new HashMap<>();
        dfs(root, null, parent);
        Queue<TreeNode> q = new ArrayDeque<>();
        Set<TreeNode> visited = new HashSet<>();
        q.offer(target);
        visited.add(target);
        int dist = 0;
        while (!q.isEmpty() && dist < k) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                TreeNode node = q.poll();
                if (node.left != null && !visited.contains(node.left)) {
                    visited.add(node.left);
                    q.offer(node.left);
                }
                if (node.right != null && !visited.contains(node.right)) {
                    visited.add(node.right);
                    q.offer(node.right);
                }
                TreeNode par = parent.get(node);
                if (par != null && !visited.contains(par)) {
                    visited.add(par);
                    q.offer(par);
                }
            }
            dist++;
        }
        List<Integer> ans = new ArrayList<>();
        for (TreeNode node : q) {
            ans.add(node.val);
        }
        return ans;
    }
    private void dfs(TreeNode node, TreeNode par, Map<TreeNode, TreeNode> parent) {
        if (node != null) {
            parent.put(node, par);
            dfs(node.left, node, parent);
            dfs(node.right, node, parent);
        }
    }
}
