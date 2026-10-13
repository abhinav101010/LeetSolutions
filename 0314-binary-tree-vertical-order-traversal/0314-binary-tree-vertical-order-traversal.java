import java.util.*;

class Solution {
    public List<List<Integer>> verticalOrder(TreeNode root) {
        if (root == null) return new ArrayList<>();
        Map<Integer, List<Integer>> map = new TreeMap<>();
        Queue<int[]> q = new LinkedList<>();
        q.offer(new int[]{0, root.val}); // column, value
        Queue<TreeNode> nodes = new LinkedList<>();
        nodes.offer(root);
        while (!q.isEmpty()) {
            int[] cur = q.poll();
            TreeNode node = nodes.poll();
            int col = cur[0];
            int val = cur[1];
            map.computeIfAbsent(col, k -> new ArrayList<>()).add(val);
            if (node.left != null) {
                q.offer(new int[]{col - 1, node.left.val});
                nodes.offer(node.left);
            }
            if (node.right != null) {
                q.offer(new int[]{col + 1, node.right.val});
                nodes.offer(node.right);
            }
        }
        return new ArrayList<>(map.values());
    }
}