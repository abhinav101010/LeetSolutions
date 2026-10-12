class Solution:
    def titleToNumber(self, columnTitle: str) -> int:
        ans = 0

        incPow = 0
        for c in columnTitle[::-1]:
            value = ord(c) - ord('A') + 1
            ans += value * (26 ** incPow)
            incPow += 1
        return ans