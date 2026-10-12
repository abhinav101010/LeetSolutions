class Solution:
    def isPalindrome(self, x: int) -> bool:
        # if x < 0: return False
        # temp = x
        # result = 0
        # while temp > 0:
        #     result = result*10 + temp%10
        #     temp //= 10
        # if result == x:
        #     return True
        # else: 
        #     return False

        return str(x) == str(x)[::-1]
        
        