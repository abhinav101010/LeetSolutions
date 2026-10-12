import java.util.*;

class Solution {
    public String removeDuplicateLetters(String s) {
        int[] lastOccurrence = new int[26];
        for (int i = 0; i < s.length(); i++) {
            lastOccurrence[s.charAt(i) - 'a'] = i;
        }
        
        Deque<Character> stack = new ArrayDeque<>();
        boolean[] inStack = new boolean[26];
        
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (inStack[c - 'a']) continue;
            
            while (!stack.isEmpty() && c < stack.peek() && i < lastOccurrence[stack.peek() - 'a']) {
                inStack[stack.pop() - 'a'] = false;
            }
            stack.push(c);
            inStack[c - 'a'] = true;
        }
        
        StringBuilder sb = new StringBuilder();
        while (!stack.isEmpty()) {
            sb.insert(0, stack.pop());
        }
        return sb.toString();
    }
}