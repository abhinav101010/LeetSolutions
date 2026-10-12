import heapq
from typing import List

class Solution:
    def smallestRange(self, nums: List[List[int]]) -> List[int]:
        k = len(nums)
        pq = [(row[0], i, 0) for i, row in enumerate(nums)]
        heapq.heapify(pq)
        
        max_val = max(row[0] for row in nums)
        ans = [pq[0][0], max_val]
        
        while pq:
            min_val, row_idx, col_idx = heapq.heappop(pq)
            if col_idx + 1 == len(nums[row_idx]):
                break
            next_val = nums[row_idx][col_idx + 1]
            heapq.heappush(pq, (next_val, row_idx, col_idx + 1))
            max_val = max(max_val, next_val)
            if max_val - pq[0][0] < ans[1] - ans[0]:
                ans = [pq[0][0], max_val]
        
        return ans