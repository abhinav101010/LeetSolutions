from typing import List

class Solution:
    def splitArray(self, nums: List[int], k: int) -> int:
        left, right = max(nums), sum(nums)
        
        while left < right:
            mid = (left + right) // 2
            count = 1
            curr_sum = 0
            for num in nums:
                if curr_sum + num > mid:
                    count += 1
                    curr_sum = num
                else:
                    curr_sum += num
            if count <= k:
                right = mid
            else:
                left = mid + 1
        
        return left