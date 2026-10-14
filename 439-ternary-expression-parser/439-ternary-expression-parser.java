import java.util.*;

class Solution {
    public String parseTernary(String expression) {
        Deque<Character> stack = new ArrayDeque<>();
        int i = expression.length() - 1;
        while (i >= 0) {
            char ch = expression.charAt(i);
            if (!stack.isEmpty() && stack.peek() == '?') {
                stack.pop(); // remove '?'
                char trueVal = stack.pop();
                char falseVal = stack.pop();
                char condition = stack.pop(); // 'T' or 'F'
                if (condition == 'T') {
                    stack.push(trueVal);
                } else {
                    stack.push(falseVal);
                }
                i--; // skip condition character
            } else {
                stack.push(ch);
            }
            i--;
        }
        return String.valueOf(stack.peek());
    }
}
