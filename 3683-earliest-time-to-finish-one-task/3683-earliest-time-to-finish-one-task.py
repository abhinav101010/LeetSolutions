class Solution:
    def earliestTime(self, tasks) -> int:
        return min(s + t for s, t in tasks)
