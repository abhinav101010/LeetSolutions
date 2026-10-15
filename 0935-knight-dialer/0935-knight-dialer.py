class Solution:
    def knightDialer(self, n: int) -> int:
        moves = {
            0: [4,6],
            1: [6,8],
            2: [7,9],
            3: [4,8],
            4: [0,3,9],
            5: [],
            6: [0,1,7],
            7: [2,6],
            8: [1,3],
            9: [2,4]
        }
        MOD = 10**9 + 7
        dp = [1]*10
        for _ in range(1, n):
            dp2 = [0]*10
            for d in range(10):
                for nxt in moves[d]:
                    dp2[nxt] = (dp2[nxt] + dp[d]) % MOD
            dp = dp2
        return sum(dp) % MOD
