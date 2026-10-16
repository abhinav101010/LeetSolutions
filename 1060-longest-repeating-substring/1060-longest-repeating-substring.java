import java.util.*;
class Solution {
    private boolean hasRepeating(String s, int length) {
        Set<String> seen = new HashSet<>();
        for (int i = 0; i <= s.length()-length; i++) {
            String sub = s.substring(i, i+length);
            if (seen.contains(sub)) return true;
            seen.add(sub);
        }
        return false;
    }
    public int longestRepeatingSubstring(String s) {
        int left = 1, right = s.length();
        int res = 0;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (hasRepeating(s, mid)) {
                res = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return res;
    }
}
