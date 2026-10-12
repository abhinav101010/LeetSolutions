import java.util.*;

class Solution {
    public String[] findWords(String[] words) {
        Set<Character> row1 = new HashSet<>(Arrays.asList('q','w','e','r','t','y','u','i','o','p'));
        Set<Character> row2 = new HashSet<>(Arrays.asList('a','s','d','f','g','h','j','k','l'));
        Set<Character> row3 = new HashSet<>(Arrays.asList('z','x','c','v','b','n','m'));
        
        List<String> ans = new ArrayList<>();
        for (String word : words) {
            String lower = word.toLowerCase();
            boolean inRow1 = true, inRow2 = true, inRow3 = true;
            for (char c : lower.toCharArray()) {
                if (!row1.contains(c)) inRow1 = false;
                if (!row2.contains(c)) inRow2 = false;
                if (!row3.contains(c)) inRow3 = false;
            }
            if (inRow1 || inRow2 || inRow3) {
                ans.add(word);
            }
        }
        return ans.toArray(new String[0]);
    }
}