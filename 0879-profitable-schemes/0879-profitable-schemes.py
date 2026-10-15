class Solution:
    def profitableSchemes(self, n: int, minProfit: int, group: list[int], profit: list[int]) -> int:
        MOD = 10**9 + 7
        length = len(group)
        dp = [[0] * (minProfit + 1) for _ in range(n + 1)]
        dp[0][0] = 1
        for k in range(length):
            g = group[k]
            p = profit[k]
            for members in range(n, g - 1, -1):
                for earn in range(minProfit, -1, -1):
                    dp[members][min(minProfit, earn + p)] = (dp[members][min(minProfit, earn + p)] + dp[members - g][earn]) % MOD
        total = 0
        for members in range(n + 1):
            total = (total + dp[members][minProfit]) % MOD
        return total
