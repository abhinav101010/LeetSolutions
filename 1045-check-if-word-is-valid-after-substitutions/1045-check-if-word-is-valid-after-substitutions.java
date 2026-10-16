import java.util.*;
class Solution {
    public boolean isValid(String S) {
        Deque<Character> stack = new ArrayDeque<>();
        for (char c : S.toCharArray()) {
            if (c == 'c') {
                if (stack.size() < 2 || stack.peek() != 'b') return false;
                stack.pop();
                if (stack.peek() != 'a') return false;
                stack.pop();
            } else {
                stack.push(c);
            }
        }
        return stack.isEmpty();
    }
}
