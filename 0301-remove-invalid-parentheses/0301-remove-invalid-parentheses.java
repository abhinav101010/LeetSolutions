import java.util.*;

class Solution {
    public List<String> removeInvalidParentheses(String s) {
        Set<String> level = new HashSet<>();
        level.add(s);
        
        while (true) {
            List<String> valid = new ArrayList<>();
            for (String str : level) {
                if (isValid(str)) valid.add(str);
            }
            if (!valid.isEmpty()) return valid;
            
            Set<String> nextLevel = new HashSet<>();
            for (String str : level) {
                for (int i = 0; i < str.length(); i++) {
                    if (str.charAt(i) == '(' || str.charAt(i) == ')') {
                        nextLevel.add(str.substring(0, i) + str.substring(i + 1));
                    }
                }
            }
            level = nextLevel;
        }
    }
    
    private boolean isValid(String s) {
        int count = 0;
        for (char c : s.toCharArray()) {
            if (c == '(') count++;
            else if (c == ')') {
                count--;
                if (count < 0) return false;
            }
        }
        return count == 0;
    }
}