class Solution:
    def trailingZeroes(self, n: int) -> int:
        # fact = 1
        # for i in range(1,n+1):
        #     fact*=i
        
        # return len(str(fact)) - len(str(int(str(fact)[::-1])))

        # fact = "1"
        # for i in range(1,n+1):
        #     fact = str(int(fact) * i)
        
        # return len(fact) - len(str(int(fact[::-1])))

        ans = 0
        while n:
            n//=5
            ans+=n
        return ans