class Solution:
    def binaryGap(self, n: int) -> int:
        b = bin(n)[2:]
        start = b.find("1")
        if start == -1: return 0
        ans = 0
        for i in range(start + 1, len(b)):
            if b[i] == "1":
                ans = max(ans, i - start)
                start = i

        return ans