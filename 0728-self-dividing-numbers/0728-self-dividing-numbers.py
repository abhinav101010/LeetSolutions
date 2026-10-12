class Solution:
    def selfDividingNumbers(self, left: int, right: int) -> List[int]:
        ans = []
        for num in range(left, right+1):
            divisible = True
            for c in str(num):
                digit = int(c)
                if digit == 0 or num%digit != 0:
                    divisible=False
            if divisible:
                ans.append(num)
        return ans
