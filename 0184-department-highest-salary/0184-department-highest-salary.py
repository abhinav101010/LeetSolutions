class Employee:
    def __init__(self, id, name, salary, departmentId):
        self.id = id
        self.name = name
        self.salary = salary
        self.departmentId = departmentId

class Department:
    def __init__(self, id, name):
        self.id = id
        self.name = name

class Solution:
    def departmentHighestSalary(self, employees, departments):
        deptName = {}
        for d in departments:
            deptName[d.id] = d.name
        maxSal = {}
        for e in employees:
            if e.departmentId not in maxSal or e.salary > maxSal[e.departmentId]:
                maxSal[e.departmentId] = e.salary
        res = []
        for e in employees:
            if e.departmentId not in deptName:
                continue
            if maxSal.get(e.departmentId) == e.salary:
                res.append([deptName[e.departmentId], e.name, str(e.salary)])
        return res
