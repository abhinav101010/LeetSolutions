class Solution:
    def countSubstrings(self, s, c):
        cnt = s.count(c)
        return cnt + cnt * (cnt - 1) // 2
