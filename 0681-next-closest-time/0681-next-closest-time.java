import java.util.*;

class Solution {
    public String nextClosestTime(String time) {
        Set<Character> allowed = new HashSet<>();
        for (char ch : time.toCharArray()) allowed.add(ch);
        int h = Integer.parseInt(time.substring(0, 2));
        int m = Integer.parseInt(time.substring(3, 5));
        int start = h * 60 + m;
        for (int offset = 1; offset <= 24 * 60; offset++) {
            int cand = (start + offset) % (24 * 60);
            int hh = cand / 60;
            int mm = cand % 60;
            String cand_str = String.format("%04d", hh * 100 + mm);
            String time_str = cand_str.substring(0, 2) + ":" + cand_str.substring(2, 4);
            boolean ok = true;
            for (char ch : time_str.toCharArray()) {
                if (ch != ':' && !allowed.contains(ch)) {
                    ok = false;
                    break;
                }
            }
            if (ok) return time_str;
        }
        return time;
    }
}