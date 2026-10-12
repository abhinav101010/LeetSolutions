class Solution:
    def sumAndMultiply(self, n: int) -> int:
        if n == 0: return 0
        s = 0
        x = ""
        for c in str(n):
            if c != "0":
                s+=int(c)
                x+=c
        return int(x)*s