class Solution {
    public int countTriplets(int[] A) {
        int n = A.length;
        final int MAX = 1 << 16;
        int[] freq = new int[MAX];
        for (int x : A) {
            freq[x]++;
        }
        // SOS dp: dp[mask] = sum_{submask subset of mask} freq[submask]
        int[] dp = freq.clone();
        for (int i = 0; i < 16; i++) {
            for (int mask = 0; mask < MAX; mask++) {
                if ((mask & (1 << i)) != 0) {
                    dp[mask] += dp[mask ^ (1 << i)];
                }
            }
        }
        int allOnes = MAX - 1;
        long ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int m = A[i] & A[j];
                int comp = allOnes ^ m;
                ans += dp[comp];
            }
        }
        return (int) ans;
    }
}
