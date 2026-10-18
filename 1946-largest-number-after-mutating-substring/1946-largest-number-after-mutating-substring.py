class Solution:
    def maximumNumber(self, num, change) :
        s = list(num)
        changed = False
        for i, c in enumerate(s):
            d = str(change[int(c)])
            if changed and d < c:
                break
            if d > c:
                changed = True
                s[i] = d
        return "".join(s)
