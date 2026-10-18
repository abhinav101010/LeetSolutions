class Solution:
    def maximumOddBinaryNumber(self, s) -> str:
        cnt = s.count("1")
        return "1" * (cnt - 1) + (len(s) - cnt) * "0" + "1"
