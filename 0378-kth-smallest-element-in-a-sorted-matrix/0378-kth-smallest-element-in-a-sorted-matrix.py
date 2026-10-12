import heapq
from typing import List

class Solution:
    def kthSmallest(self, matrix: List[List[int]], k: int) -> int:
        n = len(matrix)
        heap = []
        
        for i in range(min(k, n)):
            heapq.heappush(heap, (matrix[i][0], i, 0))
        
        result = 0
        for _ in range(k):
            val, row, col = heapq.heappop(heap)
            result = val
            if col + 1 < n:
                heapq.heappush(heap, (matrix[row][col + 1], row, col + 1))
        
        return result