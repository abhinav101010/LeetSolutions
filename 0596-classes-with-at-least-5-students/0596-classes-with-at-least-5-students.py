class Course:
    def __init__(self, student, className):
        self.student = student
        self.className = className

class Solution:
    def findClasses(self, courses):
        cnt = {}
        for c in courses:
            cnt[c.className] = cnt.get(c.className, 0) + 1
        res = [k for k, v in cnt.items() if v >= 5]
        res.sort()
        return res
