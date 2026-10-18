class Salary:
    def __init__(self, id, name, sex, salary):
        self.id = id
        self.name = name
        self.sex = sex
        self.salary = salary

class Solution:
    def swapSex(self, salaries):
        ans = []
        for s in salaries:
            sex = s.sex
            if sex == "m":
                sex = "f"
            elif sex == "f":
                sex = "m"
            ans.append([str(s.id), s.name, sex, str(s.salary)])
        ans.sort(key=lambda r: int(r[0]))
        return ans
