class Solution:
    def shiftingLetters(self, s: str, shifts: list[int]) -> str:
        n = len(s)
        total = 0
        res = []
        for i in range(n-1, -1, -1):
            total += shifts[i]
            offset = (ord(s[i]) - ord('a') + total) % 26
            res.append(chr(ord('a') + offset))
        res.reverse()
        return ''.join(res)
