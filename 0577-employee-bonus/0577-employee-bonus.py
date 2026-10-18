from typing import List
from dataclasses import dataclass

@dataclass
class Employee:
    empId: int
    name: str
    supervisor: int
    salary: int

@dataclass
class Bonus:
    empId: int
    bonus: int

class Solution:
    def employeeBonus(self, employees: List[Employee], bonusList: List[Bonus]) -> List[List]:
        result = []
        bonus_map = {b.empId: b.bonus for b in bonusList}
        for e in employees:
            b = bonus_map.get(e.empId)
            if b is None or b < 1000:
                result.append([e.name, b if b is not None else None])
        return result
