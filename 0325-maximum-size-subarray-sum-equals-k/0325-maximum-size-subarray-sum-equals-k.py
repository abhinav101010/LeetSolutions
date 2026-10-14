from typing import List

class Solution:
    def maxSubArrayLen(self, nums: List[int], k: int) -> int:
        prefix_sum = 0
        sum_to_index = {0: -1}
        max_len = 0
        for i, num in enumerate(nums):
            prefix_sum += num
            if prefix_sum - k in sum_to_index:
                max_len = max(max_len, i - sum_to_index[prefix_sum - k])
            if prefix_sum not in sum_to_index:
                sum_to_index[prefix_sum] = i
        return max_len
