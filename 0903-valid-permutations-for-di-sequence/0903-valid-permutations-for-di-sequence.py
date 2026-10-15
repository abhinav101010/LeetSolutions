class Solution:
    def numPermsDISequence(self, S: str) -> int:
        n = len(S)
        MOD = 10**9 + 7  # actually answer fits in integer but we keep mod for safety
        dp = [1] * (n + 1)  # dp for length 1? We'll use dp for current size
        # Actually we need dp for size i+1 numbers.
        # We'll use dp[j] = number of ways for current length ending with j-th smallest.
        # Initialize for length 1: only one number, dp[0] = 1.
        dp = [1]
        for i, ch in enumerate(S):
            ndp = [0] * (len(dp) + 1)
            if ch == 'I':
                # sum of dp[0..j-1]
                acc = 0
                for j in range(len(dp)):
                    ndp[j+1] = acc
                    acc = (acc + dp[j]) % MOD
            else:  # 'D'
                # sum of dp[j..end]
                acc = 0
                for j in range(len(dp)-1, -1, -1):
                    acc = (acc + dp[j]) % MOD
                    ndp[j] = acc
            dp = ndp
        return sum(dp) % MOD
