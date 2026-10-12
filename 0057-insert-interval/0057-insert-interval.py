class Solution:
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
        intervals.append(newInterval)
        intervals.sort()
        ans  = [intervals[0]]
        i = 1
        while i < len(intervals):
            if ans[-1][1] >= intervals[i][0]:
                ans[-1][1] = max(ans[-1][1], intervals[i][1])
            elif ans[-1][1] <= intervals[i][0]:
                ans.append(intervals[i])
            i+=1
        return ans