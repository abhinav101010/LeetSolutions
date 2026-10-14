class MyCalendar:
    def __init__(self):
        self.intervals = []  # list of (start, end)

    def book(self, start: int, end: int) -> bool:
        for s, e in self.intervals:
            if not (end <= s or start >= e):
                return False
        self.intervals.append((start, end))
        return True
