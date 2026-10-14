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
};

class Solution {
    private int i;
    private String s;
    
    public TreeNode str2tree(String s) {
        if (s == null || s.length() == 0) return null;
        this.s = s;
        this.i = 0;
        return dfs();
    }
    
    private TreeNode dfs() {
        if (i >= s.length()) return null;
        // parse number (could be negative)
        int sign = 1;
        if (s.charAt(i) == '-') {
            sign = -1;
            i++;
        }
        int num = 0;
        while (i < s.length() && Character.isDigit(s.charAt(i))) {
            num = num * 10 + (s.charAt(i) - '0');
            i++;
        }
        num *= sign;
        TreeNode node = new TreeNode(num);
        // left child
        if (i < s.length() && s.charAt(i) == '(') {
            i++; // skip '('
            node.left = dfs();
            // after left subtree, expect ')'
            if (i < s.length() && s.charAt(i) == ')') {
                i++; // skip ')'
            }
        }
        // right child
        if (i < s.length() && s.charAt(i) == '(') {
            i++; // skip '('
            node.right = dfs();
            if (i < s.length() && s.charAt(i) == ')') {
                i++; // skip ')'
            }
        }
        return node;
    }
}
