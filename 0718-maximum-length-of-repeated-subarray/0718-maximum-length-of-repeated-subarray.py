from typing import List

class Solution:
    def findLength(self, nums1: List[int], nums2: List[int]) -> int:
        n, m = len(nums1), len(nums2)
        dp = [0] * (m + 1)
        ans = 0
        for i in range(n):
            # iterate backwards to avoid overwriting
            for j in range(m - 1, -1, -1):
                if nums1[i] == nums2[j]:
                    dp[j + 1] = dp[j] + 1
                    ans = max(ans, dp[j + 1])
                else:
                    dp[j + 1] = 0
        return ans
