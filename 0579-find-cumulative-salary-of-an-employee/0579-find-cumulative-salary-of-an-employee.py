class Employee:
    def __init__(self, Id, Month, Salary):
        self.Id = Id
        self.Month = Month
        self.Salary = Salary

class Solution:
    def cumulativeSalary(self, employees):
        byId = {}
        for e in employees:
            byId.setdefault(e.Id, []).append(e)
        ans = []
        for id, rows in byId.items():
            rows.sort(key=lambda r: r.Month)
            maxMonth = rows[-1].Month
            n = len(rows)
            for i in range(n):
                s = rows[i].Salary
                if i - 1 >= 0:
                    s += rows[i - 1].Salary
                if i - 2 >= 0:
                    s += rows[i - 2].Salary
                if rows[i].Month == maxMonth:
                    s -= rows[i].Salary
                ans.append([str(id), str(rows[i].Month), str(s)])
        ans.sort(key=lambda r: (int(r[0]), int(r[1])))
        return ans
