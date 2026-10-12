import java.util.*;

class Solution {
    public String findLongestWord(String s, List<String> dictionary) {
        dictionary.sort((a, b) -> {
            if (a.length() != b.length()) return b.length() - a.length();
            return a.compareTo(b);
        });
        
        for (String word : dictionary) {
            int i = 0;
            for (char c : s.toCharArray()) {
                if (i < word.length() && word.charAt(i) == c) i++;
            }
            if (i == word.length()) return word;
        }
        return "";
    }
}