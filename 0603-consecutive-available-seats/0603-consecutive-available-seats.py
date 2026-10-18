from typing import List


class Seat:
    def __init__(self, id: int, free: bool):
        self.id = id
        self.free = free


class Solution:
    def consecutiveAvailableSeats(self, seats: List[Seat]) -> List[int]:
        freeIds = set(s.id for s in seats if s.free)
        ans = [s.id for s in seats if s.free and (s.id - 1 in freeIds or s.id + 1 in freeIds)]
        ans.sort()
        return ans
