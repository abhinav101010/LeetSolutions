import java.util.*;

class Solution {
    public List<Integer> closestKValues(TreeNode root, double target, int k) {
        List<Integer> res = new ArrayList<>();
        Deque<Integer> stack1 = new ArrayDeque<>();
        Deque<Integer> stack2 = new ArrayDeque<>();
        inorder(root, stack1, target, true);
        inorder(root, stack2, target, false);
        while (k-- > 0) {
            if (stack1.isEmpty()) {
                res.add(stack2.pop());
            } else if (stack2.isEmpty()) {
                res.add(stack1.pop());
            } else if (Math.abs(stack1.peek() - target) < Math.abs(stack2.peek() - target)) {
                res.add(stack1.pop());
            } else {
                res.add(stack2.pop());
            }
        }
        return res;
    }
    
    private void inorder(TreeNode root, Deque<Integer> stack, double target, boolean isLeft) {
        if (root == null) return;
        if (isLeft) {
            inorder(root.left, stack, target, true);
            if ((double)root.val <= target) stack.push(root.val);
            else return;
            inorder(root.right, stack, target, true);
        } else {
            inorder(root.right, stack, target, false);
            if ((double)root.val > target) stack.push(root.val);
            else return;
            inorder(root.left, stack, target, false);
        }
    }
}