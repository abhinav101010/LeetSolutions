class Solution:
    def numberOfEmployeesWhoMetTarget(self, hours, target):
        return sum(x >= target for x in hours)