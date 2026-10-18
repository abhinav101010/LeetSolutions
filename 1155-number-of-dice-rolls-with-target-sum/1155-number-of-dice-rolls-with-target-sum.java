import java.util.*;

class Solution {
    public int numRollsToTarget(int n, int k, int target) {
        final int MOD = 1000000007;
        int[] f = new int[target + 1];
        f[0] = 1;
        for (int i = 0; i < n; i++) {
            int[] g = new int[target + 1];
            for (int j = 1; j <= target; j++) {
                for (int h = 1; h <= k; h++) {
                    if (j - h >= 0) {
                        g[j] = (g[j] + f[j - h]) % MOD;
                    }
                }
            }
            f = g;
        }
        return f[target];
    }
}
