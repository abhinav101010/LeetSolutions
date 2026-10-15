class Solution:
    def superEggDrop(self, K: int, N: int) -> int:
        # dp[k] = max floors we can test with t moves and k eggs
        dp = [0] * (K + 1)
        moves = 0
        while dp[K] < N:
            moves += 1
            for k in range(K, 0, -1):
                dp[k] = dp[k] + dp[k-1] + 1
        return moves
