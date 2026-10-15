import java.util.Arrays;
class Solution {
    public int minDeletionSize(String[] strs) {
        if (strs == null || strs.length == 0) return 0;
        int n = strs.length;
        int m = strs[0].length();
        int[] dp = new int[m];
        Arrays.fill(dp, 1);
        int maxKeep = 1;
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
            maxKeep = Math.max(maxKeep, dp[i]);
        }
        return m - maxKeep;
    }
}
