from typing import List


class Project:
    def __init__(self, project_id: int, employee_id: int):
        self.project_id = project_id
        self.employee_id = employee_id


class Employee:
    def __init__(self, employee_id: int, name: str, experience_years: int):
        self.employee_id = employee_id
        self.name = name
        self.experience_years = experience_years


class Solution:
    def projectEmployees(self, projects: List[Project], employees: List[Employee]) -> List[List[str]]:
        empExp = {e.employee_id: e.experience_years for e in employees}
        proj = {}
        for p in projects:
            ex = empExp.get(p.employee_id)
            if ex is None:
                continue
            if p.project_id not in proj:
                proj[p.project_id] = [0, 0]
            proj[p.project_id][0] += ex
            proj[p.project_id][1] += 1
        result = []
        for pid in sorted(proj):
            avg = proj[pid][0] / proj[pid][1]
            result.append([str(pid), f"{avg:.2f}"])
        return result
