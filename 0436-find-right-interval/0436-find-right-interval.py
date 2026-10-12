from typing import List
import bisect

class Solution:
    def findRightInterval(self, intervals: List[List[int]]) -> List[int]:
        sorted_starts = sorted((interval[0], i) for i, interval in enumerate(intervals))
        starts = [s for s, _ in sorted_starts]
        
        result = []
        for interval in intervals:
            idx = bisect.bisect_left(starts, interval[1])
            if idx < len(starts):
                result.append(sorted_starts[idx][1])
            else:
                result.append(-1)
        return result