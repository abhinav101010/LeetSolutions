from typing import List
from dataclasses import dataclass
from collections import defaultdict

@dataclass
class Department:
    id: int
    revenue: int
    month: str

class Solution:
    def reformatTable(self, department: List[Department]) -> List[List]:
        months = ["Jan", "Feb", "Mar", "Apr", "May", "Jun", 
                  "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"]
        d = defaultdict(list)
        for dep in department:
            d[dep.id].append((dep.month, dep.revenue))
        res = []
        for id_, items in d.items():
            rev = {m: r for m, r in items}
            row = [id_]
            for m in months:
                row.append(rev.get(m))
            res.append(row)
        res.sort(key=lambda x: x[0])
        return res
