class Solution:
    def countPrimeSetBits(self, left: int, right: int) -> int:
        ans = 0

        for i in range(left, right + 1):
            oneBits = 0

            for c in bin(i)[2:]:
                if c == "1":
                    oneBits += 1

            if oneBits < 2:
                continue

            isPrime = True
            for j in range(2, oneBits):
                if oneBits % j == 0:
                    isPrime = False
                    break

            if isPrime:
                ans += 1

        return ans