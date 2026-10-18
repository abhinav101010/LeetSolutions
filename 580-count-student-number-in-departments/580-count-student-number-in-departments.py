from collections import defaultdict

class Department:
    def __init__(self, id, name):
        self.id = id
        self.name = name

class Student:
    def __init__(self, id, name, department_id):
        self.id = id
        self.name = name
        self.department_id = department_id

class Solution:
    def countStudents(self, departments, students):
        cnt = defaultdict(int)
        for s in students:
            cnt[s.department_id] += 1
        res = []
        for d in departments:
            res.append((d.name, cnt[d.id]))
        res.sort(key=lambda x: (-x[1], x[0]))
        return res
