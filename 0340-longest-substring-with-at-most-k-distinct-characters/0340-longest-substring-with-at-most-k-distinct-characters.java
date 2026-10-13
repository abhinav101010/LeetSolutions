import java.util.*;

class Solution {
    public int lengthOfLongestSubstringKDistinct(String s, int k) {
        Map<Character, Integer> count = new HashMap<>();
        int left = 0, res = 0;
        for (int right = 0; right < s.length(); right++) {
            count.put(s.charAt(right), count.getOrDefault(s.charAt(right), 0) + 1);
            while (count.size() > k) {
                char c = s.charAt(left);
                count.put(c, count.get(c) - 1);
                if (count.get(c) == 0) {
                    count.remove(c);
                }
                left++;
            }
            res = Math.max(res, right - left + 1);
        }
        return res;
    }
}