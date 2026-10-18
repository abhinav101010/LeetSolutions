class Solution:
    def maximumCostSubstring(self, s, chars, vals):
        d = {c: v for c, v in zip(chars, vals)}
        ans = tot = mi = 0
        for c in s:
            v = d.get(c, ord(c) - ord('a') + 1)
            tot += v
            ans = max(ans, tot - mi)
            mi = min(mi, tot)
        return ans
