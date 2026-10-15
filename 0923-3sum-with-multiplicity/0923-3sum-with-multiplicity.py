class Solution:
    def threeSumMulti(self, arr: list[int], target: int) -> int:
        MOD = 10**9 + 7
        n = len(arr)
        ans = 0
        for i in range(n):
            memo = {}
            rem = target - arr[i]
            for j in range(i + 1, n):
                need = rem - arr[j]
                ans = (ans + memo.get(need, 0)) % MOD
                memo[arr[j]] = memo.get(arr[j], 0) + 1
        return ans
