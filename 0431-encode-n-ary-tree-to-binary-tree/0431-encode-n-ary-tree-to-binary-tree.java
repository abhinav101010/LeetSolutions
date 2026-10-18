import java.util.*;

// Definition for a Node.
class Node {
    public int val;
    public List<Node> children;

    public Node() {}

    public Node(int _val) {
        val = _val;
    }

    public Node(int _val, List<Node> _children) {
        val = _val;
        children = _children;
    }
};

/**
 * Definition for a binary tree node.
 */
class TreeNode {
    public int val;
    public TreeNode left;
    public TreeNode right;
    public TreeNode() {}
    public TreeNode(int val) { this.val = val; }
    public TreeNode(int val, TreeNode left, TreeNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
};

class Codec {
    // Encodes an n-ary tree to a binary tree.
    public TreeNode encode(Node root) {
        if (root == null) return null;
        TreeNode bRoot = new TreeNode(root.val);
        if (root.children == null || root.children.size() == 0) return bRoot;
        // encode first child
        bRoot.left = encode(root.children.get(0));
        // link siblings via right pointers
        TreeNode cur = bRoot.left;
        for (int i = 1; i < root.children.size(); i++) {
            cur.right = encode(root.children.get(i));
            cur = cur.right;
        }
        return bRoot;
    }

    // Decodes your binary tree to an n-ary tree.
    public Node decode(TreeNode data) {
        if (data == null) return null;
        Node nRoot = new Node(data.val, new ArrayList<>());
        // first child is left of binary node
        TreeNode cur = data.left;
        while (cur != null) {
            nRoot.children.add(decode(cur));
            cur = cur.right;
        }
        return nRoot;
    }
}
