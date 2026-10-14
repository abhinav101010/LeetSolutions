from typing import List

# Employee info
class Employee:
    def __init__(self, id: int, importance: int, subordinates: List[int]):
        self.id = id
        self.importance = importance
        self.subordinates = subordinates

class Solution:
    def getImportance(self, employees: List['Employee'], id: int) -> int:
        emap = {e.id: e for e in employees}
        total = 0
        stack = [id]
        while stack:
            eid = stack.pop()
            emp = emap[eid]
            total += emp.importance
            stack.extend(emp.subordinates)
        return total
