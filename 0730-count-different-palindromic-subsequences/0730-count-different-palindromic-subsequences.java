class Solution {
    public int countPalindromicSubsequences(String S) {
        final int MOD = 1000000007;
        int n = S.length();
        int[][] dp = new int[n][n];
        for (int i = 0; i < n; i++) {
            dp[i][i] = 1;
        }
        int[][] next = new int[n][4];
        int[][] prev = new int[n][4];
        for (int c = 0; c < 4; c++) {
            char ch = (char)('a' + c);
            int nxt = n;
            for (int i = n-1; i >= 0; i--) {
                if (S.charAt(i) == ch) nxt = i;
                next[i][c] = nxt;
            }
            int prv = -1;
            for (int i = 0; i < n; i++) {
                if (S.charAt(i) == ch) prv = i;
                prev[i][c] = prv;
            }
        }
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1;
                if (S.charAt(i) != S.charAt(j)) {
                    dp[i][j] = dp[i+1][j] + dp[i][j-1] - dp[i+1][j-1];
                } else {
                    int ch = S.charAt(i) - 'a';
                    int left = next[i][ch];
                    int right = prev[j][ch];
                    if (left > right) {
                        dp[i][j] = dp[i+1][j-1] * 2 + 2;
                    } else if (left == right) {
                        dp[i][j] = dp[i+1][j-1] * 2 + 1;
                    } else {
                        dp[i][j] = dp[i+1][j-1] * 2 - dp[left+1][right-1];
                    }
                }
                dp[i][j] = (dp[i][j] % MOD + MOD) % MOD;
            }
        }
        return dp[0][n-1];
    }
}
