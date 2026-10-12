class Solution:
    def hasAlternatingBits(self, n: int) -> bool:
        b = bin(n)[2:]
        prev = ""
        for i in range(len(b)):
            if prev == b[i]: return False
            prev = b[i]
        return True