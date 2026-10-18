class Solution:
    def getNthHighestSalary(self, employees, N):
        distinct = sorted({e['salary'] for e in employees}, reverse=True)
        if N < 1 or N > len(distinct):
            return None
        return distinct[N-1]
