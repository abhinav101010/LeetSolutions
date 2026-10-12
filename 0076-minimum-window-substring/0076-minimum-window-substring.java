import java.util.*;

class Solution {
    public String minWindow(String s, String t) {
        if (s == null || t == null || s.length() < t.length()) {
            return "";
        }
        
        Map<Character, Integer> target = new HashMap<>();
        for (char c : t.toCharArray()) {
            target.put(c, target.getOrDefault(c, 0) + 1);
        }
        int required = target.size();
        
        int left = 0;
        int formed = 0;
        Map<Character, Integer> windowCounts = new HashMap<>();
        
        int[] ans = {Integer.MAX_VALUE, -1, -1}; // length, left, right
        
        for (int right = 0; right < s.length(); right++) {
            char c = s.charAt(right);
            windowCounts.put(c, windowCounts.getOrDefault(c, 0) + 1);
            
            if (target.containsKey(c) && windowCounts.get(c).equals(target.get(c))) {
                formed++;
            }
            
            while (left <= right && formed == required) {
                c = s.charAt(left);
                
                if (right - left + 1 < ans[0]) {
                    ans[0] = right - left + 1;
                    ans[1] = left;
                    ans[2] = right;
                }
                
                windowCounts.put(c, windowCounts.get(c) - 1);
                if (target.containsKey(c) && windowCounts.get(c) < target.get(c)) {
                    formed--;
                }
                
                left++;
            }
        }
        
        return ans[0] == Integer.MAX_VALUE ? "" : s.substring(ans[1], ans[2] + 1);
    }
}