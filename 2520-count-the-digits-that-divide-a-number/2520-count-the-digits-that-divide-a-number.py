class Solution:
    def countDigits(self, num: int) -> int:
        ans = 0
        for c in str(num):
            ans += 1 if num%int(c)==0 else 0
        return ans