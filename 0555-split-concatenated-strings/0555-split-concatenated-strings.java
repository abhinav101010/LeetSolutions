import java.util.*;

public class Solution {
    public String splitLoopedString(String[] strs) {
        int n = strs.length;
        String[] s = new String[n];
        for (int i = 0; i < n; ++i) {
            String t = strs[i];
            String rev = new StringBuilder(t).reverse().toString();
            s[i] = t.compareTo(rev) >= 0 ? t : rev;
        }
        String res = "";
        for (int i = 0; i < n; ++i) {
            String t = strs[i];
            String rev = new StringBuilder(t).reverse().toString();
            String[] parts = {t, rev};
            for (int p = 0; p < 2; ++p) {
                String cur = parts[p];
                for (int j = 0; j < cur.length(); ++j) {
                    String prefix = cur.substring(j);
                    String suffix = cur.substring(0, j);
                    StringBuilder candidate = new StringBuilder(prefix);
                    for (int k = 1; k < n; ++k) {
                        candidate.append(s[(i + k) % n]);
                    }
                    candidate.append(suffix);
                    String c = candidate.toString();
                    if (c.compareTo(res) > 0) res = c;
                }
            }
        }
        return res;
    }
}
