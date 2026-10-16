class Solution:
    def countTriplets(self, A):
        n = len(A)
        MAX = 1<<16
        freq = [0]*MAX
        for x in A:
            freq[x] += 1
        dp = freq[:]
        for i in range(16):
            for mask in range(MAX):
                if mask & (1<<i):
                    dp[mask] += dp[mask ^ (1<<i)]
        all_ones = MAX-1
        ans = 0
        for i in range(n):
            for j in range(n):
                m = A[i] & A[j]
                comp = all_ones ^ m
                ans += dp[comp]
        return ans
