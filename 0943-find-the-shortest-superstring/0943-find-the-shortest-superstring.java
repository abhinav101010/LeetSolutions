import java.util.*;
class Solution {
    public String shortestSuperstring(String[] A) {
        int n = A.length;
        int[][] overlap = new int[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                String a = A[i], b = A[j];
                int max = Math.min(a.length(), b.length());
                for (int k = max; k >= 0; k--) {
                    if (a.endsWith(b.substring(0, k))) {
                        overlap[i][j] = k;
                        break;
                    }
                }
            }
        }
        String[][] dp = new String[1<<n][n];
        for (int i = 0; i < n; i++) {
            dp[1<<i][i] = A[i];
        }
        for (int mask = 0; mask < (1<<n); mask++) {
            for (int last = 0; last < n; last++) {
                if ((mask & (1<<last)) == 0) continue;
                String cur = dp[mask][last];
                if (cur == null) continue;
                for (int nxt = 0; nxt < n; nxt++) {
                    if ((mask & (1<<nxt)) != 0) continue;
                    int mask2 = mask | (1<<nxt);
                    String cand = cur + A[nxt].substring(overlap[last][nxt]);
                    if (dp[mask2][nxt] == null || cand.length() < dp[mask2][nxt].length() ||
                            (cand.length() == dp[mask2][nxt].length() && cand.compareTo(dp[mask2][nxt]) < 0)) {
                        dp[mask2][nxt] = cand;
                    }
                }
            }
        }
        int full = (1<<n) - 1;
        String ans = null;
        for (int last = 0; last < n; last++) {
            String s = dp[full][last];
            if (s == null) continue;
            if (ans == null || s.length() < ans.length() ||
                    (s.length() == ans.length() && s.compareTo(ans) < 0)) {
                ans = s;
            }
        }
        return ans;
    }
}
