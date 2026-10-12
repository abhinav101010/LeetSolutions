class Solution:
    def myAtoi(self, s: str) -> int:
        i = 0
        n = len(s)

        while i < n and s[i] == ' ':
            i += 1

        sign = 1
        if i < n and (s[i] == '+' or s[i] == '-'):
            if s[i] == '-':
                sign = -1
            i += 1

        ans = 0
        while i < n and '0' <= s[i] <= '9':
            ans = ans * 10 + int(s[i])
            i += 1

            if ans > 2**31 - 1:
                return 2**31 - 1 if sign == 1 else -2**31

        return sign * ans
