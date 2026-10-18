from typing import List
from collections import defaultdict

class Employee:
    def __init__(self, id: int, name: str, managerId: int):
        self.id = id
        self.name = name
        self.managerId = managerId

class Solution:
    def findManagers(self, employees: List[Employee]) -> List[str]:
        manager_count = defaultdict(int)
        name_map = {}
        for e in employees:
            name_map[e.id] = e.name
            if e.managerId >= 0:
                manager_count[e.managerId] += 1
        result = []
        for manager_id, count in manager_count.items():
            if count >= 5:
                result.append(name_map[manager_id])
        result.sort()
        return result
