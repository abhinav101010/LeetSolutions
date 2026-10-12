class Solution:
    def isHappy(self, n: int) -> bool:
        seen = set()

        while n != 1:
            if n in seen:
                return False
            seen.add(n)

            newN = 0
            for digit in str(n):
                newN += int(digit) ** 2

            n = newN
        return True