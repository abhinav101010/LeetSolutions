from typing import List, Optional


class Employee:
    def __init__(self, employee_id: int, name: str, reports_to: Optional[int], age: int):
        self.employee_id = employee_id
        self.name = name
        self.reports_to = reports_to
        self.age = age


class Report:
    def __init__(self, employee_id: int, name: str, reports_count: int, average_age: int):
        self.employee_id = employee_id
        self.name = name
        self.reports_count = reports_count
        self.average_age = average_age


class Solution:
    def countEmployees(self, employees: List[Employee]) -> List[Report]:
        cnt = {}
        sumAge = {}
        for e in employees:
            if e.reports_to is not None:
                m = e.reports_to
                cnt[m] = cnt.get(m, 0) + 1
                sumAge[m] = sumAge.get(m, 0) + e.age
        ans = []
        for e in employees:
            c = cnt.get(e.employee_id)
            if c is not None and c >= 1:
                avg = round(sumAge[e.employee_id] / c)
                ans.append(Report(e.employee_id, e.name, c, avg))
        ans.sort(key=lambda r: r.employee_id)
        return ans
