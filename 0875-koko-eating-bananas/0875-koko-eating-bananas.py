class Solution:
    def minEatingSpeed(self, piles: list[int], h: int) -> int:
        def can(speed):
            hours = 0
            for p in piles:
                hours += (p + speed - 1) // speed
                if hours > h:
                    return False
            return hours <= h
        lo, hi = 1, max(piles)
        while lo < hi:
            mid = (lo + hi) // 2
            if can(mid):
                hi = mid
            else:
                lo = mid + 1
        return lo
