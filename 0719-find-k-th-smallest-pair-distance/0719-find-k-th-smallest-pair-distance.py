from typing import List

class Solution:
    def smallestDistancePair(self, nums: List[int], k: int) -> int:
        nums.sort()
        n = len(nums)
        def count_pairs(max_dist: int) -> int:
            cnt = 0
            left = 0
            for right in range(n):
                while nums[right] - nums[left] > max_dist:
                    left += 1
                cnt += right - left
            return cnt
        lo, hi = 0, nums[-1] - nums[0]
        while lo < hi:
            mid = (lo + hi) // 2
            if count_pairs(mid) >= k:
                hi = mid
            else:
                lo = mid + 1
        return lo
