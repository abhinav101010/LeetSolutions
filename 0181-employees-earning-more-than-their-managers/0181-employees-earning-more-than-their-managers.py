from typing import List
from dataclasses import dataclass

@dataclass
class Employee:
    id: int
    name: str
    salary: int
    managerId: int  # None if no manager

class Solution:
    def findEmployees(self, employees: List[Employee]) -> List[str]:
        result = []
        for e in employees:
            if not e.managerId:
                continue
            for m in employees:
                if m.id == e.managerId:
                    if e.salary > m.salary:
                        result.append(e.name)
                    break
        return result
