class Solution:
    def distributeCandies(self, candyType: List[int]) -> int:
        n = len(candyType)
        uniqueCandies = len(set(candyType))
        return uniqueCandies if uniqueCandies <= n//2 else n//2