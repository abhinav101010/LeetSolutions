from typing import List
import bisect

class Solution:
    def maxSumSubmatrix(self, matrix: List[List[int]], k: int) -> int:
        m, n = len(matrix), len(matrix[0])
        max_sum = float('-inf')
        
        for left in range(n):
            row_sums = [0] * m
            for right in range(left, n):
                for i in range(m):
                    row_sums[i] += matrix[i][right]
                
                # Find max subarray sum <= k
                prefix = 0
                sorted_prefix = [0]
                for s in row_sums:
                    prefix += s
                    idx = bisect.bisect_left(sorted_prefix, prefix - k)
                    if idx < len(sorted_prefix):
                        max_sum = max(max_sum, prefix - sorted_prefix[idx])
                    bisect.insort(sorted_prefix, prefix)
        
        return max_sum