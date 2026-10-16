class Solution {
    public int maxSumTwoNoOverlap(int[] A, int L, int M) {
        int n = A.length;
        int[] pref = new int[n + 1];
        for (int i = 0; i < n; i++) pref[i+1] = pref[i] + A[i];
        java.util.function.BiFunction<Integer, Integer, Integer> sumx = (i, j) -> pref[j] - pref[i];
        int ans = 0, maxL = 0, maxM = 0;
        for (int i = L + M - 1; i < n; i++) {
            maxL = Math.max(maxL, sumx.apply(i - M - L + 1, i - M + 1));
            maxM = Math.max(maxM, sumx.apply(i - M - L + 1, i - L + 1));
            ans = Math.max(ans, Math.max(maxL + sumx.apply(i - M + 1, i + 1), maxM + sumx.apply(i - L + 1, i + 1)));
        }
        return ans;
    }
}
