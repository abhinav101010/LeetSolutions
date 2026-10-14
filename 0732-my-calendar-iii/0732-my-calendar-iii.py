class MyCalendarThree:
    def __init__(self):
        self.delta = {}  # time -> change in count

    def book(self, start: int, end: int) -> int:
        self.delta[start] = self.delta.get(start, 0) + 1
        self.delta[end] = self.delta.get(end, 0) - 1
        # compute prefix sum max
        ongoing = 0
        max_ongoing = 0
        for time in sorted(self.delta.keys()):
            ongoing += self.delta[time]
            if ongoing > max_ongoing:
                max_ongoing = ongoing
        return max_ongoing
