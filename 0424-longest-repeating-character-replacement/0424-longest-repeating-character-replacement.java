import java.util.*;

class Solution {
    public int characterReplacement(String s, int k) {
        int[] count = new int[26];
        int maxCount = 0;
        int left = 0;
        int result = 0;
        
        for (int right = 0; right < s.length(); right++) {
            count[s.charAt(right) - 'a']++;
            maxCount = Math.max(maxCount, count[s.charAt(right) - 'a']);
            
            while (right - left + 1 - maxCount > k) {
                count[s.charAt(left) - 'a']--;
                left++;
            }
            
            result = Math.max(result, right - left + 1);
        }
        
        return result;
    }
}