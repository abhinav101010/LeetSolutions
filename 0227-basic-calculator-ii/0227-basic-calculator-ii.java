import java.util.*;

class Solution {
    public int calculate(String s) {
        int num = 0;
        char sign = '+';
        Deque<Integer> stack = new ArrayDeque<>();
        
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (Character.isDigit(c)) {
                num = num * 10 + (c - '0');
            }
            
            if (c == '+' || c == '-' || c == '*' || c == '/' || i == s.length() - 1) {
                if (sign == '+') stack.push(num);
                else if (sign == '-') stack.push(-num);
                else if (sign == '*') stack.push(stack.pop() * num);
                else if (sign == '/') {
                    int prev = stack.pop();
                    stack.push(prev / num);
                }
                sign = c;
                num = 0;
            }
        }
        
        int result = 0;
        while (!stack.isEmpty()) {
            result += stack.pop();
        }
        return result;
    }
}