import java.util.*;
class Solution {
    public int minDeletionSize(String[] strs) {
        int m = strs[0].length();
        int n = strs.length;
        int[] dp = new int[m];
        Arrays.fill(dp, 1);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < i; j++) {
                boolean ok = true;
                for (int k = 0; k < n; k++) {
                    if (strs[k].charAt(j) > strs[k].charAt(i)) {
                        ok = false;
                        break;
                    }
                }
                if (ok) {
                    dp[i] = Math.max(dp[i], dp[j] + 1);
                }
            }
        }
        int maxKeep = 0;
        for (int v : dp) {
            if (v > maxKeep) maxKeep = v;
        }
        return m - maxKeep;
    }
}
