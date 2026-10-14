import java.util.*;

class Solution {
    public String encode(String s) {
        int n = s.length();
        String[][] dp = new String[n][n];
        for (int i = 0; i < n; i++) {
            dp[i][i] = s.substring(i, i+1);
        }
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1;
                String substr = s.substring(i, j+1);
                dp[i][j] = substr; // default
                // split
                for (int k = i; k < j; k++) {
                    String left = dp[i][k];
                    String right = dp[k+1][j];
                    if (left.length() + right.length() < dp[i][j].length()) {
                        dp[i][j] = left + right;
                    }
                }
                // check for repeated pattern
                int l = len;
                for (int p = 1; p <= l/2; p++) {
                    if (l % p == 0) {
                        int repeats = l / p;
                        String pattern = substr.substring(0, p);
                        boolean ok = true;
                        for (int r = 1; r < repeats; r++) {
                            if (!pattern.equals(substr.substring(r*p, r*p+p))) {
                                ok = false;
                                break;
                            }
                        }
                        if (ok) {
                            String encodedPattern = dp[i][i+p-1];
                            String candidate = repeats + "[" + encodedPattern + "]";
                            if (candidate.length() < dp[i][j].length()) {
                                dp[i][j] = candidate;
                            }
                        }
                    }
                }
            }
        }
        return dp[0][n-1];
    }
}
