import java.util.*;

class Solution {
    public int longestSubstring(String s, int k) {
        if (s.length() < k) return 0;
        
        int[] count = new int[26];
        for (char c : s.toCharArray()) {
            count[c - 'a']++;
        }
        
        for (int i = 0; i < 26; i++) {
            if (count[i] > 0 && count[i] < k) {
                char splitChar = (char) (i + 'a');
                String[] parts = s.split(String.valueOf(splitChar));
                int max = 0;
                for (String part : parts) {
                    max = Math.max(max, longestSubstring(part, k));
                }
                return max;
            }
        }
        
        return s.length();
    }
}