import java.util.*;
class Solution {
    public List<Boolean> camelMatch(String[] queries, String pattern) {
        List<Boolean> res = new ArrayList<>();
        for (String q : queries) res.add(match(q, pattern));
        return res;
    }
    boolean match(String q, String p) {
        int i = 0;
        for (char c : q.toCharArray()) {
            if (i < p.length() && c == p.charAt(i)) i++;
            else if (Character.isUpperCase(c)) return false;
        }
        return i == p.length();
    }
}
