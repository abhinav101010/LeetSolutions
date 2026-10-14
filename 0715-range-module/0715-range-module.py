from bisect import bisect_left, bisect_right

class RangeModule:
    def __init__(self):
        self.intervals = []  # list of [start, end)

    def addRange(self, left: int, right: int) -> None:
        if not self.intervals:
            self.intervals.append([left, right])
            return
        # find index of first interval with end >= left
        i = bisect_left(self.intervals, left, key=lambda x: x[1])
        # find index of first interval with start > right
        j = bisect_right(self.intervals, right, key=lambda x: x[0])
        # if there is overlap, we may need to merge
        start = left
        end = right
        if i < len(self.intervals):
            start = min(start, self.intervals[i][0])
        if j > 0:
            end = max(end, self.intervals[j-1][1])
        # replace intervals[i:j] with [start, end]
        self.intervals[i:j] = [[start, end]]

    def queryRange(self, left: int, right: int) -> bool:
        # find the interval that could contain left
        i = bisect_right(self.intervals, left, key=lambda x: x[0]) - 1
        if i >= 0 and self.intervals[i][1] >= right:
            return True
        return False

    def removeRange(self, left: int, right: int) -> None:
        if not self.intervals:
            return
        i = bisect_left(self.intervals, left, key=lambda x: x[1])
        j = bisect_right(self.intervals, right, key=lambda x: x[0])
        start = left
        end = right
        # we will keep parts before left and after right
        new_intervals = []
        if i < len(self.intervals):
            # interval at i may start before left
            if self.intervals[i][0] < left:
                new_intervals.append([self.intervals[i][0], left])
            # interval at j-1 may end after right
            if j > 0 and self.intervals[j-1][1] > right:
                new_intervals.append([right, self.intervals[j-1][1]])
        # intervals before i and after j remain
        self.intervals = self.intervals[:i] + new_intervals + self.intervals[j:]
