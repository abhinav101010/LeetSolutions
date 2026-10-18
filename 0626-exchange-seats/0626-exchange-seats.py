from typing import List
from dataclasses import dataclass

@dataclass
class Seat:
    id: int
    student: str

class Solution:
    def exchangeSeats(self, seats: List[Seat]) -> List[Seat]:
        n = len(seats)
        result = []
        for s in seats:
            if s.id % 2 == 1 and s.id != n:
                new_id = s.id + 1
            elif s.id % 2 == 0:
                new_id = s.id - 1
            else:
                new_id = s.id
            result.append((new_id, s.student))
        result.sort(key=lambda x: x[0])
        return [Seat(r[0], r[1]) for r in result]
