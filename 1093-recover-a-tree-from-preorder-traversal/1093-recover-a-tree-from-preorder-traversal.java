class TreeNode {
    int val; TreeNode left; TreeNode right;
    TreeNode() {}
    TreeNode(int val) { this.val = val; }
    TreeNode(int val, TreeNode left, TreeNode right) { this.val = val; this.left = left; this.right = right; }
}
class Solution {
    public TreeNode recoverFromPreorder(String s) {
        int i = 0;
        java.util.Stack<TreeNode> stack = new java.util.Stack<>();
        while (i < s.length()) {
            int depth = 0;
            while (i < s.length() && s.charAt(i) == '-') { depth++; i++; }
            int val = 0;
            while (i < s.length() && Character.isDigit(s.charAt(i))) { val = val * 10 + (s.charAt(i) - '0'); i++; }
            TreeNode node = new TreeNode(val);
            while (stack.size() > depth) stack.pop();
            if (!stack.isEmpty()) {
                if (stack.peek().left == null) stack.peek().left = node;
                else stack.peek().right = node;
            }
            stack.push(node);
        }
        return stack.firstElement();
    }
}
