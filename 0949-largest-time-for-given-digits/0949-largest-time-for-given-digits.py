from itertools import permutations
class Solution:
    def largestTimeFromDigits(self, A: list[int]) -> str:
        ans = ""
        for h1, h2, m1, m2 in permutations(A):
            hour = h1*10 + h2
            minute = m1*10 + m2
            if hour < 24 and minute < 60:
                t = f"{hour:02d}:{minute:02d}"
                if t > ans:
                    ans = t
        return ans
