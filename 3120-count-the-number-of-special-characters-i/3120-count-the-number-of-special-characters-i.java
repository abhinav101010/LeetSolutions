import java.util.*;

class Solution {
    public int numberOfSpecialChars(String word) {
        Set<Character> ans = new HashSet<>();
        for (char c : word.toCharArray()) {
            if (Character.isLowerCase(c) && word.indexOf(Character.toUpperCase(c)) >= 0) {
                ans.add(c);
            }
        }
        return ans.size();
    }
}