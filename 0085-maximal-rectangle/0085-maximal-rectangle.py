from typing import List

class Solution:
    def maximalRectangle(self, matrix: List[List[str]]) -> int:
        if not matrix or not matrix[0]:
            return 0
        
        m, n = len(matrix), len(matrix[0])
        heights = [0] * n
        max_area = 0
        
        for i in range(m):
            for j in range(n):
                if matrix[i][j] == '1':
                    heights[j] += 1
                else:
                    heights[j] = 0
            
            # Largest rectangle in histogram
            stack = []
            for k, h in enumerate(heights):
                start = k
                while stack and stack[-1][1] > h:
                    idx, height = stack.pop()
                    area = height * (k - idx)
                    max_area = max(max_area, area)
                    start = idx
                stack.append((start, h))
            
            for idx, height in stack:
                area = height * (n - idx)
                max_area = max(max_area, area)
        
        return max_area