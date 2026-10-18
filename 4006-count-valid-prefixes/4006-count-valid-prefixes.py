class Solution:
    def countValidPrefixes(self, s):
        ans = t = 0
        for c in s:
            t += 1 if c == '1' else -1
            ans += 1 if abs(t) <= 1 else 0
        return ans
