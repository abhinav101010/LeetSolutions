import java.util.*;

class Solution {
    private HashMap<Character, String> map;
    private HashSet<String> set;
    private boolean res;
    
    public boolean wordPatternMatch(String pattern, String s) {
        map = new HashMap<>();
        set = new HashSet<>();
        res = false;
        backtrack(0, 0, pattern, s);
        return res;
    }
    
    private void backtrack(int i, int j, String pattern, String s) {
        if (res) return;
        if (i == pattern.length() && j == s.length()) {
            res = true;
            return;
        }
        if (i == pattern.length() || j == s.length()) return;
        char p = pattern.charAt(i);
        for (int k = j; k < s.length(); k++) {
            String sub = s.substring(j, k + 1);
            if (map.containsKey(p) && map.get(p).equals(sub)) {
                backtrack(i + 1, k + 1, pattern, s);
            } else if (!map.containsKey(p) && !set.contains(sub)) {
                map.put(p, sub);
                set.add(sub);
                backtrack(i + 1, k + 1, pattern, s);
                set.remove(sub);
                map.remove(p);
            }
        }
    }
}