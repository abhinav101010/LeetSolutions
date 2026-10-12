class Solution:
    def repeatedStringMatch(self, a: str, b: str) -> int:
        if a == b: return 1
        s = a
        count = 1
        while len(s) < len(b):
            s += a
            count += 1
        if b in s: return count
        s += a
        count += 1
        if b in s: return count
        return -1