import java.util.*;

class Solution {
    public String longestNiceSubstring(String s) {
        if (s.length() < 2) {
            return "";
        }

        Set<Character> chars = new HashSet<>();
        for (char c : s.toCharArray()) {
            chars.add(c);
        }

        for (int i = 0; i < s.length(); i++) {
            char ch = s.charAt(i);
            if (!chars.contains(Character.toLowerCase(ch)) || !chars.contains(Character.toUpperCase(ch))) {
                String left = longestNiceSubstring(s.substring(0, i));
                String right = longestNiceSubstring(s.substring(i + 1));

                return left.length() >= right.length() ? left : right;
            }
        }

        return s;
    }
}