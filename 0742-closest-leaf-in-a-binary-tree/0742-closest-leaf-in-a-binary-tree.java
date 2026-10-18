import java.util.*;

/* Definition for a binary tree node. */
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
    public int findClosestLeaf(TreeNode root, int k) {
        // Build adjacency list using map from TreeNode to list of TreeNode
        Map<TreeNode, List<TreeNode>> graph = new HashMap<>();
        dfs(root, null, graph);
        // Find target node
        TreeNode target = null;
        for (TreeNode node : graph.keySet()) {
            if (node.val == k) {
                target = node;
                break;
            }
        }
        if (target == null) return -1; // should not happen
        // BFS from target
        Queue<TreeNode> q = new LinkedList<>();
        Set<TreeNode> visited = new HashSet<>();
        q.offer(target);
        visited.add(target);
        while (!q.isEmpty()) {
            TreeNode node = q.poll();
            // leaf in original tree: no left and right child
            if (node.left == null && node.right == null) {
                return node.val;
            }
            for (TreeNode nei : graph.getOrDefault(node, Collections.emptyList())) {
                if (!visited.contains(nei)) {
                    visited.add(nei);
                    q.offer(nei);
                }
            }
        }
        return -1; // should not happen
    }
    
    private void dfs(TreeNode node, TreeNode parent, Map<TreeNode, List<TreeNode>> graph) {
        if (node == null) return;
        graph.putIfAbsent(node, new ArrayList<>());
        if (parent != null) {
            graph.get(node).add(parent);
            graph.get(parent).add(node);
        }
        dfs(node.left, node, graph);
        dfs(node.right, node, graph);
    }
}
