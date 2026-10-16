class Solution:
    def shipWithinDays(self, weights, D):
        left = max(weights)
        right = sum(weights)
        while left < right:
            mid = (left + right) // 2
            days = 1
            cur = 0
            for w in weights:
                if cur + w > mid:
                    days += 1
                    cur = 0
                cur += w
            if days <= D:
                right = mid
            else:
                left = mid + 1
        return left
