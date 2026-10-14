from typing import List

class Solution:
    def pourWater(self, heights: List[int], volume: int, k: int) -> List[int]:
        n = len(heights)
        for _ in range(volume):
            # try left
            i = k
            while i > 0 and heights[i-1] <= heights[i]:
                i -= 1
            if i < k and heights[i] < heights[k]:
                heights[i] += 1
                continue
            # try right
            i = k
            while i < n-1 and heights[i+1] <= heights[i]:
                i += 1
            if i > k and heights[i] < heights[k]:
                heights[i] += 1
                continue
            # stay
            heights[k] += 1
        return heights
