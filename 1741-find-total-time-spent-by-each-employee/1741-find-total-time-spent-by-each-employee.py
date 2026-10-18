class Employee:
    def __init__(self, empId, eventDay, inTime, outTime):
        self.empId = empId
        self.eventDay = eventDay
        self.inTime = inTime
        self.outTime = outTime

class Solution:
    def findTotalTimeSpentByEachEmployee(self, employees):
        total = {}
        for e in employees:
            key = (e.eventDay, e.empId)
            total[key] = total.get(key, 0) + (e.outTime - e.inTime)
        res = []
        for (day, empId), t in sorted(total.items()):
            res.append([day, str(empId), str(t)])
        return res
