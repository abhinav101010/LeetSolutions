@cache
def f(x) :
    if x < 2:
        return 1
    return x * f(x - 1)


class Solution:
    def isDigitorialPermutation(self, n) :
        x, y = 0, n
        while y:
            x += f(y % 10)
            y //= 10
        return sorted(str(x)) == sorted(str(n))
