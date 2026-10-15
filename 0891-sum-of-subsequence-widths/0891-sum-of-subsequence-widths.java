import java.util.Arrays;
class Solution {
    public int sumSubseqWidths(int[] A) {
        final int MOD = 1000000007;
        Arrays.sort(A);
        int n = A.length;
        long[] pow2 = new long[n];
        pow2[0] = 1;
        for (int i = 1; i < n; i++) {
            pow2[i] = (pow2[i-1] * 2) % MOD;
        }
        long ans = 0;
        for (int i = 0; i < n; i++) {
            long left = pow2[i];
            long right = pow2[n-1-i];
            long contrib = (left - right + MOD) % MOD;
            ans = (ans + contrib * A[i]) % MOD;
        }
        return (int) ans;
    }
}
