import java.util.*;
class Solution {
    public List<String> ambiguousCoordinates(String s) {
        String inner = s.substring(1, s.length() - 1);
        List<String> res = new ArrayList<>();
        for (int i = 1; i < inner.length(); i++) {
            String left = inner.substring(0, i);
            String right = inner.substring(i);
            List<String> leftOpts = make(left);
            List<String> rightOpts = make(right);
            for (String l : leftOpts) {
                for (String r : rightOpts) {
                    res.add("(" + l + ", " + r + ")");
                }
            }
        }
        return res;
    }
    private List<String> make(String frag) {
        List<String> res = new ArrayList<>();
        int n = frag.length();
        if (n == 0) return res;
        // no decimal
        if (!(frag.charAt(0) == '0' && n > 1)) {
            res.add(frag);
        }
        // with decimal
        for (int i = 1; i < n; i++) {
            String left = frag.substring(0, i);
            String right = frag.substring(i);
            if (left.length() > 1 && left.charAt(0) == '0') continue;
            if (right.charAt(right.length() - 1) == '0') continue;
            res.add(left + "." + right);
        }
        return res;
    }
}
