from typing import List

class Solution:
    def intersectionSizeTwo(self, intervals: List[List[int]]) -> int:
        intervals.sort(key=lambda x: (x[1], x[0]))
        ans = 0
        first = -2  # largest selected
        second = -2 # second largest selected
        for a, b in intervals:
            if second >= a:
                continue
            if first >= a:
                ans += 1
                second = b
            else:
                ans += 2
                first = b - 1
                second = b
        return ans
