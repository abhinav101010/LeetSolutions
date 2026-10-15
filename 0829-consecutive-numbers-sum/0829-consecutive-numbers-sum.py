class Solution:
    def consecutiveNumbersSum(self, n: int) -> int:
        count = 0
        i = 1
        while i * i <= n:
            if n % i == 0:
                if i % 2 == 1:
                    count += 1
                j = n // i
                if j != i and j % 2 == 1:
                    count += 1
            i += 1
        return count
