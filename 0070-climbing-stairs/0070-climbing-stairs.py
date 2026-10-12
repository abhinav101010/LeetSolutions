class Solution:
    def climbStairs(self, n: int) -> int:
        # ans = 0
        # def climb(n, curr):
        #     nonlocal ans
        #     if n == curr:
        #        ans+=1
        #        return

        #     climb(n, curr+1)
        #     if n-2 >= curr:
        #         climb(n, curr+2)
        # climb(n, 0)
        # return ans

# It is actually a fibonacci series, i didnt knew, the code written by me gives TLE
        if n <= 2 :
            return n
        a, b = 1, 2
        for _ in range(3, n+1):
            a, b = b, a+b
        return b