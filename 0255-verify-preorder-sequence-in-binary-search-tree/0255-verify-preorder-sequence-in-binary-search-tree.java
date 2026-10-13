import java.util.*;

class Solution {
    public boolean verifyPreorder(int[] preorder) {
        Stack<Integer> stack = new Stack<>();
        int low = Integer.MIN_VALUE;
        for (int val : preorder) {
            if (val < low) return false;
            while (!stack.isEmpty() && stack.peek() < val) {
                low = stack.pop();
            }
            stack.push(val);
        }
        return true;
    }
}