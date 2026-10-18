import java.util.*;

public class Solution {
    public class TreeNode {
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
    
    public TreeNode str2tree(String s) {
        if (s.isEmpty()) return null;
        Deque<TreeNode> stack = new ArrayDeque<>();
        int i = 0;
        while (i < s.length()) {
            char c = s.charAt(i);
            if (c == '(' || c == ')') {
                ++i;
                continue;
            }
            int sign = 1;
            if (c == '-' || c == '+') {
                sign = (c == '-') ? -1 : 1;
                ++i;
            }
            int num = 0;
            while (i < s.length() && Character.isDigit(s.charAt(i))) {
                num = num * 10 + (s.charAt(i) - '0');
                ++i;
            }
            TreeNode node = new TreeNode(sign * num);
            if (!stack.isEmpty()) {
                TreeNode parent = stack.peek();
                if (parent.left == null) {
                    parent.left = node;
                } else {
                    parent.right = node;
                }
            }
            stack.push(node);
            if (i < s.length() && s.charAt(i) == ')') {
                stack.pop();
                ++i;
            }
        }
        return stack.isEmpty() ? null : stack.peek();
    }
}
