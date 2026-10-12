from typing import List
import bisect

class Solution:
    def countRangeSum(self, nums: List[int], lower: int, upper: int) -> int:
        n = len(nums)
        prefix = [0] * (n + 1)
        for i in range(n):
            prefix[i + 1] = prefix[i] + nums[i]
        
        def merge_sort(arr):
            if len(arr) <= 1:
                return arr
            mid = len(arr) // 2
            left = merge_sort(arr[:mid])
            right = merge_sort(arr[mid:])
            
            # Count valid pairs
            j = k = 0
            for l_val in left:
                while j < len(right) and right[j] - l_val < lower:
                    j += 1
                while k < len(right) and right[k] - l_val <= upper:
                    k += 1
                self.count += k - j
            
            # Merge
            return sorted(left + right)
        
        self.count = 0
        merge_sort(prefix)
        return self.count