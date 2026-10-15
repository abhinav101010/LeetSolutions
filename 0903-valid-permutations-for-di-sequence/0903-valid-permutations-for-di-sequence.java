class Solution {
    public int numPermsDISequence(String S) {
        int n = S.length();
        int MOD = 1000000007;
        int[] dp = new int[1];
        dp[0] = 1;
        for (char ch : S.toCharArray()) {
            int[] ndp = new int[dp.length + 1];
            if (ch == 'I') {
                long acc = 0;
                for (int j = 0; j < dp.length; j++) {
                    ndp[j+1] = (int) acc;
                    acc = (acc + dp[j]) % MOD;
                }
            } else { // 'D'
                long acc = 0;
                for (int j = dp.length - 1; j >= 0; j--) {
                    acc = (acc + dp[j]) % MOD;
                    ndp[j] = (int) acc;
                }
            }
            dp = ndp;
        }
        long ans = 0;
        for (int v : dp) {
            ans = (ans + v) % MOD;
        }
        return (int) ans;
    }
}
