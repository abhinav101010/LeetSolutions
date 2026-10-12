class Solution:
    def findKthNumber(self, m: int, n: int, k: int) -> int:
        def count(mid):
            return sum(min(mid // i, n) for i in range(1, m + 1))
        
        left, right = 1, m * n
        while left < right:
            mid = (left + right) // 2
            if count(mid) >= k:
                right = mid
            else:
                left = mid + 1
        return left