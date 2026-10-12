import java.util.*;

class Solution {
    public int findLUSlength(String[] strs) {
        Map<String, Integer> count = new HashMap<>();
        for (String s : strs) count.put(s, count.getOrDefault(s, 0) + 1);
        
        List<String> unique = new ArrayList<>(count.keySet());
        unique.sort((a, b) -> b.length() - a.length());
        
        for (String s : unique) {
            if (count.get(s) == 1) {
                boolean isSubseq = false;
                for (String t : unique) {
                    if (!t.equals(s) && isSubsequence(s, t)) {
                        isSubseq = true;
                        break;
                    }
                }
                if (!isSubseq) return s.length();
            }
        }
        return -1;
    }
    
    private boolean isSubsequence(String s, String t) {
        if (s.length() > t.length()) return false;
        int i = 0;
        for (char c : t.toCharArray()) {
            if (i < s.length() && s.charAt(i) == c) i++;
        }
        return i == s.length();
    }
}