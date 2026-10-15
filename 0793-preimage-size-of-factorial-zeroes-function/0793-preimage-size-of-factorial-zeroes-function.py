class Solution:
    def preimageSizeFZF(self, K: int) -> int:
        def trailing_zeros(x):
            count = 0
            while x:
                x //= 5
                count += x
            return count
        # binary search for leftmost x with trailing_zeros(x) >= K
        lo, hi = 0, 5 * K + 5  # safe upper bound
        while lo < hi:
            mid = (lo + hi) // 2
            if trailing_zeros(mid) < K:
                lo = mid + 1
            else:
                hi = mid
        # now lo is candidate
        return 5 if trailing_zeros(lo) == K else 0
