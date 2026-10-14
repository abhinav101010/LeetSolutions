class MyCalendarTwo:
    def __init__(self):
        self.calendar = []  # list of (start, end)
        self.overlap = []   # list of (start, end) of overlaps between two events

    def book(self, start: int, end: int) -> bool:
        # check against overlap
        for s, e in self.overlap:
            if not (end <= s or start >= e):
                return False
        # find overlaps with calendar and add to overlap
        newOverlaps = []
        for s, e in self.calendar:
            if not (end <= s or start >= e):
                startOverlap = max(start, s)
                endOverlap = min(end, e)
                newOverlaps.append((startOverlap, endOverlap))
        # add new overlaps
        self.overlap.extend(newOverlaps)
        # add event to calendar
        self.calendar.append((start, end))
        return True
