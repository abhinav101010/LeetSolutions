import heapq

class SummaryRanges:
    def __init__(self):
        self.intervals = []
    
    def addNum(self, value: int) -> None:
        # Find position to insert
        left, right = 0, len(self.intervals)
        while left < right:
            mid = (left + right) // 2
            if self.intervals[mid][0] < value:
                left = mid + 1
            else:
                right = mid
        
        # Check if can merge with left
        if left > 0 and self.intervals[left - 1][1] + 1 >= value:
            left -= 1
        
        # Merge overlapping intervals
        new_start = value
        new_end = value
        while left < len(self.intervals) and self.intervals[left][0] <= new_end + 1:
            new_start = min(new_start, self.intervals[left][0])
            new_end = max(new_end, self.intervals[left][1])
            self.intervals.pop(left)
        
        self.intervals.insert(left, [new_start, new_end])
    
    def getIntervals(self) -> List[List[int]]:
        return self.intervals