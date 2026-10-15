from typing import List

class Solution:
    def findMaxAverage(self, nums: List[int], k: int) -> float:
        def check(avg: float) -> bool:
            # transform each nums[i] - avg
            n = len(nums)
            prefix = [0.0] * (n + 1)
            for i in range(n):
                prefix[i+1] = prefix[i] + nums[i] - avg
            min_prefix = 0.0
            for i in range(k, n+1):
                if prefix[i] - min_prefix >= 0:
                    return True
                # update min_prefix to be min of prefix[0..i-k+1]
                if prefix[i-k+1] < min_prefix:
                    min_prefix = prefix[i-k+1]
            return False

        lo, hi = min(nums), max(nums)
        eps = 1e-5
        while hi - lo > eps:
            mid = (lo + hi) / 2.0
            if check(mid):
                lo = mid
            else:
                hi = mid
        return lo
