class Solution:
    def largestRectangleArea(self, heights: list[int]) -> int:
        stack = []  # (index, height)
        max_area = 0
        
        for i, h in enumerate(heights):
            start = i
            while stack and stack[-1][1] > h:
                idx, height = stack.pop()
                area = height * (i - idx)
                max_area = max(max_area, area)
                start = idx
            stack.append((start, h))
        
        n = len(heights)
        for idx, height in stack:
            area = height * (n - idx)
            max_area = max(max_area, area)
        
        return max_area