public class Solution {
    public String parseTernary(String expression) {
        java.util.Deque<Character> stack = new java.util.ArrayDeque<>();
        for (int i = expression.length() - 1; i >= 0; --i) {
            char c = expression.charAt(i);
            if (c == '?') {
                char trueChar = stack.pop();
                stack.pop(); // ':'
                char falseChar = stack.pop();
                if (expression.charAt(i - 1) == 'T') {
                    stack.push(trueChar);
                } else {
                    stack.push(falseChar);
                }
                --i;
            } else if (c != ':') {
                stack.push(c);
            }
        }
        return stack.pop().toString();
    }
}
