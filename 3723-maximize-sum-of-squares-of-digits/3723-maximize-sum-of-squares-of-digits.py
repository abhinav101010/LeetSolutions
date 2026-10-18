class Solution:
    def maxSumOfSquares(self, num, sum):
        if num * 9 < sum:
            return ""
        k, s = divmod(sum, 9)
        ans = "9" * k
        if s:
            ans += str(s)
        ans += "0" * (num - len(ans))
        return ans
