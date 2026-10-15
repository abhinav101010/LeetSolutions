class Solution {
    public int superEggDrop(int K, int N) {
        int[] dp = new int[K + 1];
        int moves = 0;
        while (dp[K] < N) {
            moves++;
            for (int k = K; k >= 1; k--) {
                dp[k] = dp[k] + dp[k-1] + 1;
            }
        }
        return moves;
    }
}
