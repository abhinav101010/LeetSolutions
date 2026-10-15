import java.util.*;

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
    public List<Integer> boundaryOfBinaryTree(TreeNode root) {
        List<Integer> res = new ArrayList<>();
        if (root == null) return res;
        if (root.left == null && root.right == null) {
            res.add(root.val);
            return res;
        }
        res.add(root.val);
        // left boundary
        TreeNode node = root.left;
        while (node != null) {
            if (node.left != null || node.right != null) {
                res.add(node.val);
            }
            if (node.left != null) {
                node = node.left;
            } else {
                node = node.right;
            }
        }
        // leaves
        addLeaves(root, res);
        // right boundary (store in reverse)
        Stack<Integer> stack = new Stack<>();
        node = root.right;
        while (node != null) {
            if (node.left != null || node.right != null) {
                stack.push(node.val);
            }
            if (node.right != null) {
                node = node.right;
            } else {
                node = node.left;
            }
        }
        while (!stack.isEmpty()) {
            res.add(stack.pop());
        }
        return res;
    }
    
    private void addLeaves(TreeNode node, List<Integer> res) {
        if (node == null) return;
        if (node.left == null && node.right == null) {
            res.add(node.val);
            return;
        }
        addLeaves(node.left, res);
        addLeaves(node.right, res);
    }
}
