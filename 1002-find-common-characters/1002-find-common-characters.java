import java.util.*;

class Solution {
    public List<String> commonChars(String[] words) {
        int[] common = new int[26];
        Arrays.fill(common, Integer.MAX_VALUE);
        for (String word : words) {
            int[] count = new int[26];
            for (int i = 0; i < word.length(); i++) {
                count[word.charAt(i) - 'a']++;
            }
            for (int i = 0; i < 26; i++) {
                common[i] = Math.min(common[i], count[i]);
            }
        }
        List<String> ans = new ArrayList<>();
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < common[i]; j++) {
                ans.add(String.valueOf((char) ('a' + i)));
            }
        }
        return ans;
    }
}
