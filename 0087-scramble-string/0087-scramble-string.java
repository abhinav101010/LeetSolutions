import java.util.*;

class Solution {
    public boolean isScramble(String s1, String s2) {
        if (s1.length() != s2.length()) return false;
        if (s1.equals(s2)) return true;
        
        char[] c1 = s1.toCharArray();
        char[] c2 = s2.toCharArray();
        Arrays.sort(c1);
        Arrays.sort(c2);
        if (!Arrays.equals(c1, c2)) return false;
        
        return dfs(s1, 0, s2, 0, s1.length(), new HashMap<>());
    }
    
    private boolean dfs(String s1, int i1, String s2, int i2, int len, Map<String, Boolean> memo) {
        String key = i1 + "," + i2 + "," + len;
        if (memo.containsKey(key)) return memo.get(key);
        
        if (s1.substring(i1, i1 + len).equals(s2.substring(i2, i2 + len))) {
            memo.put(key, true);
            return true;
        }
        
        char[] sub1 = s1.substring(i1, i1 + len).toCharArray();
        char[] sub2 = s2.substring(i2, i2 + len).toCharArray();
        Arrays.sort(sub1);
        Arrays.sort(sub2);
        if (!Arrays.equals(sub1, sub2)) {
            memo.put(key, false);
            return false;
        }
        
        for (int k = 1; k < len; k++) {
            // No swap
            if (dfs(s1, i1, s2, i2, k, memo) && dfs(s1, i1 + k, s2, i2 + k, len - k, memo)) {
                memo.put(key, true);
                return true;
            }
            // Swap
            if (dfs(s1, i1, s2, i2 + len - k, k, memo) && dfs(s1, i1 + k, s2, i2, len - k, memo)) {
                memo.put(key, true);
                return true;
            }
        }
        
        memo.put(key, false);
        return false;
    }
}