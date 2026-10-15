import java.util.*;
class Solution {
    public String orderlyQueue(String S, int K) {
        if (K == 1) {
            String s2 = S + S;
            int n = S.length();
            String best = s2.substring(0, n);
            for (int i = 1; i < n; i++) {
                String cand = s2.substring(i, i + n);
                if (cand.compareTo(best) < 0) {
                    best = cand;
                }
            }
            return best;
        } else {
            char[] arr = S.toCharArray();
            Arrays.sort(arr);
            return new String(arr);
        }
    }
}
