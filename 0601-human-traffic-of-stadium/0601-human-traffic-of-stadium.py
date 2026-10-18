from typing import List
from dataclasses import dataclass

@dataclass
class Stadium:
    id: int
    visit_date: str
    people: int

class Solution:
    def humanTraffic(self, stadium: List[Stadium]) -> List[Stadium]:
        n = len(stadium)
        mark = [False] * n
        for i in range(n - 2):
            if (stadium[i].people >= 100 and 
                stadium[i+1].people >= 100 and 
                stadium[i+2].people >= 100 and
                stadium[i+1].id == stadium[i].id + 1 and 
                stadium[i+2].id == stadium[i+1].id + 1):
                mark[i] = mark[i+1] = mark[i+2] = True
        return [stadium[i] for i in range(n) if mark[i]]
