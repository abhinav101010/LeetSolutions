class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        # if len(intervals) == 1: return intervals
        # intervals.sort()
        # ans  = []
        # for i in range(1, len(intervals)):
        #     if intervals[i-1][1] >= intervals[i][0]:
        #         ans.append([intervals[i-1][0], intervals[i][1]])
        #     else: 
        #         ans.append(intervals[i-1])
        # return ans


        # if len(intervals) == 1: return intervals
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