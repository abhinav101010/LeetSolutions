class Solution {
    public int distinctSubseqII(String s) {
        final int MOD = 1000000007;
        long dp = 1; // empty
        int[] last = new int[26];
        for (char ch : s.toCharArray()) {
            int idx = ch - 'a';
            long prev = dp;
            dp = (dp * 2) % MOD;
            dp = (dp - last[idx] + MOD) % MOD;
            last[idx] = (int) prev;
        }
        return (int) ((dp - 1 + MOD) % MOD);
    }
}
