class Solution:
    def canWinNim(self, n: int) -> bool:
# Self thought logic but........
        # memo = {}
        # ans = False
        # def recurr(n, turn):
        #     nonlocal ans
        #     if n == 0: 
        #         if turn: ans = True
        #         return turn

        #     if not ans:
        #         recurr(n-1, not turn)
        #         if n>=2: recurr(n-2, not turn)
        #         if n>=3: recurr(n-3, not turn)

        # recurr(n, False)
        # return ans

# WtFffFFFFF....
        return n % 4 != 0