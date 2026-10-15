class Solution:
    def minFlipsMonoIncr(self, s: str) -> int:
        ones = 0
        ans = 0
        for ch in s:
            if ch == '1':
                ones += 1
            else:
                ans = min(ans + 1, ones)
        return ans
