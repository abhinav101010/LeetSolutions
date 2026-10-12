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
import java.util.*;

class Solution {
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        List<List<Integer>> ans = new ArrayList<>();

        if (root == null) {
            return ans;
        }

        Deque<TreeNode> deque = new ArrayDeque<>();
        deque.add(root);
        boolean leftToRight = true;

        while (!deque.isEmpty()) {
            int size = deque.size();
            Integer[] level = new Integer[size];

            for (int i = 0; i < size; i++) {
                TreeNode node = deque.poll();
                int index = leftToRight ? i : size - 1 - i;
                level[index] = node.val;

                if (node.left != null) {
                    deque.add(node.left);
                }
                if (node.right != null) {
                    deque.add(node.right);
                }
            }

            ans.add(Arrays.asList(level));
            leftToRight = !leftToRight;
        }

        return ans;
    }
}
