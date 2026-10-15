class Solution:
    def diStringMatch(self, s: str) -> list[int]:
        lo, hi = 0, len(s)
        res = []
        for ch in s:
            if ch == 'I':
                res.append(lo)
                lo += 1
            else:
                res.append(hi)
                hi -= 1
        res.append(lo)  # lo == hi
        return res
