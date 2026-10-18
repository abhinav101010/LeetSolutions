class Solution:
    def sortTheStudents(self, score, k):
        return sorted(score, key=lambda x: -x[k])
