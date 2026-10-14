from typing import List

# Definition for an Interval.
class Interval:
    def __init__(self, start: int = None, end: int = None):
        self.start = start
        self.end = end

class Solution:
    def employeeFreeTime(self, schedule: List[List['Interval']]) -> List['Interval']:
        intervals = []
        for emp in schedule:
            for iv in emp:
                intervals.append((iv.start, iv.end))
        if not intervals:
            return []
        intervals.sort(key=lambda x: x[0])
        merged = []
        cur_start, cur_end = intervals[0]
        for s, e in intervals[1:]:
            if s <= cur_end:
                cur_end = max(cur_end, e)
            else:
                merged.append((cur_start, cur_end))
                cur_start, cur_end = s, e
        merged.append((cur_start, cur_end))
        # compute gaps
        free = []
        for i in range(1, len(merged)):
            prev_end = merged[i-1][1]
            curr_start = merged[i][0]
            if prev_end < curr_start:
                free.append(Interval(prev_end, curr_start))
        return free
