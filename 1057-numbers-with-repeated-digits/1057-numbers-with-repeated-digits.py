import math
class Solution:
    def numDupDigitsAtMostN(self, n):
        s = str(n)
        length = len(s)
        ans = 0
        for i in range(1, length):
            ans += 9 * math.perm(9, i-1)
        used = set()
        for i, c in enumerate(s):
            for d in range(int(c)):
                if d == 0 and i == 0: continue
                if d in used: continue
                ans += math.perm(9 - i, length - 1 - i)
            if int(c) in used: break
            used.add(int(c))
        if len(used) == length: ans += 1
        return n - ans
