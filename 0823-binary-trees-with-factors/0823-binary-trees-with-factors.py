class Solution:
    def numFactoredBinaryTrees(self, arr: list[int]) -> int:
        MOD = 10**9 + 7
        arr.sort()
        n = len(arr)
        dp = {}
        for x in arr:
            dp[x] = 1  # single node tree
        for i in range(n):
            for j in range(i):
                if arr[i] % arr[j] == 0:
                    right = arr[i] // arr[j]
                    if right in dp:
                        dp[arr[i]] = (dp[arr[i]] + dp[arr[j]] * dp[right]) % MOD
        return sum(dp.values()) % MOD
