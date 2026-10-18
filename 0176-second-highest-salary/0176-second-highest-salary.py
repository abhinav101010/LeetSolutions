from typing import List


class Employee:
    def __init__(self, id: int, salary: int):
        self.id = id
        self.salary = salary


class Solution:
    def secondHighestSalary(self, employees: List[Employee]) -> List[List[str]]:
        distinct = sorted({e.salary for e in employees}, reverse=True)
        if len(distinct) < 2:
            return [["NULL"]]
        return [[str(distinct[1])]]
