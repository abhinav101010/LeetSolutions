class Employee:
    def __init__(self, Id, Company, Salary):
        self.Id = Id
        self.Company = Company
        self.Salary = Salary

class Solution:
    def medianEmployeeSalary(self, employees):
        byComp = {}
        for e in employees:
            byComp.setdefault(e.Company, []).append(e)
        ans = []
        for comp, rows in byComp.items():
            n = len(rows)
            ascIdx = list(range(n))
            descIdx = list(range(n))
            ascIdx.sort(key=lambda i: (rows[i].Salary, i))
            descIdx.sort(key=lambda i: (-rows[i].Salary, i))
            rnAsc = [0]*n
            rnDesc = [0]*n
            for i in range(n):
                rnAsc[ascIdx[i]] = i + 1
                rnDesc[descIdx[i]] = i + 1
            for i in range(n):
                ra = rnAsc[i]
                rd = rnDesc[i]
                if ra == rd or ra == rd - 1 or ra == rd + 1:
                    ans.append([str(rows[i].Id), str(comp), str(rows[i].Salary)])
        ans.sort(key=lambda r: (int(r[1]), int(r[0])))
        return ans
