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
    class Pair {
        TreeNode node;
        int idx;
        Pair(TreeNode node, int idx) {
            this.node = node;
            this.idx = idx;
        }
    }
    
    public int widthOfBinaryTree(TreeNode root) {
        Queue<Pair> q = new LinkedList<>();
        q.offer(new Pair(root, 0));
        int maxWidth = 0;
        while (!q.isEmpty()) {
            int leftIdx = q.peek().idx;
            int size = q.size();
            int lastIdx = 0;
            for (int i = 0; i < size; i++) {
                Pair p = q.poll();
                lastIdx = p.idx;
                if (p.node.left != null) q.offer(new Pair(p.node.left, p.idx * 2));
                if (p.node.right != null) q.offer(new Pair(p.node.right, p.idx * 2 + 1));
            }
            maxWidth = Math.max(maxWidth, lastIdx - leftIdx + 1);
        }
        return maxWidth;
    }
}