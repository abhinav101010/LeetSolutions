class Solution:
    def largestPalindrome(self, n: int) -> int:
        if n == 1:
            return 9
        upper = 10 ** n - 1
        lower = 10 ** (n - 1)
        for i in range(upper, lower - 1, -1):
            pal = int(str(i) + str(i)[::-1])
            for j in range(upper, int(pal ** 0.5) - 1, -1):
                if pal % j == 0 and lower <= pal // j <= upper:
                    return pal % 1337
        return 0