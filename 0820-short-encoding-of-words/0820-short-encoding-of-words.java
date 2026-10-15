import java.util.*;

class Solution {
    public int minimumLengthEncoding(String[] words) {
        Set<String> set = new HashSet<>(Arrays.asList(words));
        // Remove words that are suffix of another word
        for (String word : words) {
            for (int i = 1; i < word.length(); i++) {
                set.remove(word.substring(i));
            }
        }
        int res = 0;
        for (String w : set) {
            res += w.length() + 1;
        }
        return res;
    }
}
