class Solution:
    def arrangeCoins(self, n: int) -> int:
        ans = 0
        for i in range(1,n+1):
            if n >= i:
                n-=i
                ans+=1
                continue
            break
        return ans