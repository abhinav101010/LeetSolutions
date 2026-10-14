class Solution:
    def monotoneIncreasingDigits(self, N: int) -> int:
        s = list(str(N))
        n = len(s)
        i = 1
        while i < n and s[i-1] <= s[i]:
            i += 1
        if i < n:
            while i > 0 and s[i-1] > s[i]:
                i -= 1
            s[i] = chr(ord(s[i]) - 1)
            for j in range(i+1, n):
                s[j] = '9'
        return int(''.join(s))
