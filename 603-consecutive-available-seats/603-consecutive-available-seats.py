class Cinema:
    def __init__(self, seat_id, free):
        self.seat_id = seat_id
        self.free = free

class Solution:
    def consecutiveAvailableSeats(self, cinema):
        freeSet = set()
        for c in cinema:
            if c.free == 1:
                freeSet.add(c.seat_id)
        seats = sorted(freeSet)
        ans = []
        for sid in seats:
            if (sid - 1) in freeSet or (sid + 1) in freeSet:
                ans.append([str(sid)])
        return ans
