class Solution:
    def convertToBase7(self, num: int) -> str:
        if num == 0: return "0"

        sign = ""
        if num < 0:
            sign = "-"
            num = abs(num)

        ans = ""
        while num > 0:
            remainder = num % 7
            ans = str(remainder) + ans
            num //= 7

        return sign + ans