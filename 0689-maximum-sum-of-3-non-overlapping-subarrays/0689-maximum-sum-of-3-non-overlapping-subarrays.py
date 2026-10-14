from typing import List

class Solution:
    def maxSumOfThreeSubarrays(self, nums: List[int], k: int) -> List[int]:
        n = len(nums)
        # window sums
        w = [0] * (n - k + 1)
        cur = sum(nums[:k])
        w[0] = cur
        for i in range(1, n - k + 1):
            cur += nums[i + k - 1] - nums[i - 1]
            w[i] = cur
        # left best index
        left = [0] * len(w)
        best = 0
        for i in range(len(w)):
            if w[i] > w[best]:
                best = i
            left[i] = best
        # right best index
        right = [0] * len(w)
        best = len(w) - 1
        for i in range(len(w)-1, -1, -1):
            if w[i] >= w[best]:  # >= to get smaller index for tie? Actually we want lexicographically smallest overall, so for right we want the smallest index when tie? In typical solution they use > for left and >= for right to get lexicographically smallest. We'll follow known solution.
                best = i
            right[i] = best
        # now try middle subarray
        max_sum = -1
        ans = []
        for j in range(k, len(w) - k):
            i = left[j - k]
            l = right[j + k]
            total = w[i] + w[j] + w[l]
            if total > max_sum:
                max_sum = total
                ans = [i, j, l]
        return ans
