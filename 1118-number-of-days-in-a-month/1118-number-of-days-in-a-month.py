class Solution:
    def numberOfDays(self, Y, M):
        import calendar
        return calendar.monthrange(Y,M)[1]
