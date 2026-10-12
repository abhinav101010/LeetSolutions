class Solution:
    def checkZeroOnes(self, s: str) -> bool:
        max_ones = max_zeros = 0
        ones = zeros = 0

        for ch in s:
            if ch == '1':
                ones += 1
                zeros = 0
                max_ones = max(max_ones, ones)
            else:
                zeros += 1
                ones = 0
                max_zeros = max(max_zeros, zeros)

        return max_ones > max_zeros