class Solution:
    def countTriplets(self, A):
        n = len(A)
        MAX = 1 << 16
        freq = [0] * MAX
        for x in A:
            freq[x] += 1
        # SOS DP: dp[mask] = sum_{submask subset of mask} freq[submask]
        dp = freq[:]
        for i in range(16):
            for mask in range(MAX):
                if mask & (1 << i):
                    dp[mask] += dp[mask ^ (1 << i)]
        # dp[mask] now contains number of elements x such that (x & mask) == x? Wait.
        # Actually we want for each mask, number of elements x such that (x & mask) == 0? Let's derive.
        # We need goodK[mask] = number of x such that (mask & x) == 0.
        # For a fixed mask, condition (mask & x) == 0 means x has no bits where mask has 1 => x subset of ~mask.
        # Let comp = (~mask) & (MAX-1). Then goodK[mask] = sum_{submask subset of comp} freq[submask].
        # So we can compute subset sums over freq to get sub[mask] = sum_{submask subset of mask} freq[submask].
        # Then goodK[mask] = sub[comp].
        # We already computed dp as subset sums over freq (since we did standard SOS for subsets).
        # So goodK[mask] = dp[comp].
        all_ones = MAX - 1
        ans = 0
        for i in range(n):
            for j in range(n):
                m = A[i] & A[j]
                comp = all_ones ^ m
                ans += dp[comp]
        return ans
