class Solution:
    def bestRotation(self, nums: list[int]) -> int:
        n = len(nums)
        change = [0] * (n + 1)
        for i, val in enumerate(nums):
            # rotation where this element stops contributing
            left = (i + 1) % n
            right = (i - val + n + 1) % n
            change[left] += 1
            change[right] -= 1
            if left > right:
                change[0] += 1
        best = 0
        max_score = -1
        cur = 0
        for k in range(n):
            cur += change[k]
            if cur > max_score:
                max_score = cur
                best = k
        return best
