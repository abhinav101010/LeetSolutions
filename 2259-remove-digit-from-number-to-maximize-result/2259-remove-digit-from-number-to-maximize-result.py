class Solution:
    def removeDigit(self, number, digit):
        return max(
            number[:i] + number[i + 1 :] for i, d in enumerate(number) if d == digit
        )
