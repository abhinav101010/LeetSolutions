class Solution:
    def maxCoins(self, piles) :
        piles.sort()
        return sum(piles[len(piles) // 3 :][::2])
