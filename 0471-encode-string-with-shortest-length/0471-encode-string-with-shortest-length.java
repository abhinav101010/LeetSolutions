import java.util.*;

public class Solution {
    public String encode(String s) {
        int n = s.length();
        String[][] dp = new String[n][n];
        for (int i = 0; i < n; ++i) {
            Arrays.fill(dp[i], "");
        }
        for (int len = 1; len <= n; ++len) {
            for (int i = 0; i + len - 1 < n; ++i) {
                int j = i + len - 1;
                dp[i][j] = s.substring(i, j + 1);
                if (len > 4) {
                    for (int k = i; k < j; ++k) {
                        int mid = k - i + 1;
                        if (len % mid == 0) {
                            String pattern = s.substring(i, i + mid);
                            boolean match = true;
                            for (int t = 1; t < len / mid; ++t) {
                                if (!s.substring(i + t * mid, i + t * mid + mid).equals(pattern)) {
                                    match = false;
                                    break;
                                }
                            }
                            if (match) {
                                String candidate = (len / mid) + "[" + dp[i][k] + "]";
                                if (candidate.length() < dp[i][j].length()) {
                                    dp[i][j] = candidate;
                                }
                            }
                        }
                    }
                    for (int k = i; k < j; ++k) {
                        if (dp[i][k].length() + dp[k + 1][j].length() < dp[i][j].length()) {
                            dp[i][j] = dp[i][k] + dp[k + 1][j];
                        }
                    }
                }
            }
        }
        return dp[0][n - 1];
    }
}
