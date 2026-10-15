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

class CBTInserter {
    private List<TreeNode> tree = new ArrayList<>();
    private TreeNode root;

    public CBTInserter(TreeNode root) {
        this.root = root;
        Deque<TreeNode> stack = new ArrayDeque<>();
        stack.push(root);
        while (!stack.isEmpty()) {
            TreeNode node = stack.pop();
            tree.add(node);
            if (node.left != null) stack.push(node.left);
            if (node.right != null) stack.push(node.right);
        }
    }

    public int insert(int v) {
        TreeNode node = new TreeNode(v);
        int n = tree.size();
        tree.add(node);
        TreeNode parent = tree.get((n - 2) / 2);
        if (n % 2 == 0) {
            parent.left = node;
        } else {
            parent.right = node;
        }
        return parent.val;
    }

    public TreeNode get_root() {
        return root;
    }
}
