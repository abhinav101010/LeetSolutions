class Solution:
    def secondsBetweenTimes(self, startTime, endTime):
        def f(s):
            return int(s[:2]) * 3600 + int(s[3:5]) * 60 + int(s[6:])

        return f(endTime) - f(startTime)
