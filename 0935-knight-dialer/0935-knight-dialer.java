import java.util.Arrays;
class Solution {
    public int knightDialer(int n) {
        int[][] moves = {
            {4,6}, //0
            {6,8}, //1
            {7,9}, //2
            {4,8}, //3
            {0,3,9}, //4
            {}, //5
            {0,1,7}, //6
            {2,6}, //7
            {1,3}, //8
            {2,4} //9
        };
        final int MOD = 1000000007;
        long[] dp = new long[10];
        Arrays.fill(dp, 1);
        for (int step = 1; step < n; step++) {
            long[] dp2 = new long[10];
            for (int d = 0; d < 10; d++) {
                for (int nxt : moves[d]) {
                    dp2[nxt] = (dp2[nxt] + dp[d]) % MOD;
                }
            }
            dp = dp2;
        }
        long sum = 0;
        for (long v : dp) sum = (sum + v) % MOD;
        return (int) sum;
    }
}
